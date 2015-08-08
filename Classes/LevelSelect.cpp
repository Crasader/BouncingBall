//
//  LevelSelect.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/24/15.
//
//

#include "LevelSelect.h"
#include "LevelGrid.h"
#include "LevelGridReader.h"

#include "UIConstants.h"
#include "SceneManager.h"
#include "Constants.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


bool LevelSelect::init()
{
    if (! Node::init()) {
        return false;
    }
    _levelPageNum = 1;
    return true;
}

void LevelSelect::onEnter()
{
    Node::onEnter();
    
    auto rootNode = CSLoader::createNode("LevelSelect.csb");
    
    this->addChild(rootNode);
    
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("LevelGridReader" , (ObjectFactory::Instance) LevelGridReader::getInstance);
    
    UserDefault* userDataInstance = UserDefault::getInstance();
    
    //FIXME: make initializd func for whole game and remove this temp code
    int firstLevel = userDataInstance->getIntegerForKey("1",LOCKED_LEVEL);
    if (firstLevel == -1) {
        userDataInstance->setIntegerForKey("1",0);
    }
    
    ui::Button* titleButton = rootNode->getChildByName<ui::Button*>("titleButton");
    ui::Button* nextPageButton = rootNode->getChildByName<ui::Button*>("nextPageButton");
    ui::Button* prevPageButton = rootNode->getChildByName<ui::Button*>("prevPageButton");
    
    titleButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        auto buttonInPanel = dynamic_cast<ui::Button*>(sender);
        if (type == ui::Widget::TouchEventType::BEGAN) {
            buttonInPanel->runAction(ScaleTo::create(0.1f, 0.9));
        }
        if (type == ui::Widget::TouchEventType::CANCELED) {
            buttonInPanel->runAction(ScaleTo::create(0.1f, 1.0f));
        }
        if (type == ui::Widget::TouchEventType::ENDED) {
            buttonInPanel->runAction(ScaleTo::create(0.1f, 1.0f));
            SceneManager::getInstance()->backToLobby();
        }
    });
    
    nextPageButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        auto buttonInPanel = dynamic_cast<ui::Button*>(sender);
        if (type == ui::Widget::TouchEventType::BEGAN) {
            buttonInPanel->runAction(ScaleTo::create(0.1f, 0.9));
        }
        if (type == ui::Widget::TouchEventType::CANCELED) {
            buttonInPanel->runAction(ScaleTo::create(0.1f, 1.0f));
        }
        if (type == ui::Widget::TouchEventType::ENDED) {
            buttonInPanel->runAction(ScaleTo::create(0.1f, 1.0f));
            if (_levelPageNum < MAX_LEVEL_PAGE_NUMS) {
                _levelPageNum++;
                _levelPage->removeFromParent();
                _levelPage = createLeveSelectPage(_levelPageNum);
                this->addChild(_levelPage);
            }
        }
    });
    
    
    prevPageButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        auto buttonInPanel = dynamic_cast<ui::Button*>(sender);
        if (type == ui::Widget::TouchEventType::BEGAN) {
            buttonInPanel->runAction(ScaleTo::create(0.1f, 0.9));
        }
        if (type == ui::Widget::TouchEventType::CANCELED) {
            buttonInPanel->runAction(ScaleTo::create(0.1f, 1.0f));
        }
        if (type == ui::Widget::TouchEventType::ENDED) {
            buttonInPanel->runAction(ScaleTo::create(0.1f, 1.0f));
            if (_levelPageNum > MIN_LEVEL_PAGE_NUMS) {
                _levelPageNum--;
                _levelPage->removeFromParent();
                _levelPage = createLeveSelectPage(_levelPageNum);
                this->addChild(_levelPage);
            }
        }
    });
    
    _levelPage = createLeveSelectPage(_levelPageNum);
    this->addChild(_levelPage);
    
}

Node* LevelSelect::createLeveSelectPage(int pageNum)
{
    Node* levelNode = Node::create();
    UserDefault* userDataInstance = UserDefault::getInstance();
    for (int row = 0; row < LEVELGIRD_ROW_NUM; row++ ) {
        for (int column = 0; column < LEVELGIRD_COLUMN_NUM; ++column) {
            int level = (pageNum - 1) * LEVEL_NUM_PER_PAGE +row * LEVELGIRD_COLUMN_NUM + column + 1;
            //FIXME: more good way to convert
            int starNums = userDataInstance->getIntegerForKey(StringUtils::toString(level).c_str(),LOCKED_LEVEL);
            
            if (starNums == LOCKED_LEVEL) {
                Sprite* lockedGrid = Sprite::create("lockedGrid.png");
                lockedGrid->setAnchorPoint(Vec2(0.5f, 0.0f));
                float xPos = GRID_INIT_X_POS + column * (GRID_WIDTH+GRID_X_INTERVAL);
                float yPos = GRID_INIT_Y_POS - row * (GRID_HEIGHT+GRID_Y_INTERVAL);
                lockedGrid->setPosition(Vec2(xPos, yPos));
                levelNode->addChild(lockedGrid);
                
            } else {
                LevelGrid* levelGrid = dynamic_cast<LevelGrid*>(CSLoader::createNode("LevelGrid.csb"));
                float xPos = GRID_INIT_X_POS + column * (GRID_WIDTH+GRID_X_INTERVAL);
                float yPos = GRID_INIT_Y_POS - row * (GRID_HEIGHT+GRID_Y_INTERVAL);
                levelGrid->setPosition(Vec2(xPos, yPos));
                levelGrid->setLevel(level);
                levelGrid->setDisplayStar(starNums);
                ui::Button* button = levelGrid->getChildByName<ui::Button*>("Button");
                button->addTouchEventListener(CC_CALLBACK_2(LevelSelect::levelButtonPressed, this));
                levelNode->addChild(levelGrid);
            }
            
        }
    }
    return levelNode;
}

void LevelSelect::levelButtonPressed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    LevelGrid* levelGrid = dynamic_cast<LevelGrid*>(button->getParent());

    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleTo::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleTo::create(0.1f, 1.0f));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        button->runAction(ScaleTo::create(0.1f, 1.0f));
        SceneManager::getInstance()->enterGameScene(levelGrid->getLevel(), false);
    }
}


