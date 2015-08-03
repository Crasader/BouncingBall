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
    bool init() override;
    void onExit() override;
    void runTransportAnimation();
    void enableTransport();
    Sprite* getTouchedCircle(cocos2d::Vec2 pos);
    void enableOKButton();
    void disableOKButton();
    bool isReady();
    void onEnter() override;

protected:
    PhysicsBody* createPhysicsBody();
    cocostudio::timeline::ActionTimeline* _timeline;
    
    cocos2d::Sprite* _circle1;
    cocos2d::Sprite* _circle2;
    ui::Button* _button1;
    ui::Button* _button2;
    bool _circle1Setted;
    bool _circle2Setted;

};

#endif /* defined(__BouncingBall__Transport__) */
