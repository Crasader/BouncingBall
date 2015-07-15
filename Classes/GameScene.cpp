#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Surface.h"
#include "SurfaceReader.h"
#include "RewardPoint.h"
#include "RewardPointReader.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = GameScene::create();
    layer->setPhyWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    this->totalScore = 0;

   
    return true;
}

void GameScene::onEnter()
{
    Layer::onEnter();
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //TODO: use level loadler to load the all node of game scene
    //code below this should be move to level loader
    
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("RewardPointReader" , (ObjectFactory::Instance) RewardPointReader::getInstance);
    
    auto rootNode = CSLoader::createNode("Stage1MainScene.csb");
  
    _ball = Sprite::create("ball.png");
    _ball->setPosition(Vec2(0,0));
    _ball->setScale(0.2f);
    auto ballBody = PhysicsBody::createCircle(_ball->getContentSize().width / 10,PhysicsMaterial(0.0f,1.0f,0.0f));
    ballBody->setGravityEnable(false);
    ballBody->setVelocity(Vec2(200.0f,200.f));
    ballBody->setContactTestBitmask(0x03);
    ballBody->setCategoryBitmask(0x01);
    ballBody->setCollisionBitmask(0x01);
    //TODO: make a enum to replace the magic number
    
    
    _ball->setPhysicsBody(ballBody);
    this->addChild(_ball);
    
    
    //TODO: for high speed
    auto edgeSp = Sprite::create();
    auto boundBody = PhysicsBody::createEdgeBox(visibleSize, PhysicsMaterial(0.0f,1.0f,0.0f), 3);
    edgeSp->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    edgeSp->setPhysicsBody(boundBody);
    this->addChild(edgeSp);
    edgeSp->setTag(0);

    addChild(rootNode);
    
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{
    PhysicsBody *a = contact.getShapeA()->getBody();
    PhysicsBody *b = contact.getShapeB()->getBody();
    
    //TODO:make a emun type detection,fix this ugly code
    if (a->getCategoryBitmask() == 0x02) {
        this->totalScore += a->getTag();
    }

    if (b->getCategoryBitmask() == 0x02 ) {
        this->totalScore += b->getTag();
    }
}

void GameScene::update()
{
    //TODO:check if the ball is speed 0,may be using the physcis update
}
void GameScene::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        //TODO: finish the check that whether user touch the place that can put a ball
        return true;
    };
    
    touchListener->onTouchMoved = [&](Touch* touch, Event* event)
    {
        //if theres a ball in the place
        //calculate the speed
    };
    
    touchListener->onTouchEnded = [&](Touch* touch, Event* event)
    {
        

    };
    
}



