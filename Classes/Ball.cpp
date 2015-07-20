//
//  Ball.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/15/15.
//
//

#include "Ball.h"
#include "Constants.h"
using namespace cocos2d;

bool Ball::isStoped()
{
    Vec2 velocity = this->getPhysicsBody()->getVelocity();
    return (abs(velocity.x) < MIN_SPEED && abs(velocity.y) < MIN_SPEED);
}
void Ball::shoot(float speed, float angle)
{
    auto ballBody = this->getPhysicsBody();
    float vx = sin(angle * M_PI / 180) * speed;
    float vy = cos(angle * M_PI / 180) * speed;
    ballBody->setVelocity(Vec2(vx,vy));
    this->setPhysicsBody(ballBody);
    
}


#pragma mark -
#pragma mark initialze

bool Ball::init()
{
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());
    std::uniform_int_distribution<> dist(0, 2);
    std::string fileName;
    switch (dist(engine)) {
        case 0:
        {
            this->_color = BallColor::red;
            fileName = "red.png";
        }
            break;
        case 1:
        {
            this->_color = BallColor::blue;
            fileName = "blue.png";
        }
            break;
        case 2:
        {
            this->_color = BallColor::green;
            fileName = "green.png";
        }
            break;
    }
    
    if (! Sprite::initWithFile(fileName)) {
        return false;
    }
    this->_hp = BALL_DEFAULT_HP;
    auto ballBody = createBallPhysicsBody(_color);
    this->setPhysicsBody(ballBody);
    
    return true;
}

Ball* Ball::createWithBallConfig(JSONPacker::BallConfig config)
{
    Ball* ball = new (std::nothrow) Ball();
    if (ball && ball->initWithBallConfig(config)) {
        ball->autorelease();
        return ball;
    } else {
        CC_SAFE_DELETE(ball);
        return nullptr;
    }
}

bool Ball::initWithBallConfig(JSONPacker::BallConfig config)
{
    std::string fileName = config.color + ".png";
    if (! Sprite::initWithFile(fileName)) {
        return false;
    }
    this->_hp = config.hp;
    this->_color = getBallColorFromStr(config.color);
    auto ballBody = createBallPhysicsBody(_color);
    this->setPhysicsBody(ballBody);
    this->setNormalizedPosition(Vec2(config.relativeX, config.relativeY));
    return true;
}

#pragma mark -
#pragma mark Util Method
BallColor Ball::getBallColorFromStr(std::string color)
{
    if (color.compare("red") == 0) {
        return BallColor::red;
    } else if (color.compare("blue") == 0) {
        return BallColor::blue;
    } else if (color.compare("green") == 0) {
        return BallColor::green;
    } else if (color.compare("yellow") == 0) {
        return BallColor::yellow;
    } else if (color.compare("purple") == 0) {
        return BallColor::purple;
    } else {
        return BallColor::black;
    }
}

PhysicsBody* Ball::createBallPhysicsBody(BallColor color)
{
    PhysicsBody* ballBody = PhysicsBody::createCircle(this->getContentSize().width/2 ,DEFAULT_BALL_MATERIAL);
    ballBody->setGravityEnable(false);
    ballBody->setLinearDamping(BALL_DEFAULT_LINEAR_DAMPING);
    ballBody->setContactTestBitmask(BALL_CONTACT_MASK);
    ballBody->setCategoryBitmask(BALL_CATEGORY);
    ballBody->setCollisionBitmask(BALL_CULLISION_MASK);
    ballBody->setTag(static_cast<int>(color));
    return ballBody;
}
