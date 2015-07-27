//
//  Bomb.h
//  BouncingBall
//
//  Created by Liang Fan on 7/28/15.
//
//

#ifndef __BouncingBall__Bomb__
#define __BouncingBall__Bomb__

#include "cocos2d.h"

class Bomb : public cocos2d::Sprite
{
public:
    CREATE_FUNC(Bomb);

private:
    bool init() override;
    void onEnter() override;
    void onExit() override;

};

#endif /* defined(__BouncingBall__Bomb__) */
