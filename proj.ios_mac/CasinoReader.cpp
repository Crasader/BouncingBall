//
//  CasinoReader.cpp
//  BouncingBall
//
//  Created by Liang Fan on 8/6/15.
//
//

#include "CasinoReader.h"
#include "Casino.h"

using namespace cocos2d;

static CasinoReader* _instanceCasinoReader = nullptr;

CasinoReader* CasinoReader::getInstance() {
    if (!_instanceCasinoReader) {
        _instanceCasinoReader = new CasinoReader();
    }
    return _instanceCasinoReader;
}

void CasinoReader::purge() {
    CC_SAFE_DELETE(_instanceCasinoReader);
}

Node* CasinoReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    Casino* node = Casino::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
