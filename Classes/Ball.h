//
//  Ball.h
//  BouncingBall
//
//  Created by Liang Fan on 7/15/15.
//
//

#ifndef __BouncingBall__Ball__
#define __BouncingBall__Ball__

#include "cocos2d.h"
#include "Constants.h"
#include "JSONPacker.h"

class Ball : public cocos2d::Sprite
{
public:
    static Ball* createWithColor(std::string color);
    static Ball* createRandomBall();
    bool init() override;
    void shoot(float speed, float angle);
    bool isStoped();
    CREATE_FUNC(Ball);
    void runDestroyAnimation();
    void gotHit();
    void setHp(int hp);
    int getHp();
    std::string getBallFileName();
    BallColor getBallColor() const;

private:
    int _hp;
    BallColor _color;
    bool initWithColor(std::string color);
    BallColor getBallColorFromStr(std::string color);
    cocos2d::PhysicsBody* createBallPhysicsBody(BallColor color);

};

#endif /* defined(__BouncingBall__Ball__) */
