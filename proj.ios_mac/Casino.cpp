//
//  Casino.cpp
//  BouncingBall
//
//  Created by Liang Fan on 8/6/15.
//
//

#include "Casino.h"

bool Casino::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->_timeline = CSLoader::createTimeline("Casino.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->_timeline->retain();

    return true;
}

void Casino::onExit()
{
    _timeline->release();
    Node::onExit();
}

void Casino::runCreateItemAnimation(ItemCategory item, CallFunc* callbackFunc)
{
    this->stopAllActions();
    this->runAction(_timeline);
    CallFunc* play = CallFunc::create([&](){
        _timeline->play("create",true);
    });

    CallFunc* stop = CallFunc::create([this,item](){
        _timeline->stop();
        int frameIndex = static_cast<int>(item) + 1;
        _timeline->gotoFrameAndPlay(frameIndex, frameIndex, false);

    });
    this->runAction(Sequence::create(play, DelayTime::create(1.5f),stop,DelayTime::create(0.5f),callbackFunc,RemoveSelf::create(),nullptr));
}

