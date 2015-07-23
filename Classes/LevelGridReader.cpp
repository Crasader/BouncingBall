//
//  LevelGridReader.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/24/15.
//
//

#include "LevelGridReader.h"
#include "LevelGrid.h"

using namespace cocos2d;

static LevelGridReader* _instanceLevelGridReader = nullptr;

LevelGridReader* LevelGridReader::getInstance()
{
    if (!_instanceLevelGridReader)
    {
        _instanceLevelGridReader = new LevelGridReader();
    }
    return _instanceLevelGridReader;
}

void LevelGridReader::purge()
{
    CC_SAFE_DELETE(_instanceLevelGridReader);
}

Node* LevelGridReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
    LevelGrid* node = LevelGrid::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}