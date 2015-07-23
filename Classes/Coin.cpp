//
//  Coin.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/23/15.
//
//

#include "Coin.h"
using namespace cocos2d;
bool Coin::init()
{
    if (! Sprite::initWithFile("coin.png")) {
        return false;
    }
    _action = Spawn::create(
                            RotateBy::create(0.5f, Vec3(0, 1080, 0)),
                            MoveBy::create(0.5f, Vec2(0,50)),
                            FadeOut::create(0.5f),
                            nullptr);
    return true;
}

void Coin::runGetCoinAnimation()
{
    this->runAction(Sequence::create(_action, RemoveSelf::create(),nullptr));
}