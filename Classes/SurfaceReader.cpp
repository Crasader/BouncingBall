//
//  SurfaceReader.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/14/15.
//
//

#include "SurfaceReader.h"
#include "Surface.h"

using namespace cocos2d;

static SurfaceReader* _instanceSurfaceReader = nullptr;

SurfaceReader* SurfaceReader::getInstance()
{
    if (!_instanceSurfaceReader)
    {
        _instanceSurfaceReader = new SurfaceReader();
    }
    return _instanceSurfaceReader;
}

void SurfaceReader::purge()
{
    CC_SAFE_DELETE(_instanceSurfaceReader);
}

Node* SurfaceReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
    Surface* node = Surface::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}