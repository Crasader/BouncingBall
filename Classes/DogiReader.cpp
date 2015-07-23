//
//  DogiReader.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/23/15.
//
//

#include "DogiReader.h"
#include "Dogi.h"

using namespace cocos2d;

static DogiReader* _instanceDogiReader = nullptr;

DogiReader* DogiReader::getInstance()
{
    if (!_instanceDogiReader)
    {
        _instanceDogiReader = new DogiReader();
    }
    return _instanceDogiReader;
}

void DogiReader::purge()
{
    CC_SAFE_DELETE(_instanceDogiReader);
}

Node* DogiReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
    Dogi* node = Dogi::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}