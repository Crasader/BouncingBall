//
//  SceneManager.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/16/15.
//
//


#include "SceneManager.h"
#include "cocos2d.h"
#include "GameScene.h"
#include "LevelSelect.h"
using namespace cocos2d;

#pragma mark -
#pragma mark Lifecycle

static SceneManager* sharedSceneManager = nullptr;

SceneManager* SceneManager::getInstance()
{
    if (! sharedSceneManager) {
        sharedSceneManager = new (std::nothrow) SceneManager();
    }
    return sharedSceneManager;
}

SceneManager::SceneManager()
{
    this->_gameScene = nullptr;
//    this->networkingWrapper = std::unique_ptr<NetworkingWrapper>(new NetworkingWrapper());
//    this->networkingWrapper->setDelegate(this);
}


SceneManager::~SceneManager()
{
}

#pragma mark -
#pragma mark Public Methods


void SceneManager::enterGameScene(std::string configFile)
{
    Scene* physicsScene = Scene::createWithPhysics();
    physicsScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    this->_gameScene = GameScene::createWithConfig(configFile);
    _gameScene->setPhyWorld(physicsScene->getPhysicsWorld());
    physicsScene->addChild(_gameScene);

//    this->gameScene->setNetworkedSession(networked);
    
    Director::getInstance()->pushScene(physicsScene);
}
void SceneManager::enterLevelSelect()
{
    Scene* scene = Scene::create();
    this->_levelSelect = LevelSelect::create();
    scene->addChild(_levelSelect);
    Director::getInstance()->pushScene(scene);
    
}

void SceneManager::backToLobby()
{
    if (_gameScene) {
        Director::getInstance()->popScene();
        _gameScene = nullptr;
 //       networkingWrapper->disconnect();
    }
    
}

void SceneManager::showPeerList()
{
 //   networkingWrapper->showPeerList();
}

void SceneManager::receiveMultiplayerInvitations()
{
//    networkingWrapper->startAdvertisingAvailability();
}

void SceneManager::sendData(const void *data, unsigned long length)
{
 //   networkingWrapper->sendData(data, length);
}

#pragma mark -
#pragma mark NetworkingWapperDelegate Methods

/*
void SceneManager::receivedData(const void *data, unsigned long length)
{
    if (gameScene) {
        gameScene->receivedData(data, length);
    }
}

void SceneManager::stateChanged(ConnectionState state)
{
    switch (state) {
        case ConnectionState::CONNECTING:
            CCLOG("Connecting..");
            break;
        case ConnectionState::NOT_CONNECTED:
            CCLOG("Not Connected");
            break;
        case ConnectionState::CONNECTED:
            CCLOG("Connected");
            if (! gameScene) {
                this->networkingWrapper->stopAdvertisingAvailability();
                this->enterGameScene(true);
            }
            break;
    }
}
*/