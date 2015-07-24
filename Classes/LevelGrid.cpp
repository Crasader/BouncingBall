//
//  LevelGrid.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/24/15.
//
//

#include "LevelGrid.h"
#include "ui/CocosGUI.h"

bool LevelGrid::init()
{
    if (! Node::init())
    {
        return false;
    }
    
    return true;
}

void LevelGrid::setDisplayStar(int starNums)
{
    //FIXME: magic num
    switch (starNums) {
        case 3:
            this->getChildByName<Sprite*>("star3")->setOpacity(255);
        case 2:
            this->getChildByName<Sprite*>("star2")->setOpacity(255);
        case 1:
            this->getChildByName<Sprite*>("star1")->setOpacity(255);
        default:
            break;
    }
}

void LevelGrid::setLevel(int level)
{
    _level = level;
    std::string labelStr = StringUtils::toString(_level);
    ui::TextBMFont* label = this->getChildByName<ui::TextBMFont*>("Label");
    label->setString(labelStr);
    
}

int LevelGrid::getLevel()
{
    return _level;
}
