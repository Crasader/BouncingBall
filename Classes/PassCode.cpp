//
//  PassCode.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/23/15.
//
//

#include "PassCode.h"
using namespace cocos2d;

PassCode* PassCode::createWithStr(std::string str)
{
    PassCode* passCode = new (std::nothrow) PassCode();
    if (passCode && passCode->initWithPassCode(str)) {
        passCode->autorelease();
        return passCode;
    } else {
        CC_SAFE_DELETE(passCode);
        return nullptr;
    }
}
bool PassCode::initWithPassCode(std::string str)
{
    if (! Node::init()) {
        return false;
    }
    
    for (int i=0; i < str.size(); ++i) {
        std::string fileName;
        BallColor color;
        switch (str[i]) {
            case 'r':
                fileName = "red.png";
                color = BallColor::red;
                break;
            case 'g':
                fileName = "green.png";
                color = BallColor::green;
                break;
            case 'b':
                fileName = "blue.png";
                color = BallColor::blue;
                break;
        }
        Sprite* passCodePiece = Sprite::create(fileName);
        float width = passCodePiece->getContentSize().width * float(i);
        passCodePiece->setPosition(width,0.0f);
        //FIXME: magic number
        passCodePiece->setOpacity(100);
        this->addChild(passCodePiece);
        
        _passCode.pushBack(passCodePiece);
        _passCodeColor.push_back(color);
    }
    _currentPassCodePos = 0;
    
    return true;
}


bool PassCode::isPassCodeClear()
{
    return _currentPassCodePos >= _passCode.size();
}

BallColor PassCode::getCurrentPassCodeColor()
{
    return _passCodeColor[_currentPassCodePos];
}

bool PassCode::EnterOneColor(BallColor color)
{
    if (isPassCodeClear()) {
        return false;
    }
    
    if(getCurrentPassCodeColor() == color) {
        turnOnCurrentColor();
        _currentPassCodePos++;
        return true;
    }
    return false;
}

void PassCode::turnOnCurrentColor()
{
    _passCode.at(_currentPassCodePos)->setOpacity(255);
}
