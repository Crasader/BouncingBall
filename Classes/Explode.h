//
//  Explode.h
//  BouncingBall
//
//  Created by Liang Fan on 7/27/15.
//
//

#ifndef __BouncingBall__Explode__
#define __BouncingBall__Explode__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

class Explode : public cocos2d::Node {
public:
    CREATE_FUNC(Explode);
    bool init() override;
    void onExit() override;
    void runBallExplodeAnimation();
    void runBombExplodeAnimation();

protected:
    cocostudio::timeline::ActionTimeline* _timeline;

};

#endif /* defined(__BouncingBall__Explode__) */
