
//
//  Dogi.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/23/15.
//
//

#include "Dogi.h"

bool Dogi::init()
{
    if (! Node::init())
    {
        return false;
    }
    
    _timeline = CSLoader::createTimeline("Dogi.csb");
    _timeline->retain();
    
    return true;
}


void Dogi::onExit()
{
    _timeline->release();
    Node::onExit();
}
void Dogi::runShootingAnimation()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("Shoot",false);
    
}

void Dogi::runWinAnimation()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("Win",false);
    
}


