//
//  Transport.h
//  BouncingBall
//
//  Created by Liang Fan on 8/4/15.
//
//

#ifndef __BouncingBall__Transport__
#define __BouncingBall__Transport__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

class Transport : public cocos2d::Node {
public:
    CREATE_FUNC(Transport);
    void syncTransportPos(cocos2d::Vec2 pos, cocos2d::Vec2 circle1Pos, cocos2d::Vec2 circle2Pos);
    bool init() override;
    void onExit() override;
    void runTransportAnimation();
    void enableTransport();
    Sprite* getTouchedCircle(cocos2d::Vec2 pos) const;
    void enableOKButton();
    void disableOKButton();
    bool isReady() const;
    void onEnter() override;
    cocos2d::Vec2 getOriginTransportPos() const;
    cocos2d::Vec2 getTransportPos() const;

protected:
    cocostudio::timeline::ActionTimeline* _timeline;
    
    cocos2d::Sprite* _circle1;
    cocos2d::Sprite* _circle2;
    ui::Button* _button1;
    ui::Button* _button2;
    bool _circle1Setted;
    bool _circle2Setted;

};

#endif /* defined(__BouncingBall__Transport__) */
