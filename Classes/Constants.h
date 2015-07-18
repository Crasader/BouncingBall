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

//TODO: change this to % of the screen

const static float MIN_SPEED = 2.2f;

enum class SurfaceType
{
    sand,
    water
};
enum class GameState
{
    prepareShooting,
    shooting
};

//TODO: bitmask defination
/*
 4 basic category: surface,points,block,ball
 when ball pass surface is speed changed
 when ball pass the points user get points
 when ball hit the block collusion happend
 
 ball is dynamic(movable)
 ball can detect collusion of surface,points,block,ball
 ball can collise block,ball
 
 block is dynamic(movable)
 block can detect block,ball
 block can colliose block,ball
 
 */
enum Category
{
    ball = 0x001, // 00000001
    maximizing = 0x02, // 00000010
    minimized  = 0x04, // 00000100
    maximized  = 0x08  // 00001000
};


#endif
