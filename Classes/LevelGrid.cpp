//
//  LevelGrid.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/24/15.
//
//

#include "LevelGrid.h"


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