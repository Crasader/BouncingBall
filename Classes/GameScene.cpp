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

#include "ItemBoxReader.h"
#include "ItemBox.h"

#include "JSONPacker.h"
#include "Coin.h"
#include "Rock.h"

#include "PassCode.h"

#include "LevelClear.h"
#include "levelClearReader.h"

#include "Explode.h"
#include "ExplodeReader.h"

#include "Bomb.h"

USING_NS_CC;

//TODO: make Debug func for game over and map test
//TODO: fix bugs that bomb donot hit any thing
//TODO: fix bomb collusion
//TODO: fix diffrence of ball nums

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
    _opponetScore = 0;
    
    //FIXME:
    if (_level == 1) {
        _tutorial = true;
    }
    
    return true;
}

void GameScene::onEnter()
{
    Node::onEnter();
    
    setupMap();
   
    createNextBall();
    
    if  (_isMultiplay) {
        setGameState(GameState::sendDeviceName);
        _simulating = false;
    } else {
        setGameState(GameState::prepareShooting);
    }
    
    if (_tutorial) {
        setGameState(GameState::tutorial);
        setupTutorialTouchHandling();
        setupTutorialContanctHandling();
        setTutorialStep(TutorialStep::swipingCannon);
    } else {
        setupContactHandling();
        setupTouchHandling();
    }
 
    //if tutorial call tutorial touch event
    this->scheduleUpdate();
}

#pragma mark -
#pragma mark Tutorial

void GameScene::setupTutorialTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    
    static Vec2 lastTouchPos;
    static Vec2 initPos;
    static bool allowToShoot;
    static bool allowToMove;
    
    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        Vec2 touchPos = this->convertTouchToNodeSpace(touch);
        lastTouchPos = touchPos;
        allowToShoot = false;
        allowToMove = false;
        
        switch (_tutorialStep) {
            case TutorialStep::swipingCannon:
            case TutorialStep::aimingBall:
            {
                allowToMove = true;
                return true;
            }
                break;
            case TutorialStep::shootball:
            {
                allowToShoot = true;
                return true;
            }
                break;
            case TutorialStep::ballCrack:
            case TutorialStep::collectCoin:
            {
                allowToMove = true;
                allowToShoot = true;
                return true;
            }
                break;
        }
        return false;
        
    };
    
    touchListener->onTouchMoved = [&](Touch* touch, Event* event)
    {
        if (allowToMove) {
            Vec2 touchPos = this->convertTouchToNodeSpace(touch);
            //change 180 degree when move from left of screen to right
            auto visibleSize = Director::getInstance()->getVisibleSize();
            float angle = (touchPos.x - lastTouchPos.x)/visibleSize.width * 180;
            _cannon->setAngle(angle);
            lastTouchPos = touchPos;
            allowToShoot = false;
        }
        
    };
    
    
    touchListener->onTouchEnded = [&](Touch* touch, Event* event)
    {

        switch (_tutorialStep) {
            case TutorialStep::swipingCannon:
            {
                //angle between 23~27 can hit the red ball
                if (_cannon->getAngle() > 23 && _cannon->getAngle() < 27) {
                    setTutorialStep(TutorialStep::shootball);
                } else if (_cannon->getAngle() > 10 || _cannon->getAngle() < -10) {
                    setTutorialStep(TutorialStep::aimingBall);
                } else {
                    
                }
            }
                break;
            case TutorialStep::aimingBall:
            {
                if (_cannon->getAngle() > 23 && _cannon->getAngle() < 27) {
                    setTutorialStep(TutorialStep::shootball);
                }
            }
                break;
            case TutorialStep::shootball:
                if (allowToShoot) {
                    shootCurrentBall();
                    setTutorialStep(TutorialStep::shooting);
                }

                break;
            case TutorialStep::ballCrack:
                if (allowToShoot) {
                    shootCurrentBall();
                    setTutorialStep(TutorialStep::createCoin);
                }
                break;
            case TutorialStep::collectCoin:
                if (allowToShoot) {
                    shootCurrentBall();
                    setTutorialStep(TutorialStep::collectCoinShooting);
                }
                break;
        }
    
    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
}

void GameScene::setupTutorialContanctHandling()
{
    //contact call back
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBeginTutorial, this);
    contactListener->onContactPostSolve = CC_CALLBACK_1(GameScene::onContactEndTutorial, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

bool GameScene::onContactBeginTutorial(cocos2d::PhysicsContact &contact)
{
    PhysicsBody *a = contact.getShapeA()->getBody();
    PhysicsBody *b = contact.getShapeB()->getBody();
    
    //Pass the first collusion of edge
    if (a->getCategoryBitmask() == EDGE_CATEGORY || b->getCategoryBitmask() == EDGE_CATEGORY) {
        _edgeSp->getPhysicsBody()->setContactTestBitmask(EDGE_RUNNING_CONTACT_MASK);
        _edgeSp->getPhysicsBody()->setCollisionBitmask(EDGE_RUNNING_CULLISION_MASK);
        return false;
    }
    
    // Ball hit Ball
    if (a->getCategoryBitmask() == BALL_CATEGORY && b->getCategoryBitmask() == BALL_CATEGORY) {
        Ball* ballA = static_cast<Ball*>(a->getNode());
        Ball* ballB = static_cast<Ball*>(b->getNode());
        
        if (ballA->getBallColor() == ballB->getBallColor()) {
            Coin* coin = Coin::create();
            coin->setPosition(a->getPosition());
            _mainScene->addChild(coin);
            coin->runGetCoinAnimation();
            _currentScore += 1;
            updateScoreLabel(_currentScore);
            //TODO: make it only appear once
            displayInfo("Same color get one coin",1.0f,0.5f);
        }
        
    }
    
    //Ball hit Coin
    if (b->getCategoryBitmask() == COIN_CATEGORY || a->getCategoryBitmask() == COIN_CATEGORY) {
        Coin* coin;
        coin = dynamic_cast<Coin*>(b->getNode());
        if (coin == nullptr) {
            coin = dynamic_cast<Coin*>(a->getNode());
        }
        coin->removeFromParent();
        auto it = _coinOnStage.find(coin);
        _coinOnStage.erase(it);
        _currentScore += 1;
        updateScoreLabel(_currentScore);
        
    }
    
    return true;
}

void GameScene::onContactEndTutorial(cocos2d::PhysicsContact &contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();
    
    if (a->getCategoryBitmask() == BALL_CATEGORY && b->getCategoryBitmask() == BALL_CATEGORY) {
        Ball* ball = dynamic_cast<Ball*>(a->getNode());
        if (ball->getTag() != TUTORIAL_CRACKED_BALL) {
            ball = dynamic_cast<Ball*>(b->getNode());
            //two ball are both normal ball
            if (ball->getTag() != TUTORIAL_CRACKED_BALL) {
                return;
            }
        }
       
        Vec2 pos = ball->getPosition();
        ball->removeFromParent();
        auto it = _ballsOnState.find(ball);
        _ballsOnState.erase(it);
        
        createCoinByPosWhenBallHpIsZero(pos);
        displayInfo("hit crack ball will create three coin",1.0, 0.5);
    }
    
}

void GameScene::updateTutorial()
{
    switch (_tutorialStep) {
        case TutorialStep::shooting:
        {
            if (this->allBallIsSpeedAreLowEnough()) {
                stopAllBall();
                _ballWaitShooting = nullptr;
                createNextBall();
                for (auto ball : _ballsOnState) {
                    ball->addCrack();
                    ball->setTag(1);
                }
                setTutorialStep(TutorialStep::ballCrack);
            }
        }
            break;
        case TutorialStep::createCoin:
        {
            if (allBallIsSpeedAreLowEnough()) {
                stopAllBall();
                _ballWaitShooting = nullptr;
                
                if (_coinOnStage.size() <= 2) {
                    setTutorialStep(TutorialStep::ballCrack);
                    Ball* ball = Ball::create();
                    _ballsInBag.pushBack(ball);
                } else {
                    setTutorialStep(TutorialStep::collectCoin);
                    enableCoin();
                }
                createNextBall();
            }
        }
            break;
        case TutorialStep::collectCoinShooting:
        {
            if (allBallIsSpeedAreLowEnough()) {
                triggerGameOver();
            }
        }
            break;
        default:
            break;
    }
}

void GameScene::setTutorialStep(TutorialStep step)
{
    _tutorialStep = step;
    switch (_tutorialStep) {
        case TutorialStep::swipingCannon:
            displayInfo("Swipe to move");
            break;
        case TutorialStep::aimingBall:
            displayInfo("Aim the Ball");
            break;
        case TutorialStep::shootball:
            displayInfo("Tap to shoot");
            break;
        case TutorialStep::ballCrack:
            displayInfo("Shoot the cracked ball",1.0,0.5);
            break;
        case TutorialStep::collectCoin:
            displayInfo("Collect the coin",1.0, 0.7);
            
    }
}


#pragma mark - 
#pragma mark - Setup Method

void GameScene::setupContactHandling()
{
    //contact call back
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
    contactListener->onContactPostSolve = CC_CALLBACK_1(GameScene::onContactEnd, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    
}

void GameScene::setupMap()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CannonReader" , (ObjectFactory::Instance) CannonReader::getInstance);
    instance->registReaderObject("DogiReader" , (ObjectFactory::Instance) DogiReader::getInstance);
    instance->registReaderObject("ExplodeReader" , (ObjectFactory::Instance) ExplodeReader::getInstance);
    instance->registReaderObject("ItemBoxReader" , (ObjectFactory::Instance) ItemBoxReader::getInstance);
    
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    _cannon = rootNode->getChildByName<Cannon*>("Cannon");
    _dogi = rootNode->getChildByName<Dogi*>("Dogi");
    _scoreLabel = rootNode->getChildByName<ui::TextBMFont*>("ScoreLabel");
    _itemBox = rootNode->getChildByName<ItemBox*>("ItemBox");
    _nextBallHolder = rootNode->getChildByName<ui::Button*>("NextBallHolder");
    _nextBallHolder->addTouchEventListener(CC_CALLBACK_2(GameScene::ballHolderButtonPressed,this));
    
    _mainScene = rootNode;
    
    std::string jsonStr = FileUtils::getInstance()->getStringFromFile(getConfigFileName());
    JSONPacker::MapState mapState = JSONPacker::unpackMapStateJSON(jsonStr);
    
    //setup balls in stage
    for (auto ballConfig : mapState.ballsOnStage)
    {
        Ball* ball = Ball::createWithColor(ballConfig.color);
        ball->setPosition(ballConfig.pos);
        _mainScene->addChild(ball);
        this->_ballsOnState.pushBack(ball);
    }
    
    //setup balls in bags
    for (auto ballColor : mapState.ballsInBag) {
        Ball* ball = Ball::createWithColor(ballColor);
        this->_ballsInBag.pushBack(ball);
    }
    
    //setup rocks
    for (auto rockPos : mapState.rocks) {
        Rock* rock = Rock::create();
        rock->setPosition(rockPos);
        _rocksOnStage.pushBack(rock);
        _mainScene->addChild(rock);
    }
    
    //setupCoins
    for (auto coinPos : mapState.coins) {
        Coin* coin = Coin::create();
        coin->setPosition(coinPos);
        coin->initCollision();
        coin->enableCollision();
        _coinOnStage.pushBack(coin);
        _mainScene->addChild(coin);
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
    _edgeSp->setContentSize(Size(edgeWidth, edgeHeight));
    _mainScene->addChild(_edgeSp);
    
    this->addChild(rootNode);
    
    //Setup UI
    
    //FIXME: try to refactoring this
    if (!_tutorial) {
        _passCode = PassCode::createWithStr(mapState.passCode);
        _passCode->setAnchorPoint(Vec2(0.5f,0.5f));
        _passCode->setPosition(Vec2(visibleSize.width * 0.3f, visibleSize.height * 0.95f));
        _mainScene->addChild(_passCode);
    } else {
        rootNode->getChildByName("ItemLabel")->setVisible(false);
        rootNode->getChildByName("EqualLabel")->setVisible(false);
    }
    
    
    ui::Button* backButton = ui::Button::create();
    backButton->setAnchorPoint(Vec2(0.0f,0.5f));
    backButton->setPosition(Vec2(0.0f,visibleSize.height* 0.95f));
    backButton->loadTextures("backButton.png", "backButtonPressed.png");
    backButton->addTouchEventListener(CC_CALLBACK_2(GameScene::backButtonPressed,this));
    _mainScene->addChild(backButton);
    
    std::string fileName = _ballsInBag.front()->getBallFileName();
    _ballPreview = Sprite::create(fileName);
    _ballPreview->setPosition(_nextBallHolder->getPosition());
    _mainScene->addChild(_ballPreview);
    
}


void GameScene::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    
    static Vec2 lastTouchPos;
    static Vec2 initPos;
    static bool allowToShoot;
    
    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        Vec2 touchPos = this->convertTouchToNodeSpace(touch);
        lastTouchPos = touchPos;
        
        switch (_gameState) {
            case GameState::prepareShooting:
            {
                Vec2 localPosInItemBox = touchPos - _itemBox->getPosition();
                if (_itemBox->isClicked(localPosInItemBox)) {
                    ItemCategory itemCategory = _itemBox->pickUpItemFromPos(touchPos);
                    if (ItemCategory::none != itemCategory) {
                        createItemWhenTouchedItemBox(itemCategory);
                        GameState nextState = getStateByItem(itemCategory);
                        setGameState(nextState);
                    }
                    return false;
                }
                allowToShoot = true;
                return true;
                
            }
                break;
            case GameState::usingThunder:
            case GameState::usingBomb:
            {
                allowToShoot = true;
                return true;
            };
                break;
            case GameState::shooting:
            case GameState::shootingBomb:
            {
                allowToShoot = false;
                return true;
            };
                break;
        }
        return false;
        
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
        switch (_gameState) {
            case GameState::prepareShooting:
            {
                if (allowToShoot) {
                    _cannon->runShootingAnimation();
                    _dogi->runShootingAnimation();
                    _ballsOnState.pushBack(_ballWaitShooting);
                    _ballWaitShooting->shoot(MAX_SHOOTING_SPEED,_cannon->getAngle());
                    setGameState(GameState::shooting);
                    
                }
            }
                break;
            case GameState::usingThunder:
            {
                if (allowToShoot) {
                    _cannon->runShootingAnimation();
                    _dogi->runShootingAnimation();
                    _ballsOnState.pushBack(_ballWaitShooting);
                    _ballWaitShooting->shoot(MAX_SHOOTING_SPEED * 2,_cannon->getAngle());
                    setGameState(GameState::shooting);
                    
                }
            }
                break;
            case GameState::usingBomb:
            {
                if (allowToShoot) {
                    _cannon->runShootingAnimation();
                    //add Fire animation
                    _dogi->runShootingAnimation();
                    Bomb* bomb = _mainScene->getChildByName<Bomb*>("bomb");
                    bomb->shoot(BOMB_SPEED,_cannon->getAngle());
                    setGameState(GameState::shootingBomb);
                }
            }
                
            default:
                break;
        }
        
    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}


#pragma mark -
#pragma mark Life Cycle

void GameScene::update(float dt)
{
    Node::update(dt);
    _physicsWorld->step(1.0f / 60.0f);
    switch (_gameState) {
        case GameState::shooting:
        {
            // Do nothing if some ball is moving
            if (!allBallIsSpeedAreLowEnough()) {
                break;
            }
            stopAllBall();
            if (canUserGetItem()) {
                _passCode->resetPassCode();
                //TODO: make item random
              //  _itemBox->addItem(ItemCategory::bomb);
                _itemBox->addItem(ItemCategory::thunder);
            }
            if (isGameOver()) {
                triggerGameOver();
            } else {
                _ballWaitShooting = nullptr;
                enableCoin();
                createNextBall();
                if (_isMultiplay) {
                    setGameState(GameState::waiting);
                } else {
                    setGameState(GameState::prepareShooting);
                }
            }
        }
            break;
        case GameState::bombFinish:
        {
            createNextBall();
            _gameState = GameState::prepareShooting;
        }
            break;
            //Only MultiPlay Mode
        case GameState::waitForSimulate:
        {
            if (allBallIsSpeedAreLowEnough() && _simulating == false) {
                stopAllBall();
                setBallPosOnState(_nextBallPos);
                _nextBallPos.clear();
                createNextBall();
                enableCoin();
                setGameState(GameState::prepareShooting);
            }
        }
            break;
        case GameState::waitForFinish:
        {
            if (allBallIsSpeedAreLowEnough() && _simulating == false) {
                triggerGameOver();
            }
        }
            break;
        //Only Tutorial
        case GameState::tutorial:
        {
            updateTutorial();
        }
        default:
            break;
    }
}


void GameScene::triggerGameOver()
{
    setGameState(GameState::gameOver);
    
    if (_isMultiplay) {
        std::string messageContent;
        if (_currentScore > _opponetScore) {
            messageContent = "Your Win !";
        } else if (_currentScore < _opponetScore) {
            messageContent = "Your Lose !";
        } else {
            messageContent = "Draw !";
        }
        MessageBox(messageContent.c_str(), "Game Over!!");
        SceneManager::getInstance()->backToLobby();
        return;
    }

    int starsNum = evaluateStars(_currentScore);
    if (starsNum == 0) {
        std::string messageContent = "Your Failed !";
        MessageBox(messageContent.c_str(), "Game Over!!");
        SceneManager::getInstance()->backToLobby();
        return ;
    }

    LevelClear* levelClear = createLevelClearPanel();
    
    _dogi->removeFromParent();
    Dogi* dogi = dynamic_cast<Dogi*>(CSLoader::createNode("Dogi.csb"));
    dogi->setPosition(Vec2(0.0f,-200.0f));
    levelClear->addChild(dogi);
    this->addChild(levelClear);
    
    dogi->runWinAnimation();
    levelClear->runLevelClearAnimation(starsNum);
    
    _mainScene->runAction(FadeTo::create(0.5, 128));
    
    int currentStars = UserDefault::getInstance()->getIntegerForKey(StringUtils::toString(_level).c_str(),UNLOCKED_LEVEL);
    if (starsNum > currentStars){
        UserDefault::getInstance()->setIntegerForKey(StringUtils::toString(_level).c_str(), starsNum);
    }
    if (UserDefault::getInstance()->getIntegerForKey(StringUtils::toString(_level+1).c_str(), LOCKED_LEVEL) == LOCKED_LEVEL) {
        UserDefault::getInstance()->setIntegerForKey(StringUtils::toString(_level+1).c_str(), UNLOCKED_LEVEL);
    }
    
}


#pragma mark - 
#pragma mark Game Logic

void GameScene::enableCoin()
{
    for (auto coin : _coinOnStage) {
        if (_isMultiplay && coin->getTag() == COIN_WILL_NOT_BE_CREATED_IN_NEXT_TURN) {
            coin->setTag(Node::INVALID_TAG);
        } else {
            coin->enableCollision();
        }
    }
}

void GameScene::shootCurrentBall()
{
    _cannon->runShootingAnimation();
    _dogi->runShootingAnimation();
    _ballsOnState.pushBack(_ballWaitShooting);
    _ballWaitShooting->shoot(MAX_SHOOTING_SPEED,_cannon->getAngle());
}

void GameScene::createNextBall()
{
    //pop one ball from bags and add to screen
    _ballWaitShooting = _ballsInBag.front();
    Vec2 ballPos = _cannon->getPosition();
    _ballWaitShooting->setPosition(ballPos);
    _mainScene->addChild(_ballWaitShooting);
    _ballsInBag.erase(_ballsInBag.begin());
    
    resetEgde();
    updateBallPreview();
    
}

void GameScene::updateBallPreview()
{
    if (_ballsInBag.begin() == _ballsInBag.end()) {
        _ballPreview->setVisible(false);
    } else {
        _ballPreview->setVisible(true);
        std::string fileName = _ballsInBag.front()->getBallFileName();
        _ballPreview->setTexture(fileName);
    }
}

void GameScene::createCoinByPosWhenBallHpIsZero(Vec2 ballPos)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Explode* ballExplode = dynamic_cast<Explode*>(CSLoader::createNode("Explode.csb"));
    ballExplode->setPosition(ballPos);
    _mainScene->addChild(ballExplode);
    ballExplode->runBallExplodeAnimation();
    ballExplode->runAction(Sequence::create(FadeOut::create(1.0f),RemoveSelf::create(),nullptr));
    
    
    std::vector<Vec2> movePos {Vec2(100,100),Vec2(60,60),Vec2(20,20)};
    Vec2 indicator;
    
    if (ballPos.x >= visibleSize.width/2 && ballPos.y >= visibleSize.height/2) {
        indicator = Vec2(-1,-1);
    } else if (ballPos.x >= visibleSize.width/2 && ballPos.y <= visibleSize.height/2) {
        indicator = Vec2(-1,1);
    } else if (ballPos.x <= visibleSize.width/2 && ballPos.y <= visibleSize.height/2) {
        indicator = Vec2(1,1);
    } else {
        indicator = Vec2(1,-1);
    }
    
    for(int i=0 ;i < CREADTED_COIN_NUMS_WHEN_BALL_HP_IS_ZERO ;++i) {
        Coin* coin = Coin::create();
        coin->setPosition(ballPos);
        _mainScene->addChild(coin);
        _coinOnStage.pushBack(coin);
        coin->initCollision();
        coin->runAppearAnimation(Vec2(ballPos.x + indicator.x * movePos[i].x, ballPos.y + indicator.y * movePos[i].y));
        
        if (_isMultiplay) {
            coin->setTag(COIN_WILL_NOT_BE_CREATED_IN_NEXT_TURN);
        }
    }
}

void GameScene::createItemWhenTouchedItemBox(ItemCategory itemCategory)
{
    switch (itemCategory) {
        case ItemCategory::bomb:
        {
            Bomb* bomb = Bomb::create();
            Vec2 bombPos = _cannon->getPosition();
            bomb->setPosition(bombPos);
            bomb->setName("bomb");
            _mainScene->addChild(bomb);
            
            if (_ballWaitShooting) {
                _ballsInBag.insert(0, _ballWaitShooting);
                _ballWaitShooting->removeFromParent();
                _ballWaitShooting = nullptr;
            }
            updateBallPreview();
            resetEgde();
        }
            break;
            //TODO add other item
        default:
            break;
    }
}
void GameScene::dealWithHpBall(Ball *ball)
{
    Vec2 pos = ball->getPosition();
    ball->removeFromParent();
    
    auto it = _ballsOnState.find(ball);
    _ballsOnState.erase(it);
    
    createCoinByPosWhenBallHpIsZero(pos);
}


#pragma mark -
#pragma mark Contact Event

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

    
    // Ball hit Ball
    if (a->getCategoryBitmask() == BALL_CATEGORY && b->getCategoryBitmask() == BALL_CATEGORY) {
        BallColor aColor = static_cast<Ball*>(a->getNode())->getBallColor();
        BallColor bColor = static_cast<Ball*>(b->getNode())->getBallColor();
        if (isMyTurn()) {
            _passCode->EnterOneColor(aColor);
            if (_passCode->EnterOneColor(bColor)) {
                _passCode->EnterOneColor(aColor);
            }
        }
       
        if (aColor == bColor) {
            Coin* coin = Coin::create();
            coin->setPosition(a->getPosition());
            _mainScene->addChild(coin);
            coin->runGetCoinAnimation();
            if (!isMyTurn()) {
                _opponetScore++;
            } else {
                _currentScore += 1;
                updateScoreLabel(_currentScore);
            }
        }
    }
    
    //Ball hit Coin
    if ((a->getCategoryBitmask() | b->getCategoryBitmask()) == BALL_HIT_COIN) {
        Coin* coin;
        coin = dynamic_cast<Coin*>(a->getNode());
        if (! coin) {
            coin = static_cast<Coin*>(b->getNode());
        }
        
        coin->removeFromParent();
        auto it = _coinOnStage.find(coin);
        _coinOnStage.erase(it);
        
        if (!isMyTurn()) {
            _opponetScore++;
        } else {
            _currentScore += 1;
            updateScoreLabel(_currentScore);
        }
 
    }

    //Bomb hitted
    if (a->getCategoryBitmask() == BOMB_CATEGORY || b->getCategoryBitmask() == BOMB_CATEGORY) {
        Bomb* bomb = _mainScene->getChildByName<Bomb*>("bomb");
        
        Explode* bombExplode = dynamic_cast<Explode*>(CSLoader::createNode("Explode.csb"));
        bombExplode->setPosition(bomb->getPosition());
        _mainScene->addChild(bombExplode);
        bombExplode->runBombExplodeAnimation();
        bombExplode->runAction(Sequence::create(FadeOut::create(1.0f),RemoveSelf::create(),nullptr));
        
        // Destory coin in range
        for (Vector<Coin*>::iterator it = _coinOnStage.begin(); it !=_coinOnStage.end();) {
            if (bomb->getBombRange().containsPoint((*it)->getPosition())) {
                (*it)->removeFromParent();
                _coinOnStage.erase(it);
            } else {
                it++;
            }
        }
        
        // Destroy rock in range
        for (Vector<Rock*>::iterator it = _rocksOnStage.begin(); it !=_rocksOnStage.end();) {
            if (bomb->getBombRange().containsPoint((*it)->getPosition())) {
                (*it)->removeFromParent();
                _rocksOnStage.erase(it);
            } else {
                it++;
            }
        }
        
        // Set Ball HP to zero
        for (Vector<Ball*>::iterator it = _ballsOnState.begin(); it !=_ballsOnState.end();) {
            if (bomb->getBombRange().containsPoint((*it)->getPosition())) {
                Vec2 pos = (*it)->getPosition();
                (*it)->removeFromParent();
                _ballsOnState.erase(it);
                createCoinByPosWhenBallHpIsZero(pos);
            } else {
                it++;
            }
        }
        
        //temp code to prevent too fast contact maybe not neccesary ,need to test more
        // bomb->getPhysicsBody()->setContactTestBitmask(NONE);
        bomb->removeFromParent();
        _gameState = GameState::bombFinish;
        return false;
    }
    
    return true;
}


void GameScene::onContactEnd(cocos2d::PhysicsContact &contact)
{
    PhysicsBody *a = contact.getShapeA()->getBody();
    PhysicsBody *b = contact.getShapeB()->getBody();
    
    if (a->getCategoryBitmask() == BALL_CATEGORY && b->getCategoryBitmask() == BALL_CATEGORY) {
        Ball* ballA = static_cast<Ball*>(a->getNode());
        Ball* ballB = static_cast<Ball*>(b->getNode());
        ballA->gotHit();
        ballB->gotHit();
        if (ballA->getHp() <= 0) {
            dealWithHpBall(ballA);
        }
        if (ballB->getHp() <= 0) {
            dealWithHpBall(ballB);
        }
        
    }
}

#pragma mark -
#pragma mark UI Method

LevelClear* GameScene::createLevelClearPanel()
{
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("LevelClearReader" , (ObjectFactory::Instance) LevelClearReader::getInstance);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    LevelClear* levelClear = dynamic_cast<LevelClear*>(CSLoader::createNode("LevelClear.csb"));
    
    levelClear->setAnchorPoint(Vec2(0.5f, 0.5f));
    levelClear->setPosition(Vec2(visibleSize.width/2, visibleSize.height * 0.55));
    
    ui::Button* menuButton = levelClear->getChildByName("clearWindow")->getChildByName<ui::Button*>("menuButton");
    ui::Button* restartButton = levelClear->getChildByName("clearWindow")->getChildByName<ui::Button*>("restartButton");
    ui::Button* nextButton = levelClear->getChildByName("clearWindow")->getChildByName<ui::Button*>("nextButton");
    
    restartButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        if (type == ui::Widget::TouchEventType::ENDED) {
            SceneManager::getInstance()->backToLobby();
            SceneManager::getInstance()->enterGameScene(_level, false);
        }
    });
    
    nextButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        if (type == ui::Widget::TouchEventType::ENDED) {
            SceneManager::getInstance()->backToLobby();
            SceneManager::getInstance()->enterGameScene(_level+1, false);
        }
    });
    
    
    menuButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        if (type == ui::Widget::TouchEventType::ENDED) {
            SceneManager::getInstance()->backToLobby();
        }
    });
    return levelClear;
}

void GameScene::backButtonPressed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SceneManager::getInstance()->backToLobby();
    }
    
}

void GameScene::ballHolderButtonPressed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        //TODO: make a func that cancel to use item?
        CCLOG("pressed");
    }
}

#pragma mark - 
#pragma mark Setter/Getter

GameState GameScene::getStateByItem(ItemCategory itemCategory) const
{
    switch (itemCategory) {
        case ItemCategory::bomb:
            return GameState::usingBomb;
        case ItemCategory::thunder:
            return GameState::usingThunder;
    }
}
void GameScene::setGameState(GameState gameState)
{
    _gameState = gameState;
    if (_isMultiplay) {
        
        JSONPacker::MultiInputData multiInputData;
        multiInputData.gameState = gameState;
        switch (gameState) {
            case GameState::sendDeviceName:
            {
                multiInputData.deviceName = SceneManager::getInstance()->getDeviceName();
            }
                break;
            case GameState::waiting:
            {
                multiInputData.ballPos = getBallPosOnState();
                _simulating = true;
            }
                break;
            case GameState::shooting:
            case GameState::shootingBomb:
            {
                multiInputData.angle = _cannon->getAngle();
            }
                break;
            default:
                break;
        }
        sendData(multiInputData);
    }
}


std::string GameScene::getConfigFileName() const
{
    return "map" + StringUtils::toString(_level) + ".json";
}

std::vector<Vec2> GameScene::getBallPosOnState() const
{
    std::vector<Vec2> ballPos;
    for (auto ball : _ballsOnState ) {
        ballPos.push_back(ball->getPosition());
    }
    return ballPos;
}



#pragma mark -
#pragma mark Util Methods

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

bool GameScene::allBallIsSpeedAreLowEnough() const
{
    for (auto ball : _ballsOnState) {
        if (! ball->isStoped()) {
            return false;
        }
    }
    return true;
}

void GameScene::stopAllBall()
{
    for (auto ball : _ballsOnState) {
        ball->stop();
    }
}

bool GameScene::canUserGetItem() const
{
    return _passCode->isPassCodeClear();
}

bool GameScene::isGameOver() const
{
    if (_ballsInBag.empty()) {
        return true;
    }
    return false;
}

int GameScene::evaluateStars(int currentScore) const
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

void GameScene::resetAllBallHp()
{
    for (auto ball : _ballsOnState) {
        ball->setHp(BALL_DEFAULT_HP);
    }
}

//default second = 1.0f,scale = 1.0f;
void GameScene::displayInfo(std::string info, float second, float scale)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    ui::TextBMFont* infoLabel = ui::TextBMFont::create(info, "font01.fnt");
    infoLabel->setAnchorPoint(Vec2(0.5,0.5));
    infoLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    infoLabel->setOpacity(0);
    infoLabel->setScale(scale);
    _mainScene->addChild(infoLabel);
    infoLabel->runAction(Sequence::create(FadeIn::create(second),DelayTime::create(1), RemoveSelf::create(),nullptr));
}

void GameScene::disableTouchEvent()
{

}


#pragma mark -
#pragma makr MultiPlay

//sync game status
/*
 
 before
 1.send each device name to others
 2.use to device name to decide who is host
 3. host randomly choose who is first to play
 4. host send info to guest
 Game Scene(loop)
 1. every state change send a data to other device
 2. other device similate the input of device
 3. define a finished status ot change (if necessary sync the data on stage so that two device share the same items)
 After
 Who get the target send game over to another
 
 rule: try to get the Target coin( e.g 40)
 coin will keep invisible until you own turn
 */


void GameScene::setMultiplay(bool isMultiplay)
{
    _isMultiplay = isMultiplay;
}

void GameScene::receivedData(const void *data, unsigned long length)
{
    const char* cstr = reinterpret_cast<const char*>(data);
    std::string json = std::string(cstr, length);
    
    JSONPacker::MultiInputData multiInputData = JSONPacker::unpackMultiInputDataJSON(json);
    
    performInput(multiInputData);
}

void GameScene::performInput(JSONPacker::MultiInputData multiInputData)
{
    switch (multiInputData.gameState) {
        case GameState::sendDeviceName:
        {
            if (multiInputData.gameState == GameState::sendDeviceName && isMyselfHost(multiInputData.deviceName)) {
                if (canPlayfirst()) {
                    displayInfo("YOU GO FIRST!");
                    setGameState(GameState::prepareShooting);
                } else {
                    displayInfo("YOU GO SECOND!");
                    setGameState(GameState::waiting);
                }
                
            }
        }
            break;
        case GameState::prepareShooting:
        {
            switch (_gameState) {
                case GameState::sendDeviceName:
                {
                    displayInfo("YOU GO SECOND!");
                    _gameState = GameState::waiting;
                }
                    break;
                case GameState::waiting:
                    CCLOG("everything sames good");
                    break;
                default:
                    break;
            }
            
        }
            break;
            //TODO: fix a bugs of one device is too fast than others
        case GameState::waiting:
        {
            switch (_gameState) {
                case GameState::sendDeviceName:
                {
                    displayInfo("YOU GO FIRST!");
                    setGameState(GameState::prepareShooting);
                }
                    break;
                case GameState::prepareShooting:
                    CCLOG("everything sames good");
                case GameState::waiting:
                {
                    CCLOG("it's my turn");
                    _gameState = GameState::waitForSimulate;
                    _nextBallPos = multiInputData.ballPos;
                }
                    break;
                default:
                    break;
            }
            
        }
            break;
        case GameState::shooting:
        {
            _ballsOnState.pushBack(_ballWaitShooting);
            _simulating = true;
            CallFunc* func01 = CallFunc::create([this]()
            {
                _dogi->runShootingAnimation();
                
            });
            CallFunc* func02 = CallFunc::create([this]()
            {
                 _ballWaitShooting->shoot(MAX_SHOOTING_SPEED,_cannon->getAngle());
                _simulating = false;
            });
            _cannon->simulateShoot(multiInputData.angle,func01,func02);
           
        }
            break;
            
        case GameState::usingBomb:
        {
            createItemWhenTouchedItemBox(ItemCategory::bomb);
        }
            break;
        case GameState::shootingBomb:
        {
            _simulating = true;
            CallFunc* func01 = CallFunc::create([this]()
                                                {
                                                    _dogi->runShootingAnimation();
                                                    
                                                });
            CallFunc* func02 = CallFunc::create([this]()
                                                {
                                                    _mainScene->getChildByName<Bomb*>("bomb")->shoot(BOMB_SPEED,_cannon->getAngle());
                                                    _simulating = false;
                                                });
             _cannon->simulateShoot(multiInputData.angle,func01,func02);
            
        }
            break;
        case GameState::gameOver:
        {
            _gameState = GameState::waitForFinish;
        }
            break;
        default:
            break;
    }
}

bool GameScene::isMyselfHost(std::string deviceName) const
{
    std::string myDeviceName = SceneManager::getInstance()->getDeviceName();
    
    //TODO: if device name is same, there will be some error
    if (myDeviceName > deviceName) {
        return true;
    } else {
        return false;
    }
}

bool GameScene::canPlayfirst() const
{
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());
    std::uniform_int_distribution<> dist(0, 1);
    
    if (dist(engine) == 1) {
        return true;
    } else {
        return false;
    }
    
}

void GameScene::sendData(JSONPacker::MultiInputData multiInputData)
{
    std::string json = JSONPacker::packMultiInputDataJSON(multiInputData);
    SceneManager::getInstance()->sendData(json.c_str(), json.length());
}

bool GameScene::isMyTurn() const
{
    return ! (_gameState == GameState::waiting || _gameState == GameState::waitForSimulate || _gameState == GameState::waitForFinish);
}


void GameScene::setBallPosOnState(std::vector<Vec2> ballPos)
{
    for (int i =0; i < ballPos.size(); ++i) {
        _ballsOnState.at(i)->setPosition(ballPos[i]);
    }
}



