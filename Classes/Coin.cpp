//
//  Coin.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/23/15.
//
//

#include "Coin.h"
#include "Constants.h"

using namespace cocos2d;
bool Coin::init()
{
    if (! Sprite::initWithFile("coin.png")) {
        return false;
    }
    
    return true;
}

void Coin::initCollision()
{
    PhysicsBody* coinBody = PhysicsBody::createCircle(this->getContentSize().width/2 ,DEFAULT_COIN_MATERIAL);
    coinBody->setContactTestBitmask(COIN_INIT_CONTACT_MARK);
    coinBody->setCategoryBitmask(COIN_CATEGORY);
    coinBody->setCollisionBitmask(COIN_INIT_COLLISION_MASK);
    coinBody->setGravityEnable(false);
    this->setPhysicsBody(coinBody);
}

void Coin::runGetCoinAnimation()
{
    _action = Spawn::create(
                            RotateBy::create(0.5f, Vec3(0, 1080, 0)),
                            MoveBy::create(0.5f, Vec2(0,50)),
                            FadeOut::create(0.5f),
                            nullptr);
    this->runAction(Sequence::create(_action, RemoveSelf::create(),nullptr));
}

void Coin::runAppearAnimation()
{
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());
    std::uniform_int_distribution<> dist(-100,100);
    Vec2 newPos = Vec2(dist(engine),dist(engine)) + this->getPosition();
    
    _action = Spawn::create(
                            JumpTo::create(0.5, newPos, 30, 1),
                            FadeTo::create(0.5f,128),
                            nullptr);
    this->runAction(_action);
}

void Coin::enableCollision()
{
    this->setOpacity(255);
    this->getPhysicsBody()->setCollisionBitmask(COIN_RUNNING_COLLISION_MASK);
    this->getPhysicsBody()->setContactTestBitmask(COIN_RUNNING_CONTACT_MARK);
}