//
//  LevelClear.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/24/15.
//
//

#include "LevelClear.h"
#include "SceneManager.h"

bool LevelClear::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->_timeline = CSLoader::createTimeline("LevelClear.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->_timeline->retain();

    return true;
}

void LevelClear::onExit()
{
    _timeline->release();
    Node::onExit();
}

void LevelClear::runLevelClearAnimation(int starNums)
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("Appear",false);
    switch (starNums) {
        case 1:
            _timeline->play("oneStar",false);
            break;
        case 2:
            _timeline->play("twoStar",false);
            break;
        case 3:
            _timeline->play("threeStar", false);
            break;
        default:
            break;
    }
}