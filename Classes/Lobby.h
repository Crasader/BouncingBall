//
//  Lobby.h
//  BouncingBall
//
//  Created by Liang Fan on 7/15/15.
//
//

#ifndef __BouncingBall__Lobby__
#define __BouncingBall__Lobby__

#include "cocos2d.h"
#include "CocosGUI.h"

class Lobby : public cocos2d::Node
{
public:
    CREATE_FUNC(Lobby);

private:
    bool init() override;
    void onEnter() override;
    void setupUI();
    void SinglePlayerPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void multiplayerPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void specialThankPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__BouncingBall__Lobby__) */
