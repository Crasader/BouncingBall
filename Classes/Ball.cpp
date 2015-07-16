//
//  Ball.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/15/15.
//
//

#include "Ball.h"
using namespace cocos2d;

bool Ball::init()
{
    if (! Sprite::initWithFile("ball.png")) {
        return false;
    }
    this->setPosition(Vec2(100.0f,100.0f));
    this->setScale(0.2f);
    auto ballBody = PhysicsBody::createCircle(this->getContentSize().width / 10,PhysicsMaterial(0.0f,1.0f,0.0f));
    ballBody->setGravityEnable(false);
    ballBody->setLinearDamping(0.2f);
 //   ballBody->setVelocity(Vec2(200.0f,200.f));
    ballBody->setContactTestBitmask(0x03);
    ballBody->setCategoryBitmask(0x01);
    ballBody->setCollisionBitmask(0x01);
    this->setPhysicsBody(ballBody);
    
    return true;
}

void Ball::setVelocity(Vec2 velocity)
{
    auto ballBody = this->getPhysicsBody();
    ballBody->setVelocity(velocity);
    this->setPhysicsBody(ballBody);
}