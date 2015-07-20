//
//  Constants.h
//  BouncingBall
//
//  Created by Liang Fan on 7/14/15.
//
//

#ifndef BouncingBall_Constants_h
#define BouncingBall_Constants_h

#include "cocos2d.h"

#pragma mark Ball Setting
const static float MIN_SPEED = 2.2f;
const static float BALL_DEFAULT_LINEAR_DAMPING = 0.5f;
const static cocos2d::PhysicsMaterial DEFAULT_BALL_MATERIAL = cocos2d::PhysicsMaterial(0.0f, 1.0f, 0.0f);
const static int BALL_DEFAULT_HP = 3;
const static float MAX_SHOOTING_SPEED = 1000.0f;



#pragma Collusion Setting
//TODO: add other colors, butfirst use three color
const static int BALL_CATEGORY = 0x01;
const static int BLOCK_CATEGORY = 0x02;


const static int BALL_CULLISION_MASK = BALL_CATEGORY | BLOCK_CATEGORY;
const static int BALL_CONTACT_MASK = BALL_CATEGORY | BLOCK_CATEGORY;
//TODO maybe color should be a tag


enum class GameState
{
    prepareShooting,
    shooting
};
enum class BallColor
{
    red = 0,
    green = 1,
    blue = 2,
    purple = 3,
    yellow = 4,
    black =5
};

enum Category
{
    ball = 0x001, // 00000001
    maximizing = 0x02, // 00000010
    minimized  = 0x04, // 00000100
    maximized  = 0x08  // 00001000
};


#endif
