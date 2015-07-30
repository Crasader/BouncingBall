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
    
    _timeline = CSLoader::createTimeline("Cannon.csb");
    _timeline->retain();
    
    return true;
}


void Cannon::onExit()
{
    _timeline->release();
    Node::onExit();
}
void Cannon::runShootingAnimation()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("Shoot",false);
    
}

#pragma mark -
#pragma mark Getter/Setter

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

void Cannon::simulateShoot(float angle, CallFunc* dogiJump, CallFunc* ballShoot)
{
    auto action = Sequence::create(RotateTo::create(0.5f, angle),
                                   CallFunc::create(CC_CALLBACK_0(Cannon::runShootingAnimation,this)),
                                   dogiJump,
                                   ballShoot,
                                   nullptr);
    
    this->getChildByName<Sprite*>("cannon")->runAction(action);
}