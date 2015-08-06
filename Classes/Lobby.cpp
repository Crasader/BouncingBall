//
//  Lobby.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/15/15.
//
//

#include "Lobby.h"
#include "SceneManager.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

bool Lobby::init()
{
    if (! Node::init()) {
        return false;
    }
    
    return true;
}

void Lobby::onEnter()
{
    Node::onEnter();
    
    SceneManager::getInstance()->receiveMultiplayerInvitations();
    
    setupUI();
}

void Lobby::setupUI()
{
    Size visiableSize = Director::getInstance()->getVisibleSize();

    auto rootNode = CSLoader::createNode("Title.csb");
    ui::Button* singlePlayerButton = rootNode->getChildByName<ui::Button*>("singlePlayButton");
    ui::Button* multiplayerButton = rootNode->getChildByName<ui::Button*>("multiplayButton");
    ui::Button* optionButton = rootNode->getChildByName<ui::Button*>("optionButton");
    
    singlePlayerButton->addTouchEventListener(CC_CALLBACK_2(Lobby::SinglePlayerPressed,this));
    multiplayerButton->addTouchEventListener(CC_CALLBACK_2(Lobby::multiplayerPressed, this));
    this->addChild(rootNode);
}

void Lobby::SinglePlayerPressed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }

    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
        SceneManager::getInstance()->enterLevelSelect();
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}


void Lobby::multiplayerPressed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
        SceneManager::getInstance()->showPeerList();
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
    
}