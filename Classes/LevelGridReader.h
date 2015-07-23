//
//  LevelGridReader.h
//  BouncingBall
//
//  Created by Liang Fan on 7/24/15.
//
//

#ifndef __BouncingBall__LevelGridReader__
#define __BouncingBall__LevelGridReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class LevelGridReader : public cocostudio::NodeReader
{
public:
    static LevelGridReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__BouncingBall__LevelGridReader__) */
