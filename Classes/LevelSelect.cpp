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


//TODO: make a locked menu for level select

void LevelSelect::onEnter()
{
    Node::onEnter();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Sprite* backGround = Sprite::create("levelBackGround.png");
    
    backGround->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    backGround->setAnchorPoint(Vec2(0.5f,0.5f));
    
    this->addChild(backGround);
    
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("LevelGridReader" , (ObjectFactory::Instance) LevelGridReader::getInstance);
    
    for (int row = 0; row < LEVELGIRD_ROW_NUM; row++ ) {
        for (int column = 0; column < LEVELGIRD_COLUMN_NUM; ++column) {
            LevelGrid* levelGrid = dynamic_cast<LevelGrid*>(CSLoader::createNode("LevelGrid.csb"));
            levelGrid->setAnchorPoint(Vec2(0.0f, 0.0f));
            float xPos = GRID_INIT_X_POS + column * (GRID_WIDTH+GRID_X_INTERVAL);
            float yPos = GRID_INIT_Y_POS - row * (GRID_HEIGHT+GRID_Y_INTERVAL);
            levelGrid->setPosition(Vec2(xPos, yPos));
            
            int levelnum = row * LEVELGIRD_COLUMN_NUM + column + 1;
            
            ui::TextBMFont* label = levelGrid->getChildByName<ui::TextBMFont*>("Label");
            std::string labelStr = StringUtils::toString(levelnum);
            label->setString(labelStr);
            
            ui::Button* button = levelGrid->getChildByName<ui::Button*>("Button");
            button->setTag(levelnum);
            
            button->setTouchEnabled(true);
            button->setEnabled(true);
            
            button->addTouchEventListener(CC_CALLBACK_2(LevelSelect::levelButtonPressed, this));
            
            this->addChild(levelGrid);

        }
    }
    
}

void LevelSelect::levelButtonPressed(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    std::string configFile = "map" + StringUtils::toString(button->getTag()) + ".json";
    
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SceneManager::getInstance()->enterGameScene(configFile);
    }
}


