//
//  Ball.h
//  BouncingBall
//
//  Created by Liang Fan on 7/15/15.
//
//

#ifndef __BouncingBall__Ball__
#define __BouncingBall__Ball__

#include "cocos2d.h"
#include "Constants.h"

class Ball : public cocos2d::Sprite
{
public:
    bool init() override;
    CREATE_FUNC(Ball);
    void setVelocity(cocos2d::Vec2 velocity);
private:


};

#endif /* defined(__BouncingBall__Ball__) */
