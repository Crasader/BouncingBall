//
//  PassCode.h
//  BouncingBall
//
//  Created by Liang Fan on 7/23/15.
//
//

#ifndef __BouncingBall__PassCode__
#define __BouncingBall__PassCode__

#include "cocos2d.h"
#include "Constants.h"

class PassCode : public cocos2d::Node
{
public:
    static PassCode* createWithStr(std::string str);
    BallColor getCurrentPassCodeColor();
    bool isPassCodeClear();
    bool EnterOneColor(BallColor color);
    void resetPassCode();

    
private:
    bool initWithPassCode(std::string str);
    int _currentPassCodePos;
    void turnOnCurrentColor();
                                 
    cocos2d::Vector<cocos2d::Sprite*> _passCode;
    std::vector<BallColor> _passCodeColor;
};

#endif /* defined(__BouncingBall__PassCode__) */
