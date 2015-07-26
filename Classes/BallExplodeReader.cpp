//
//  BallExplodeReader.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/27/15.
//
//

#include "BallExplodeReader.h"
#include "BallExplode.h"

using namespace cocos2d;

static BallExplodeReader* _instanceBallExplodeReader = nullptr;

BallExplodeReader* BallExplodeReader::getInstance() {
    if (!_instanceBallExplodeReader) {
        _instanceBallExplodeReader = new BallExplodeReader();
    }
    return _instanceBallExplodeReader;
}

void BallExplodeReader::purge() {
    CC_SAFE_DELETE(_instanceBallExplodeReader);
}

Node* BallExplodeReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    BallExplode* node = BallExplode::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
