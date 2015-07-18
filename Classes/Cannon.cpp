//
//  Cannon.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/17/15.
//
//

#include "Cannon.h"
#include "Ball.h"

bool Cannon::init()
{
    if (! Node::init())
    {
        return false;
    }
    
    // load the character animation timeline
    _timeline = CSLoader::createTimeline("Cannon.csb");

    
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    
    return true;
}


void Cannon::onExit()
{
    // release the retain we called in init
    _timeline->release();
    Node::onExit();
}
void Cannon::runShootingAnimation()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("Shoot",false);
    
}

float Cannon::getAngle()
{
    return this->getChildByName<Sprite*>("cannon")->getRotation();
}

void Cannon::setAngle(float angle)
{
    float currentAngle = this->getAngle();
    float newAngle = angle + currentAngle;
    if (newAngle > 60) {
        newAngle = 60;
    } else if (newAngle < -60) {
        newAngle = -60;
    }
    this->getChildByName<Sprite*>("cannon")->setRotation(newAngle);
}
