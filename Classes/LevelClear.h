//
//  LevelClear.h
//  BouncingBall
//
//  Created by Liang Fan on 7/24/15.
//
//

#ifndef __BouncingBall__LevelClear__
#define __BouncingBall__LevelClear__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"

class LevelClear : public cocos2d::Node {
public:
    CREATE_FUNC(LevelClear);
    bool init() override;
    void runLevelClearAnimation(int starNums);

protected:
    void onExit() override;
    cocostudio::timeline::ActionTimeline* _timeline;

};

#endif /* defined(__BouncingBall__LevelClear__) */
