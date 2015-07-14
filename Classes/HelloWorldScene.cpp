#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Surface.h"
#include "SurfaceReader.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = HelloWorld::create();
    layer->setPhyWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();


    
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("SurfaceReader" , (ObjectFactory::Instance) SurfaceReader::getInstance);
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);
    
    _ball = Sprite::create("ball.png");
    _ball->setPosition(Point(0,0));
    _ball->setScale(0.2f);
    auto ballBody = PhysicsBody::createCircle(_ball->getContentSize().width / 10,PhysicsMaterial(0.0f,1.0f,0.0f));
    ballBody->setGravityEnable(false);
    ballBody->setVelocity(Vec2(200.0f,200.f));
    ballBody->setContactTestBitmask(0x03);
    ballBody->setCategoryBitmask(0x01);
    ballBody->setCollisionBitmask(0x01);
    //TODO make a enum to replace the magic number
    
    
    _ball->setPhysicsBody(ballBody);
    this->addChild(_ball);
    
    
    //TODO: for high speed
    auto edgeSp = Sprite::create();
    auto boundBody = PhysicsBody::createEdgeBox(visibleSize, PhysicsMaterial(0.0f,1.0f,0.0f), 3);
    edgeSp->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    edgeSp->setPhysicsBody(boundBody);
    this->addChild(edgeSp);
    edgeSp->setTag(0);
    
   
    return true;
}

void HelloWorld::onEnter()
{
    Layer::onEnter();
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

bool HelloWorld::onContactBegin(cocos2d::PhysicsContact &contact)
{
    PhysicsBody *a = contact.getShapeA()->getBody();
    PhysicsBody *b = contact.getShapeB()->getBody();
    
    //TODO make a emun type detection
    if (a->getCategoryBitmask() == 0x02 ) {
        const float currentDuamping = b->getLinearDamping();
        b->setLinearDamping(0.1f+currentDuamping);
        return false;
    }

}





