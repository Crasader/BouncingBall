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
#include "TapInfo.h"

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
    auto rootNode = CSLoader::createNode("Title.csb");
    ui::Button* singlePlayerButton = rootNode->getChildByName<ui::Button*>("singlePlayButton");
    ui::Button* multiplayerButton = rootNode->getChildByName<ui::Button*>("multiplayButton");
    ui::Button* specialThankButton = rootNode->getChildByName<ui::Button*>("specialThankButton");
    
    singlePlayerButton->addTouchEventListener(CC_CALLBACK_2(Lobby::SinglePlayerPressed,this));
    multiplayerButton->addTouchEventListener(CC_CALLBACK_2(Lobby::multiplayerPressed, this));
    specialThankButton->addTouchEventListener(CC_CALLBACK_2(Lobby::specialThankPressed, this));
    
    this->addChild(rootNode);
    
}

void Lobby::specialThankPressed(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto buttonInPanel = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        buttonInPanel->runAction(ScaleTo::create(0.1f, 1.6));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        buttonInPanel->runAction(ScaleTo::create(0.1f, 1.8f));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        buttonInPanel->runAction(ScaleTo::create(0.1f, 1.8f));
        std::vector<std::string> infoList;
        TapInfo* tapInfo = TapInfo::create();
        infoList.push_back("Special Thanks:");
        infoList.push_back("");
        infoList.push_back("Daniel Haaser");
        infoList.push_back("");
        infoList.push_back("Ken Watanabe");
        infoList.push_back("");
        infoList.push_back("Ying Huang");
        tapInfo->displayInfo(infoList,900.0f);
        this->addChild(tapInfo);
    }
}
void Lobby::SinglePlayerPressed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleTo::create(0.1f, 1.6));
    }

    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        button->runAction(ScaleTo::create(0.1f, 1.8f));
        SceneManager::getInstance()->enterLevelSelect();
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleTo::create(0.1f, 1.8f));
    }
}


void Lobby::multiplayerPressed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleTo::create(0.1f, 1.6));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        button->runAction(ScaleTo::create(0.1f, 1.8f));
        SceneManager::getInstance()->showPeerList();
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleTo::create(0.1f, 1.8f));
    }
    
}