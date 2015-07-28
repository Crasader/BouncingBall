//
//  ExplodeReader.h
//  BouncingBall
//
//  Created by Liang Fan on 7/27/15.
//
//

#ifndef __BouncingBall__ExplodeReader__
#define __BouncingBall__ExplodeReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class ExplodeReader : public cocostudio::NodeReader {
public:
    static ExplodeReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__BouncingBall__Explode__) */
