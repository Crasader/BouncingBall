//
//  Dogi.h
//  BouncingBall
//
//  Created by Liang Fan on 7/23/15.
//
//

#ifndef __BouncingBall__Dogi__
#define __BouncingBall__Dogi__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

class Dogi : public cocos2d::Node
{
public:
    CREATE_FUNC(Dogi);
    bool init() override;
    void onExit() override;
    void runShootingAnimation();
    void runWinAnimation();
    
protected:
    cocostudio::timeline::ActionTimeline* _timeline;
    
};

#endif /* defined(__BouncingBall__Dogi__) */
