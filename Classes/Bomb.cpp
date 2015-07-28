//
//  Bomb.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/28/15.
//
//

#include "Bomb.h"
#include "Constants.h"

USING_NS_CC;

bool Bomb::init()
{
    if (!Sprite::initWithFile("bomb.png"))
    {
        return false;
    }

    PhysicsBody* bombBody = PhysicsBody::createCircle(this->getContentSize().width/2);
    bombBody->setGravityEnable(false);
    bombBody->setContactTestBitmask(BOMB_CONTACT_MASK);
    bombBody->setCategoryBitmask(BOMB_CATEGORY);
    bombBody->setCollisionBitmask(BOMB_COLLISION_MASK);
    this->setPhysicsBody(bombBody);
    
    return true;
}

#pragma mark - View lifecycle

void Bomb::onEnter()
{
    Sprite::onEnter();
}

void Bomb::onExit()
{
    Sprite::onExit();
}

void Bomb::shoot(float speed, float angle)
{
    auto bombBody = this->getPhysicsBody();
    float vx = sin(angle * M_PI / 180) * speed;
    float vy = cos(angle * M_PI / 180) * speed;
    bombBody->setVelocity(Vec2(vx,vy));
    this->setPhysicsBody(bombBody);
    
}

Rect Bomb::getBombRange()
{
    Vec2 pos = this->getPosition();
    Size size = this->getContentSize();
    
    return Rect(pos.x-BOMB_RANGE, pos.y-BOMB_RANGE, BOMB_RANGE * 2, BOMB_RANGE * 2);
}