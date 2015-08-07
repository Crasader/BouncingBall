//
//  TransportReader.cpp
//  BouncingBall
//
//  Created by Liang Fan on 8/4/15.
//
//

#include "TransportReader.h"
#include "Transport.h"

using namespace cocos2d;

static TransportReader* _instanceTransportReader = nullptr;

TransportReader* TransportReader::getInstance() {
    if (!_instanceTransportReader) {
        _instanceTransportReader = new TransportReader();
    }
    return _instanceTransportReader;
}

void TransportReader::purge() {
    CC_SAFE_DELETE(_instanceTransportReader);
}

Node* TransportReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    Transport* node = Transport::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
