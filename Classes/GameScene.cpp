#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "UIConstants.h"

#include "ball.h"
#include "SceneManager.h"

#include "Cannon.h"
#include "CannonReader.h"

#include "JSONPacker.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Node::init() )
    {
        return false;
    }

    _edgeSp = nullptr;
    _totalScore = 0;
   
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

bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{
    PhysicsBody *a = contact.getShapeA()->getBody();
    PhysicsBody *b = contact.getShapeB()->getBody();
    std::string name = contact.getCurrentTarget()->getName();
    
    //TODO:make a emun type detection,fix this ugly code
    if (a->getTag() == b->getTag()) {
        _totalScore += 2;
    } else {
        _totalScore += 1;
    }
    
    if (a->getCategoryBitmask() == EDGE_CATEGORY || b->getCategoryBitmask() == EDGE_CATEGORY) {
        _edgeSp->getPhysicsBody()->setContactTestBitmask(EDGE_RUNNING_CONTACT_MASK);
        _edgeSp->getPhysicsBody()->setCollisionBitmask(EDGE_RUNNING_CULLISION_MASK);
        return false;
    }
    
    updateScoreLabel(_totalScore);

    return true;
}
void GameScene::setupMap()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();

    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CannonReader" , (ObjectFactory::Instance) CannonReader::getInstance);
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
     _cannon = rootNode->getChildByName<Cannon*>("Cannon");

    std::string jsonStr = FileUtils::getInstance()->getStringFromFile("map1.json");
    const JSONPacker::MapState mapState = JSONPacker::unpackMapStateJSON(jsonStr);
 
    for (auto ballconfig : mapState.ballsOnStage)
    {
        Ball* ball = Ball::createWithBallConfig(ballconfig);
        rootNode->addChild(ball);
        this->_ballsOnState.pushBack(ball);
    }
    
    for (auto ballconfig : mapState.ballsInBag) {
        Ball* ball = Ball::createWithBallConfig(ballconfig);
        this->_ballsInBag.pushBack(ball);
    }
    
    this->addChild(rootNode);
    
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
    this->addChild(_edgeSp);
    
    
    //Setup UI
    ui::Button* backButton = ui::Button::create();
    backButton->setAnchorPoint(Vec2(0.0f,1.0f));
    backButton->setPosition(Vec2(0.0f,visibleSize.height));
    backButton->loadTextures("backButton.png", "backButtonPressed.png");
    backButton->addTouchEventListener(CC_CALLBACK_2(GameScene::backButtonPressed,this));
    this->addChild(backButton);
    
    this->_scoreLabel = ui::Text::create("0",FONT_NAME,FONT_SIZE);
    this->_scoreLabel->setAnchorPoint(Vec2(0.5f, 1.0f));
    this->_scoreLabel->setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.98f));
    this->_scoreLabel->setColor(LABEL_COLOR);
    this->addChild(_scoreLabel);
    
}
void GameScene::resetEgde()
{
    _edgeSp->getPhysicsBody()->setContactTestBitmask(EDGE_INIT_CONTACT_MASK);
    _edgeSp->getPhysicsBody()->setCollisionBitmask(EDGE_INIT_CULLISION_MASK);
    
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
            _ballWaitShooting->shoot(MAX_SHOOTING_SPEED,_cannon->getAngle());
            _gameState = GameState::shooting;
        }
       
    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void GameScene::update(float dt)
{
    Node::update(dt);
    if (_gameState == GameState::shooting && this->allBallIsStoped()) {
        _ballWaitShooting->release();
        _ballWaitShooting = nullptr;
        setupBall();
    }
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