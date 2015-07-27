//
//  Rock.h
//  BouncingBall
//
//  Created by Liang Fan on 7/28/15.
//
//

#ifndef __BouncingBall__Rock__
#define __BouncingBall__Rock__

#include "cocos2d.h"

class Rock : public cocos2d::Sprite
{
public:
    CREATE_FUNC(Rock);

private:
    bool init() override;
    void onEnter() override;
    void onExit() override;

};

#endif /* defined(__BouncingBall__Rock__) */
