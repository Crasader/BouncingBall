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
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{
    PhysicsBody *a = contact.getShapeA()->getBody();
    PhysicsBody *b = contact.getShapeB()->getBody();
    
    //TODO:make a emun type detection,fix this ugly code
    if (a->getCategoryBitmask() == 0x02) {
        _totalScore += a->getTag();
    }

    if (b->getCategoryBitmask() == 0x02 ) {
        _totalScore += b->getTag();
    }
}
void GameScene::setupMap()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("RewardPointReader" , (ObjectFactory::Instance) RewardPointReader::getInstance);
    
    auto rootNode = CSLoader::createNode("Stage1MainScene.csb");

    //TODO: make a enum to replace the magic number
    
    //TODO: for high speed
    auto edgeSp = Sprite::create();
    auto boundBody = PhysicsBody::createEdgeBox(visibleSize, PhysicsMaterial(0.0f,1.0f,0.0f), 3);
    edgeSp->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    edgeSp->setPhysicsBody(boundBody);
    this->addChild(edgeSp);
    edgeSp->setTag(0);
    
    this->addChild(rootNode);
    
    
}
void GameScene::setupBall()
{
    _ball = Ball::create();
    
    this->addChild(_ball);
}

 //TODO:check if the ball is speed 0,may be using the physcis update

void GameScene::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    static Vec2 lastTouchPos;
    static Vec2 initPos;
    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        //TODO: finish the check that whether user touch the place that can put a ball
        lastTouchPos = this->convertTouchToNodeSpace(touch);
        
        if (_ball->getBoundingBox().containsPoint(lastTouchPos)) {
            _selectedSprite = _ball;
            initPos = _ball->getPosition();
    
            if ( ballIsInShootingArea()) {
                _gameState = GameState::prepareShooting;
            } else {
                _gameState = GameState::moveBallToShootingArea;
            }
            return true;
        } else {
            return false;
        }
        //if item is selected than selectedSprite = items
    //    return true;
    };
    
    touchListener->onTouchMoved = [&](Touch* touch, Event* event)
    {
        Vec2 touchPos = this->convertTouchToNodeSpace(touch);
        switch (_gameState) {
            case GameState::moveBallToShootingArea:
            {
                _ball->setPosition(touchPos);
            }
                break;
            case GameState::prepareShooting:
                break;
            default:
                break;
        }
        
        
    };
    
    touchListener->onTouchEnded = [&](Touch* touch, Event* event)
    {
        Vec2 touchPos = this->convertTouchToNodeSpace(touch);
        switch (_gameState) {
            case GameState::moveBallToShootingArea:
            {
                if (! ballIsInShootingArea()) {
                    _ball->setPosition(initPos);
                } else {
                    _gameState = GameState::prepareShooting;
                }
            }
                break;
            case GameState::prepareShooting:
            {
                Vec2 velocity = _ball->getPosition() - touchPos;
                _ball->setVelocity(velocity);
                _gameState = GameState::moveBallToShootingArea;
                
            }
        }

    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

bool GameScene::ballIsInShootingArea()
{
    return isInShootingArea(_ball->getPosition());
}

bool GameScene::isInShootingArea(Vec2 pos)
{
    //TODO: make the shooting aear
    if (pos.x < 300 && pos.x > 200) {
        return true;
    } else {
        return false;
    }
}





