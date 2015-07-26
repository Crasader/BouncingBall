//
//  BallExplode.h
//  BouncingBall
//
//  Created by Liang Fan on 7/27/15.
//
//

#ifndef __BouncingBall__BallExplode__
#define __BouncingBall__BallExplode__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

class BallExplode : public cocos2d::Node {
public:
    CREATE_FUNC(BallExplode);
    bool init() override;
    void onExit() override;
    void runExplodeAnimation();

protected:
    cocostudio::timeline::ActionTimeline* _timeline;

};

#endif /* defined(__BouncingBall__BallExplode__) */
