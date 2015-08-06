//
//  TapInfo.h
//  BouncingBall
//
//  Created by Liang Fan on 8/6/15.
//
//

#ifndef __BouncingBall__TapInfo__
#define __BouncingBall__TapInfo__

#include "cocos2d.h"

class TapInfo : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(TapInfo);
    void displayInfo(const std::vector<std::string>& infoList);

private:
    bool init() override;
    void onEnter() override;
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchEnd(cocos2d::Touch *touch, cocos2d::Event *event);

};

#endif /* defined(__BouncingBall__TapInfo__) */
