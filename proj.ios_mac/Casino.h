//
//  Casino.h
//  BouncingBall
//
//  Created by Liang Fan on 8/6/15.
//
//

#ifndef __BouncingBall__Casino__
#define __BouncingBall__Casino__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "Constants.h"

class Casino : public cocos2d::Node {
public:
    CREATE_FUNC(Casino);
    bool init() override;
    void onExit() override;
    void runCreateItemAnimation(ItemCategory item, CallFunc* callbackFunc);

protected:
    cocostudio::timeline::ActionTimeline* _timeline;

};

#endif /* defined(__BouncingBall__Casino__) */
