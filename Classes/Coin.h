//
//  Coin.h
//  BouncingBall
//
//  Created by Liang Fan on 7/23/15.
//
//

#ifndef __BouncingBall__Coin__
#define __BouncingBall__Coin__

#include "cocos2d.h"

class Coin : public cocos2d::Sprite
{
public:
    CREATE_FUNC(Coin);
    void runGetCoinAnimation();
    void runAppearAnimation(cocos2d::Vec2 newPos,bool enable = false);
    void enableCollision();
    void initCollision();
    void runItemCoinAnimation();
private:
    bool init() override;
    cocos2d::Spawn* _action;
    
};
#endif /* defined(__BouncingBall__Coin__) */
