//
//  ItemBoxReader.h
//  BouncingBall
//
//  Created by Liang Fan on 7/28/15.
//
//

#ifndef __BouncingBall__ItemBoxReader__
#define __BouncingBall__ItemBoxReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class ItemBoxReader : public cocostudio::NodeReader {
public:
    static ItemBoxReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__BouncingBall__ItemBox__) */
