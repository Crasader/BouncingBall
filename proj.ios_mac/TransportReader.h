//
//  TransportReader.h
//  BouncingBall
//
//  Created by Liang Fan on 8/4/15.
//
//

#ifndef __BouncingBall__TransportReader__
#define __BouncingBall__TransportReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class TransportReader : public cocostudio::NodeReader {
public:
    static TransportReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__BouncingBall__Transport__) */
