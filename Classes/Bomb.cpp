//
//  Bomb.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/28/15.
//
//

#include "Bomb.h"

USING_NS_CC;

bool Bomb::init()
{
    if (!Sprite::initWithFile("bomb.png"))
    {
        return false;
    }

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
