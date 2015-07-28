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
const static float MIN_SPEED = 5.0f;
const static float BALL_DEFAULT_LINEAR_DAMPING = 1.2f;
const static cocos2d::PhysicsMaterial DEFAULT_BALL_MATERIAL = cocos2d::PhysicsMaterial(0.0f, 1.0f, 0.0f);
const static int BALL_DEFAULT_HP = 2;
const static int BALL_INFINITY_HP = 99;
const static float MAX_SHOOTING_SPEED = 2000.0f;

const static float BOMB_RANGE = 100.0f;
const static float BOMB_SPEED = 1000.0f;

#pragma mark -
#pragma mark Edge Setting
const static cocos2d::PhysicsMaterial EDGE_MATERIAL = cocos2d::PhysicsMaterial(0.0f, 1.0f, 0.0f);

const static cocos2d::PhysicsMaterial DEFAULT_ROCK_MATERIAL = cocos2d::PhysicsMaterial(0.0f, 1.0f, 0.0f);

const static cocos2d::PhysicsMaterial DEFAULT_COIN_MATERIAL = cocos2d::PhysicsMaterial(0.0f, 0.0f, 1.0f);



#pragma Collusion Setting
//TODO: add other colors, butfirst use three color
const static int NONE = 0x00;
const static int BALL_CATEGORY = 0x01;
const static int ROCK_CATEGORY = 0x02;
const static int EDGE_CATEGORY = 0x04;
const static int COIN_CATEGORY = 0x08;
const static int BOMB_CATEGORY = 0x10;

const static int BOMB_COLLISION_MASK = EDGE_CATEGORY;
const static int BOMB_CONTACT_MASK = BALL_CATEGORY | ROCK_CATEGORY | EDGE_CATEGORY;

const static int BALL_COLLISION_MASK = BALL_CATEGORY | ROCK_CATEGORY | EDGE_CATEGORY | COIN_CATEGORY ;
const static int BALL_CONTACT_MASK = BALL_CATEGORY | ROCK_CATEGORY | EDGE_CATEGORY | COIN_CATEGORY | BOMB_CATEGORY;

const static int ROCK_COLLISION_MASK = BALL_CATEGORY | COIN_CATEGORY;
const static int ROCK_CONTACT_MASK = BALL_CATEGORY  | BOMB_CATEGORY;

const static int COIN_INIT_COLLISION_MASK = COIN_CATEGORY | EDGE_CATEGORY | ROCK_CATEGORY;
const static int COIN_INIT_CONTACT_MARK = NONE;

const static int COIN_RUNNING_COLLISION_MASK = NONE ;
const static int COIN_RUNNING_CONTACT_MASK = BALL_CATEGORY | BOMB_CATEGORY;

const static int EDGE_INIT_CULLISION_MASK = COIN_CATEGORY;
const static int EDGE_INIT_CONTACT_MASK = BALL_CATEGORY | BOMB_CATEGORY;

const static int EDGE_RUNNING_CULLISION_MASK = BALL_CATEGORY | COIN_CATEGORY | BOMB_CATEGORY;
const static int EDGE_RUNNING_CONTACT_MASK = NONE;

const static int LOCKED_LEVEL = -1;
const static int UNLOCKED_LEVEL = 0;

//TODO maybe color should be a tag


enum class GameState
{
    prepareShooting,
    shooting,
    gameOver,
    usingBomb,
    shootingBomb,
    bombFinish,
};
enum class MultiplayState
{
    sendDeviceName,
    wait,
    shooting,
    gameOver
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

enum ItemCategory
{
    ballBox,
    bomb,
    aim,
    none
};



#endif
