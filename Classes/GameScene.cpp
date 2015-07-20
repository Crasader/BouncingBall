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

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = GameScene::create();
    layer->setPhyWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    _totalScore = 0;
   
    return true;
}

void GameScene::onEnter()
{
    Layer::onEnter();
    
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
    
    //TODO:make a emun type detection,fix this ugly code
    if (a->getTag() == b->getTag()) {
        _totalScore += 2;
    } else {
        _totalScore += 1;
    }
    updateScoreLabel(_totalScore);

    return true;
}
void GameScene::setupMap()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CannonReader" , (ObjectFactory::Instance) CannonReader::getInstance);
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
     _cannon = rootNode->getChildByName<Cannon*>("Cannon");



    std::string jsonStr = FileUtils::getInstance()->getStringFromFile("map1.json");
    const JSONPacker::MapState mapState = JSONPacker::unpackMapStateJSON(jsonStr);
    for (auto ballconfig : mapState.ballConfigs)
    {
        Ball* ball = Ball::createWithBallConfig(ballconfig);
        rootNode->addChild(ball);
        this->_balls.pushBack(ball);
    }

    
    //TODO: for high speed
    auto edgeSp = Sprite::create();
    //TODO: make a enum to replace the magic number
    auto boundBody = PhysicsBody::createEdgeBox(visibleSize, PhysicsMaterial(0.0f,1.0f,0.0f), 3);
    edgeSp->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    edgeSp->setPhysicsBody(boundBody);
    this->addChild(edgeSp);
    edgeSp->setTag(0);
    
    this->addChild(rootNode);
    
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
void GameScene::setupBall()
{
    Ball* ball = Ball::create();
    _ballWaitShooting = ball;
    
    Vec2 ballPos = _cannon->getPosition();
    _ballWaitShooting->setPosition(ballPos);
    
    _balls.pushBack(_ballWaitShooting);
    this->addChild(_ballWaitShooting);
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
        float angle = (touchPos.x - lastTouchPos.x)/this->getContentSize().width * 180;
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
    for (auto ball : _balls) {
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