//
//  TapInfo.cpp
//  BouncingBall
//
//  Created by Liang Fan on 8/6/15.
//
//

#include "TapInfo.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

bool TapInfo::init()
{
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 200))) {
        return false;
    }

    return true;
}

#pragma mark -
#pragma mark View lifecycle

void TapInfo::onEnter()
{
    LayerColor::onEnter();
    this->setOpacity(100);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(TapInfo::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(TapInfo::onTouchEnd, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

/* default height = 600*/
void TapInfo::displayInfo(const std::vector<std::string> &infoList,float startHeight)
{
    Vec2 startPos = Vec2(320,startHeight);
    float lineInterval = 50;
    
    for (int i=0;i < infoList.size();++i) {
        ui::TextBMFont* line = ui::TextBMFont::create(infoList[i], "font01.fnt");
        line->setAnchorPoint(Vec2(0.5,0.5));
        line->setPosition(startPos - Vec2(0,lineInterval * i));
        line->setScale(0.7);
        this->addChild(line);
    };
}

bool TapInfo::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return true;
}

void TapInfo::onTouchEnd(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    this->runAction(Sequence::create(
                                     FadeOut::create(0.3f),
                                     RemoveSelf::create(),
                                     NULL
                                     ));
}