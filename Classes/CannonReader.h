//
//  CannonReader.h
//  BouncingBall
//
//  Created by Liang Fan on 7/17/15.
//
//

#ifndef __BouncingBall__CannonReader__
#define __BouncingBall__CannonReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class CannonReader : public cocostudio::NodeReader
{
public:
    static CannonReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};
#endif /* defined(__BouncingBall__CannonReader__) */
