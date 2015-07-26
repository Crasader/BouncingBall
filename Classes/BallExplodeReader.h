//
//  BallExplodeReader.h
//  BouncingBall
//
//  Created by Liang Fan on 7/27/15.
//
//

#ifndef __BouncingBall__BallExplodeReader__
#define __BouncingBall__BallExplodeReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class BallExplodeReader : public cocostudio::NodeReader {
public:
    static BallExplodeReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__BouncingBall__BallExplode__) */
