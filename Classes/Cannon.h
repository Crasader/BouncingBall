//
//  Cannon.h
//  BouncingBall
//
//  Created by Liang Fan on 7/17/15.
//
//

#ifndef __BouncingBall__Cannon__
#define __BouncingBall__Cannon__

#include "cocos2d.h"
#include "Constants.h"
#include "cocostudio/CocoStudio.h"

class Ball;

class Cannon : public cocos2d::Node
{
public:
    CREATE_FUNC(Cannon);
    bool init() override;
    void onExit() override;
    void runShootingAnimation();
    void rotate(float cocosAngle);
    float getAngle();
    void setAngle(float angle);
protected:
    cocostudio::timeline::ActionTimeline* _timeline;
    
    
    
};

#endif /* defined(__BouncingBall__Cannon__) */
