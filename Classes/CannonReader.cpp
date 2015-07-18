//
//  CannonReader.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/17/15.
//
//

#include "CannonReader.h"
#include "Cannon.h"
using namespace cocos2d;

static CannonReader* _instanceCannonReader = nullptr;

CannonReader* CannonReader::getInstance()
{
    if (!_instanceCannonReader)
    {
        _instanceCannonReader = new CannonReader();
    }
    return _instanceCannonReader;
}

void CannonReader::purge()
{
    CC_SAFE_DELETE(_instanceCannonReader);
}

Node* CannonReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
    Cannon* node = Cannon::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}