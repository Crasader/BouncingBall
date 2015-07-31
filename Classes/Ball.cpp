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
    if(abs(velocity.x) < MIN_SPEED && abs(velocity.y) < MIN_SPEED) {
        this->getPhysicsBody()->setVelocity(Vec2(0.0f,0.0f));
        return true;
    } else {
        return false;
    }
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

Ball* Ball::createWithColor(std::string color)
{
    Ball* ball = new (std::nothrow) Ball();
    if (ball && ball->initWithColor(color)) {
        ball->autorelease();
        return ball;
    } else {
        CC_SAFE_DELETE(ball);
        return nullptr;
    }
}


bool Ball::initWithColor(std::string color)
{
    std::string fileName = color + ".png";
    if (! Sprite::initWithFile(fileName)) {
        return false;
    }
    this->_hp = BALL_DEFAULT_HP;
    this->_color = getBallColorFromStr(color);
    auto ballBody = createBallPhysicsBody(_color);
    this->setPhysicsBody(ballBody);
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
    ballBody->setCollisionBitmask(BALL_COLLISION_MASK);
    return ballBody;
}

void Ball::gotHit()
{
    _hp--;
    if (_hp == 1) {
        auto crack = Sprite::create("crack.png");
        crack->setAnchorPoint(Vec2(0.5,0.5));
        crack->setPosition(this->getContentSize()/2);
        this->addChild(crack);
    }

}

BallColor Ball::getBallColor() const
{
    return _color;
}
void Ball::setHp(int hp)
{
    _hp = hp;
}

int Ball::getHp()
{
    return _hp;
}

std::string Ball::getBallFileName()
{
    switch (_color) {
        case BallColor::red:
            return "red.png";
            break;
        case BallColor::green:
            return "green.png";
        case BallColor::blue:
            return "blue.png";
    }
}
