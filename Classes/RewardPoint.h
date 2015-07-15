//
//  RewardPoint.h
//  BouncingBall
//
//  Created by Liang Fan on 7/16/15.
//
//

#ifndef __BouncingBall__RewardPoint__
#define __BouncingBall__RewardPoint__

class RewardPoint : public cocos2d::Node
{
public:
    void onEnter() override;
    CREATE_FUNC(RewardPoint);
    void setupPhysics();
private:
    int points;

};

#endif /* defined(__BouncingBall__RewardPoint__) */
