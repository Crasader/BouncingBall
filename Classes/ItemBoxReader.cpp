//
//  ItemBoxReader.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/28/15.
//
//

#include "ItemBoxReader.h"
#include "ItemBox.h"

using namespace cocos2d;

static ItemBoxReader* _instanceItemBoxReader = nullptr;

ItemBoxReader* ItemBoxReader::getInstance() {
    if (!_instanceItemBoxReader) {
        _instanceItemBoxReader = new ItemBoxReader();
    }
    return _instanceItemBoxReader;
}

void ItemBoxReader::purge() {
    CC_SAFE_DELETE(_instanceItemBoxReader);
}

Node* ItemBoxReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions) {
    ItemBox* node = ItemBox::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
