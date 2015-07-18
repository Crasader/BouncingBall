//
//  Ball.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/15/15.
//
//

#include "Ball.h"
#include "Constants.h"
using namespace cocos2d;

bool Ball::init()
{
    if (! Sprite::initWithFile("RedBall.png")) {
        return false;
    }
  //  this->setPosition(Vec2(100.0f,100.0f));
 //   this->setScale(0.2f);
    auto ballBody = PhysicsBody::createCircle(this->getContentSize().width/2 ,PhysicsMaterial(0.0f,1.0f,0.0f));
    ballBody->setGravityEnable(false);
    ballBody->setLinearDamping(0.2f);
    ballBody->setContactTestBitmask(0x03);
    ballBody->setCategoryBitmask(0x01);
    ballBody->setCollisionBitmask(0x01);
    this->setPhysicsBody(ballBody);
    
    return true;
}
bool Ball::isStoped()
{
    Vec2 velocity = this->getPhysicsBody()->getVelocity();
    return (velocity.x < MIN_SPEED  && velocity.y < MIN_SPEED);
}
void Ball::shoot(float speed, float angle)
{
    auto ballBody = this->getPhysicsBody();
    float vx = sin(angle * M_PI / 180) * speed;
    float vy = cos(angle * M_PI / 180) * speed;
    ballBody->setVelocity(Vec2(vx,vy));
    this->setPhysicsBody(ballBody);
    
    
}