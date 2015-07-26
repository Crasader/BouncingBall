//
//  BallExplode.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/27/15.
//
//

#include "BallExplode.h"

bool BallExplode::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->_timeline = CSLoader::createTimeline("BallExplode.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->_timeline->retain();

    return true;
}


void BallExplode::onExit()
{
    _timeline->release();
    Node::onExit();
}

void BallExplode::runExplodeAnimation()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("Explode",false);
}