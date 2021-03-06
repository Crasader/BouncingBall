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
    this->_levelSelect = nullptr;
    this->networkingWrapper = std::unique_ptr<NetworkingWrapper>(new NetworkingWrapper());
    this->networkingWrapper->setDelegate(this);
}


SceneManager::~SceneManager()
{
}

#pragma mark -
#pragma mark Public Methods

std::string SceneManager::getDeviceName()
{
    return networkingWrapper->getDeviceName();
}

void SceneManager::enterGameScene(int level, bool networked)
{
    Scene* physicsScene = Scene::createWithPhysics();
    if (DEBUG_MODE) {
        physicsScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    }
    
    this->_gameScene = GameScene::createWithLevel(level);
    this->_gameScene->setMultiplay(networked);
    _gameScene->setPhyWorld(physicsScene->getPhysicsWorld());
    physicsScene->getPhysicsWorld()->setAutoStep(false);
    
    physicsScene->addChild(_gameScene);

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
        networkingWrapper->disconnect();
        return;
    }
    if (_levelSelect) {
        Director::getInstance()->popScene();
        _levelSelect = nullptr;
        return;
    }
    
}

void SceneManager::showPeerList()
{
    networkingWrapper->showPeerList();
}

void SceneManager::receiveMultiplayerInvitations()
{
    networkingWrapper->startAdvertisingAvailability();
}

void SceneManager::sendData(const void *data, unsigned long length)
{
    networkingWrapper->sendData(data, length);
}

#pragma mark -
#pragma mark NetworkingWapperDelegate Methods


void SceneManager::receivedData(const void *data, unsigned long length)
{
    if (_gameScene) {
        _gameScene->receivedData(data, length);
    }
}

void SceneManager::stateChanged(ConnectionState state)
{
    switch (state) {
        case ConnectionState::CONNECTING:
            CCLOG("Connecting..");
            break;
        case ConnectionState::NOT_CONNECTED:
            MessageBox("Unable to connect, please check your internet connection", "CONNECTION ERROR");
            SceneManager::getInstance()->backToLobby();
            break;
        case ConnectionState::CONNECTED:
            CCLOG("Connected");
            if (! _gameScene) {
                this->networkingWrapper->stopAdvertisingAvailability();
                this->enterGameScene(10000,true);
            }
            break;
    }
}
