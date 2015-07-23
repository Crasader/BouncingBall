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

bool LevelSelect::init()
{
    if (! Node::init()) {
        return false;
    }

    return true;
}

void LevelSelect::onEnter()
{
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
            float yPos = GRID_INIT_Y_POS + row * (GRID_HEIGHT+GRID_Y_INTERVAL);
            levelGrid->setPosition(Vec2(xPos, yPos));
            this->addChild(levelGrid);
            ui::Button* button = this->getChildByName<ui::Button*>("Button");
            std::string labelStr = "1";
            std::string configFile = "map" + labelStr + ".json";
            button->addTouchEventListener()

        }
    }
    
}

void LevelSelect::levelButtonPressed(Ref* pSender, ui::Widget::TouchEventType eEventType, std::string configFile)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SceneManager::getInstance()->enterGameScene(configFile);
    }
}


