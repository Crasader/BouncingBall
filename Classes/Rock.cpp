//
//  Rock.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/28/15.
//
//

#include "Rock.h"
#include "Constants.h";

USING_NS_CC;

bool Rock::init()
{
    if (!Sprite::initWithFile("rock.png"))
    {
        return false;
    }
    
    PhysicsBody* rockBody = PhysicsBody::createBox(this->getContentSize(), PhysicsMaterial(DEFAULT_ROCK_MATERIAL));
    rockBody->setDynamic(false);
    rockBody->setContactTestBitmask(ROCK_CONTACT_MASK);
    rockBody->setCategoryBitmask(ROCK_CATEGORY);
    rockBody->setCollisionBitmask(ROCK_COLLISION_MASK);
    rockBody->setGravityEnable(false);
    this->setPhysicsBody(rockBody);
    
    return true;
}

#pragma mark - View lifecycle

void Rock::onEnter()
{
    Sprite::onEnter();
}

void Rock::onExit()
{
    Sprite::onExit();
}
