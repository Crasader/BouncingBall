//
//  ExplodeReader.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/27/15.
//
//

#include "ExplodeReader.h"
#include "Explode.h"

using namespace cocos2d;

static ExplodeReader* _instanceExplodeReader = nullptr;

ExplodeReader* ExplodeReader::getInstance() {
    if (!_instanceExplodeReader) {
        _instanceExplodeReader = new ExplodeReader();
    }
    return _instanceExplodeReader;
}

void ExplodeReader::purge() {
    CC_SAFE_DELETE(_instanceExplodeReader);
}

Node* ExplodeReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    Explode* node = Explode::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
