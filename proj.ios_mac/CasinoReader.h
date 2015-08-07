//
//  CasinoReader.h
//  BouncingBall
//
//  Created by Liang Fan on 8/6/15.
//
//

#ifndef __BouncingBall__CasinoReader__
#define __BouncingBall__CasinoReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class CasinoReader : public cocostudio::NodeReader {
public:
    static CasinoReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* defined(__BouncingBall__Casino__) */
