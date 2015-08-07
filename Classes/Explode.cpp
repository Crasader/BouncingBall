//
//  Explode.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/27/15.
//
//

#include "Explode.h"

bool Explode::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->_timeline = CSLoader::createTimeline("Explode.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->_timeline->retain();

    return true;
}


void Explode::onExit()
{
    _timeline->release();
    Node::onExit();
}

void Explode::runBallExplodeAnimation()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("BallExplode",false);
}

void Explode::runBombExplodeAnimation()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("BombExplode",false);
}
