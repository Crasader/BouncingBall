//
//  LevelSelect.h
//  BouncingBall
//
//  Created by Liang Fan on 7/24/15.
//
//

#ifndef __BouncingBall__LevelSelect__
#define __BouncingBall__LevelSelect__

#include "cocos2d.h"
#include "CocosGUI.h"

class LevelSelect : public cocos2d::Node
{
public:
    CREATE_FUNC(LevelSelect);
    
private:
    void loadUserData();
    void onEnter() override;
    void levelButtonPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__BouncingBall__LevelSelect__) */
