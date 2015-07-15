//
//  RewardPointReader.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/16/15.
//
//

#include "RewardPointReader.h"
#include "RewardPoint.h"

using namespace cocos2d;

static RewardPointReader* _instanceRewardPointReader = nullptr;

RewardPointReader* RewardPointReader::getInstance()
{
    if (!_instanceRewardPointReader)
    {
        _instanceRewardPointReader = new RewardPointReader();
    }
    return _instanceRewardPointReader;
}

void RewardPointReader::purge()
{
    CC_SAFE_DELETE(_instanceRewardPointReader);
}

Node* RewardPointReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
    RewardPoint* node = RewardPoint::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}