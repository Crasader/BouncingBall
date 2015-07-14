//
//  SurfaceReader.h
//  BouncingBall
//
//  Created by Liang Fan on 7/14/15.
//
//

#ifndef __BouncingBall__SurfaceReader__
#define __BouncingBall__SurfaceReader__

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class SurfaceReader : public cocostudio::NodeReader
{
public:
    static SurfaceReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};
#endif /* defined(__BouncingBall__SurfaceReader__) */
