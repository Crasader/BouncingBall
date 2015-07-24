//
//  LevelClearReader.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/24/15.
//
//

#include "LevelClearReader.h"
#include "LevelClear.h"

using namespace cocos2d;

static LevelClearReader* _instanceLevelClearReader = nullptr;

LevelClearReader* LevelClearReader::getInstance() {
    if (!_instanceLevelClearReader) {
        _instanceLevelClearReader = new LevelClearReader();
    }
    return _instanceLevelClearReader;
}

void LevelClearReader::purge() {
    CC_SAFE_DELETE(_instanceLevelClearReader);
}

Node* LevelClearReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    LevelClear* node = LevelClear::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
