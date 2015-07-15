//
//  RewardPointReader.h
//  BouncingBall
//
//  Created by Liang Fan on 7/16/15.
//
//

#ifndef __BouncingBall__RewardPointReader__
#define __BouncingBall__RewardPointReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class RewardPointReader : public cocostudio::NodeReader
{
public:
    static RewardPointReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__BouncingBall__RewardPointReader__) */
