#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "UIConstants.h"

#include "ball.h"
#include "SceneManager.h"

#include "Cannon.h"
#include "CannonReader.h"
#include "DogiReader.h"
#include "Dogi.h"

#include "JSONPacker.h"
#include "Coin.h"

#include "PassCode.h"

#include "LevelClear.h"
#include "levelClearReader.h"

USING_NS_CC;


//TODO: make Debug func for game over and map test

#pragma mark -
#pragma mark LifeCircle

GameScene* GameScene::createWithLevel(int level)
{
    GameScene* gameScene = new (std::nothrow) GameScene();
    if (gameScene && gameScene->initWithLevel(level)) {
        gameScene->autorelease();
        return gameScene;
    } else {
        CC_SAFE_DELETE(gameScene);
        return nullptr;
    }
}

bool GameScene::initWithLevel(int level)
{
    if (! Node::init()) {
        return false;
    }
    _level = level;
    _edgeSp = nullptr;
    _currentScore = 0;
    
    return true;
}

void GameScene::onEnter()
{
    Node::onEnter();
    
    setupMap();
   
    setupBall();

    //TODO: use level loadler to load the all node of game scene
    //code below this should be move to level loader
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    setupTouchHandling();
    this->scheduleUpdate();
}


void GameScene::setupMap()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();

    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CannonReader" , (ObjectFactory::Instance) CannonReader::getInstance);
    instance->registReaderObject("DogiReader" , (ObjectFactory::Instance) DogiReader::getInstance);
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    _cannon = rootNode->getChildByName<Cannon*>("Cannon");
    _dogi = rootNode->getChildByName<Dogi*>("Dogi");

    _mainScene = rootNode;
    
    std::string jsonStr = FileUtils::getInstance()->getStringFromFile(getConfigFileName());
    JSONPacker::MapState mapState = JSONPacker::unpackMapStateJSON(jsonStr);
    
    //setup balls in stage
    for (auto ballconfig : mapState.ballsOnStage)
    {
        Ball* ball = Ball::createWithBallConfig(ballconfig);
        _mainScene->addChild(ball);
        this->_ballsOnState.pushBack(ball);
    }
    
    //setup balls in bags
    for (auto ballconfig : mapState.ballsInBag) {
        Ball* ball = Ball::createWithBallConfig(ballconfig);
        this->_ballsInBag.pushBack(ball);
    }
    
    _oneStarScore = mapState.starConfig.oneStar;
    _twoStarScore = mapState.starConfig.twoStar;
    _threeStarScore = mapState.starConfig.threeStar;
    
    //Setup Edge
    float bottomHeight = rootNode->getChildByName<Sprite*>("BottomBound")->getContentSize().height;
    float upperHeight = rootNode->getChildByName<Sprite*>("UpperBound")->getContentSize().height;
    float edgeHeight = visibleSize.height - bottomHeight - upperHeight;
    
    float sideWidth = rootNode->getChildByName<Sprite*>("SideBarShadowLeft")->getChildByName<Sprite*>("SideBarLeft")->getContentSize().width /2;
    float edgeWidth = visibleSize.width - 2 * sideWidth;
    
    auto edgeBody = PhysicsBody::createEdgeBox(Size(edgeWidth, edgeHeight), EDGE_MATERIAL);
    
    edgeBody->setContactTestBitmask(EDGE_INIT_CONTACT_MASK);
    edgeBody->setCollisionBitmask(EDGE_INIT_CULLISION_MASK);
    edgeBody->setCategoryBitmask(EDGE_CATEGORY);
    
    _edgeSp = Sprite::create();
    _edgeSp->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2 + (bottomHeight - upperHeight)/2));
    _edgeSp->setPhysicsBody(edgeBody);
    _mainScene->addChild(_edgeSp);

    
    this->addChild(rootNode);
    
    //Setup UI

    _passCode = PassCode::createWithStr(mapState.passCode);
    _passCode->setAnchorPoint(Vec2(0.5f,0.5f));
    _passCode->setPosition(Vec2(visibleSize.width * 0.2f, visibleSize.height * 0.95f));
    this->addChild(_passCode);
    

    
    ui::Button* backButton = ui::Button::create();
    backButton->setAnchorPoint(Vec2(0.0f,1.0f));
    backButton->setPosition(Vec2(0.0f,visibleSize.height));
    backButton->loadTextures("backButton.png", "backButtonPressed.png");
    backButton->addTouchEventListener(CC_CALLBACK_2(GameScene::backButtonPressed,this));
    this->addChild(backButton);
    
    
    Coin* uiCoin = Coin::create();
    uiCoin->setAnchorPoint(Vec2(0.5f, 0.5f));
    uiCoin->setPosition(Vec2(visibleSize.width * 0.8f, visibleSize.height * 0.95f));
    this->addChild(uiCoin);
    
    this->_scoreLabel = ui::Text::create("0",FONT_NAME,FONT_SIZE);
    this->_scoreLabel->setAnchorPoint(Vec2(0.5f, 0.5f));
    this->_scoreLabel->setPosition(Vec2(visibleSize.width * 0.9f, visibleSize.height * 0.95f));
    this->_scoreLabel->setColor(LABEL_COLOR);
    
    this->addChild(_scoreLabel);
    
}

void GameScene::setupBall()
{
    _ballWaitShooting = _ballsInBag.front();
    _ballWaitShooting->retain();
    _ballsInBag.erase(_ballsInBag.begin());
    
    Vec2 ballPos = _cannon->getPosition();
    _ballWaitShooting->setPosition(ballPos);
    
    _ballsOnState.pushBack(_ballWaitShooting);
    this->addChild(_ballWaitShooting);
    resetEgde();
    _gameState = GameState::prepareShooting;
}


void GameScene::update(float dt)
{
    Node::update(dt);
    if (_gameState == GameState::shooting && this->allBallIsStoped()) {
        if (isGameOver()) {
            triggerGameOver();
        } else {
            _ballWaitShooting->release();
            _ballWaitShooting = nullptr;
            setupBall();
        }

    }
}

void GameScene::triggerGameOver()
{
    if (isGoalAchieved()) {
        //TODO: add animation to
        
        int totalScore = _ballsInBag.size()*3 + _currentScore;
        int starsNum = evaluateStars(totalScore);
        
        Size visibleSize = Director::getInstance()->getVisibleSize();
        
        CSLoader* instance = CSLoader::getInstance();
        instance->registReaderObject("LevelClearReader" , (ObjectFactory::Instance) LevelClearReader::getInstance);

        LevelClear* levelClear = dynamic_cast<LevelClear*>(CSLoader::createNode("LevelClear.csb"));
        levelClear->setAnchorPoint(Vec2(0.5f, 0.5f));
        levelClear->setPosition(Vec2(visibleSize.width/2, visibleSize.height * 0.55));
        levelClear->runLevelClearAnimation(starsNum);
        this->addChild(levelClear);
        
        _mainScene->runAction(FadeTo::create(0.5, 128));
    
        UserDefault::getInstance()->setIntegerForKey(StringUtils::toString(_level).c_str(), starsNum);
        UserDefault::getInstance()->setIntegerForKey(StringUtils::toString(_level+1).c_str(), UNLOCKED_LEVEL);

        _gameState = GameState::gameOver;
        
  //      std::string starStr = StringUtils::toString(starsNum);
 //       std::string messageContent = "Your Got " + starStr + " Stars !";
        
 //       MessageBox(messageContent.c_str(), "Game Over!!");
   //     SceneManager::getInstance()->backToLobby();
        
    } else {
        std::string messageContent = "Your Failed !";
        MessageBox(messageContent.c_str(), "Game Over!!");
        SceneManager::getInstance()->backToLobby();

    }
}

#pragma mark -
#pragma mark CallBack Methods

bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{
    PhysicsBody *a = contact.getShapeA()->getBody();
    PhysicsBody *b = contact.getShapeB()->getBody();
    
    //Pass the first collusion of edge
    if (a->getCategoryBitmask() == EDGE_CATEGORY || b->getCategoryBitmask() == EDGE_CATEGORY) {
        _edgeSp->getPhysicsBody()->setContactTestBitmask(EDGE_RUNNING_CONTACT_MASK);
        _edgeSp->getPhysicsBody()->setCollisionBitmask(EDGE_RUNNING_CULLISION_MASK);
        return false;
    }
    
    //TODO:make a emun type detection,fix this ugly code
    
    BallColor aColor = static_cast<BallColor>(a->getTag());
    BallColor bColor = static_cast<BallColor>(b->getTag());
    _passCode->EnterOneColor(aColor);
    if (_passCode->EnterOneColor(bColor)) {
        _passCode->EnterOneColor(aColor);
    }
    
    if (aColor == bColor) {
        Coin* coin = Coin::create();
        coin->setPosition(a->getPosition());
        _mainScene->addChild(coin);
        coin->runGetCoinAnimation();
        _currentScore += 1;
    } else {
    }
    
    
    updateScoreLabel(_currentScore);
    
    return true;
}

void GameScene::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    
    static Vec2 lastTouchPos;
    static Vec2 firstTouchPos;
    static Vec2 initPos;
    static bool allowToShoot;
    
    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        Vec2 touchPos = this->convertTouchToNodeSpace(touch);
        lastTouchPos = touchPos;
        firstTouchPos = touchPos;
        switch (_gameState) {
            case GameState::prepareShooting:
            {
                allowToShoot = true;
                return true;
            }
                break;
            case GameState::shooting:
            {
                allowToShoot = false;
                return true;
            }
        }

    };
    
    touchListener->onTouchMoved = [&](Touch* touch, Event* event)
    {
        Vec2 touchPos = this->convertTouchToNodeSpace(touch);
        //change 180 degree when move from left of screen to right
        auto visibleSize = Director::getInstance()->getVisibleSize();
        float angle = (touchPos.x - lastTouchPos.x)/visibleSize.width * 180;
        _cannon->setAngle(angle);
        lastTouchPos = touchPos;
        allowToShoot = false;
    };
    
    
    touchListener->onTouchEnded = [&](Touch* touch, Event* event)
    {
        if (allowToShoot) {
            _cannon->runShootingAnimation();
            _dogi->runShootingAnimation();
            _ballWaitShooting->shoot(MAX_SHOOTING_SPEED,_cannon->getAngle());
            _gameState = GameState::shooting;
            if (_isMultiplayer) {
                //sendData
            }
        }
    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

#pragma mark -
#pragma mark UI Method



void GameScene::backButtonPressed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SceneManager::getInstance()->backToLobby();
    }
    
}

bool GameScene::allBallIsStoped()
{
    for (auto ball : _ballsOnState) {
        if (! ball->isStoped()) {
            return false;
        }
    }
    return true;
}


#pragma mark -
#pragma mark Util Methods;

void GameScene::updateScoreLabel(int score)
{
    std::string scoreString = StringUtils::toString(score);
    this->_scoreLabel->setString(scoreString);
}

void GameScene::resetEgde()
{
    _edgeSp->getPhysicsBody()->setContactTestBitmask(EDGE_INIT_CONTACT_MASK);
    _edgeSp->getPhysicsBody()->setCollisionBitmask(EDGE_INIT_CULLISION_MASK);
    
}

bool GameScene::isGoalAchieved(){
    return _passCode->isPassCodeClear();
}

bool GameScene::isGameOver()
{
    if (isGoalAchieved()) {
        return true;
    }
    
    if (_ballsInBag.empty()) {
        return true;
    }
    
    return false;
}

int GameScene::evaluateStars(int currentScore)
{
    if (currentScore >= _threeStarScore) {
        return 3;
    } else if (currentScore >= _twoStarScore) {
        return 2;
    } else if (currentScore >= _oneStarScore) {
        return 1;
    } else {
        return 0;
    }

}

std::string GameScene::getConfigFileName()
{
    return "map" + StringUtils::toString(_level) + ".json";
}