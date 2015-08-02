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

//FINISH REFACTORING 8/3
class Ball : public cocos2d::Sprite
{
public:
    //init Method
    static Ball* createWithColor(std::string color);
    CREATE_FUNC(Ball);

    //Ball Game Logic
    void shoot(float speed, float angle);
    void gotHit();
    void addCrack();
    bool isStoped() const;
    void stop();
    
    //Getter Setter
    void setHp(int hp);
    int getHp() const;
    BallColor getBallColor() const;
    std::string getBallFileName() const;
    BallColor getBallColorFromStr(std::string color);

private:
    int _hp;
    BallColor _color;
    
    //init Method
    bool initWithColor(std::string color);
    bool init() override;
    cocos2d::PhysicsBody* createBallPhysicsBody(BallColor color);

};

#endif /* defined(__BouncingBall__Ball__) */
