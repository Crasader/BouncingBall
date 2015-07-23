//
//  DogiReader.h
//  BouncingBall
//
//  Created by Liang Fan on 7/23/15.
//
//

#ifndef __BouncingBall__DogiReader__
#define __BouncingBall__DogiReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class DogiReader : public cocostudio::NodeReader
{
public:
    static DogiReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__BouncingBall__DogiReader__) */
