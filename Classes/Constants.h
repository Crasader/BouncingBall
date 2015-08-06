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
const static float MIN_SPEED = 2.0f;
const static float BALL_DEFAULT_LINEAR_DAMPING = 1.2f;
const static cocos2d::PhysicsMaterial DEFAULT_BALL_MATERIAL = cocos2d::PhysicsMaterial(0.0f, 0.9f, 0.0f);
const static int BALL_DEFAULT_HP = 2;
const static int BALL_INFINITY_HP = 99;
const static float MAX_SHOOTING_SPEED = 1500.0f;

const static float BOMB_RANGE = 100.0f;
const static float BOMB_SPEED = 1000.0f;

const static int COIN_NUMS_IF_ITEM_IS_GETTED = 5;

const static bool DEBUG_MODE = true;

const static int BASIC_LEVEL_NUMS = 0;

#pragma mark -
#pragma mark Edge Setting
const static cocos2d::PhysicsMaterial EDGE_MATERIAL = cocos2d::PhysicsMaterial(0.0f, 1.0f, 0.0f);

const static cocos2d::PhysicsMaterial DEFAULT_ROCK_MATERIAL = cocos2d::PhysicsMaterial(0.0f, 1.0f, 0.0f);

const static cocos2d::PhysicsMaterial DEFAULT_COIN_MATERIAL = cocos2d::PhysicsMaterial(0.0f, 0.0f, 1.0f);

const static cocos2d::Vec2 TRANSPORT_INIT_POS = cocos2d::Vec2(100,400);

#pragma Collusion Setting
//TODO: add other colors, butfirst use three color
const static int NONE = 0x00;
const static int BALL_CATEGORY = 0x01;
const static int ROCK_CATEGORY = 0x02;
const static int EDGE_CATEGORY = 0x04;
const static int COIN_CATEGORY = 0x08;
const static int BOMB_CATEGORY = 0x10;
const static int TRANSPORT_CATEGORY = 0x20;

const static int BOMB_COLLISION_MASK = EDGE_CATEGORY;
const static int BOMB_CONTACT_MASK = BALL_CATEGORY | ROCK_CATEGORY | EDGE_CATEGORY | COIN_CATEGORY | TRANSPORT_CATEGORY;

const static int BALL_COLLISION_MASK = BALL_CATEGORY | ROCK_CATEGORY | EDGE_CATEGORY | COIN_CATEGORY ;
const static int BALL_CONTACT_MASK = BALL_CATEGORY | ROCK_CATEGORY | EDGE_CATEGORY | COIN_CATEGORY | BOMB_CATEGORY | TRANSPORT_CATEGORY;

const static int ROCK_COLLISION_MASK = BALL_CATEGORY | COIN_CATEGORY;
const static int ROCK_CONTACT_MASK = BALL_CATEGORY  | BOMB_CATEGORY;

const static int COIN_INIT_COLLISION_MASK = ROCK_CATEGORY;
const static int COIN_INIT_CONTACT_MARK = BOMB_CATEGORY;

const static int COIN_RUNNING_COLLISION_MASK = NONE ;
const static int COIN_RUNNING_CONTACT_MASK = BALL_CATEGORY | BOMB_CATEGORY;

const static int EDGE_INIT_CULLISION_MASK = NONE;
const static int EDGE_INIT_CONTACT_MASK = BALL_CATEGORY | BOMB_CATEGORY;

const static int EDGE_RUNNING_CULLISION_MASK = BALL_CATEGORY | BOMB_CATEGORY;
const static int EDGE_RUNNING_CONTACT_MASK = NONE;

const static int TRANSPORT_CULLISION_MASK = NONE;
const static int TRANSPORT_CONTACT_MASK = BALL_CATEGORY | BOMB_CATEGORY;

const static int LOCKED_LEVEL = -1;
const static int UNLOCKED_LEVEL = 0;

const static int COIN_WILL_NOT_BE_CREATED_IN_NEXT_TURN = 1;
const static int CREADTED_COIN_NUMS_WHEN_BALL_HP_IS_ZERO = 3;

const static int TUTORIAL_CRACKED_BALL = 1;

const static int BALL_HIT_COIN = BALL_CATEGORY | COIN_CATEGORY;
const static int BALL_HIT_TRANSPORT = BALL_CATEGORY | TRANSPORT_CATEGORY;

enum class GameState
{
    sendDeviceName, //only multi
    prepareShooting,
    pause,
    shooting,
    gameOver,
    createItem,
    creatingItem,
    usingBomb,
    shootingBomb,
    bombFinish,
    usingThunder,
    shootingByThunder,
    usingTransport,
    finishSettingTransport,
    usingCoin,
    waiting,         //only multi
    waitForSimulate,   //only multi
    waitForFinish,
    tutorial,
    
    //only for multiPlay
};

enum class TutorialStep
{
    initInfo,
    swipingCannon,
    shootball,
    shooting,
    sameColor,
    ballCrack,
    createCoin,
    collectCoin,
    collectCoinShooting,
    itemInitInfo,
    generateItem,
    creatingItem,
    usingItem,
    dragTransport,
    finishUsingTransport,
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

// the sequnce of item is related to animation,take careful to change it
enum class ItemCategory
{
    bomb = 0,
    coin = 1,
    thunder = 2,
    transport= 3,
    none = 4,
};



#endif
