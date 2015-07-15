//
//  RewardPoint.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/16/15.
//
//

#include "RewardPoint.h"
using namespace cocos2d;

void RewardPoint::setupPhysics(){
    for (int i = 0; i < this->getChildren().size(); ++i) {
        auto rewardPoint = this->getChildren().at(i);
        //TODO: the config of the object should be managed by some config file use json or setting.
        //TODO: make a commmand line tools to create a objects
        auto rewardPointBody = PhysicsBody::createCircle(rewardPoint->getContentSize().width / 2, PhysicsMaterial(0.0f,1.0f,0.0f));
        rewardPointBody->setGravityEnable(false);
        rewardPointBody->setDynamic(false);
        rewardPointBody->setContactTestBitmask(0x03);
        rewardPointBody->setCategoryBitmask(0x02);
        rewardPointBody->setCollisionBitmask(0x02);
        
        //FIXME: fix this ugly code
        int points = 10;
        rewardPointBody->setTag(points); // the reward point of a circle
        rewardPoint->setPhysicsBody(rewardPointBody);
        
    }
}

void RewardPoint::onEnter()
{
    Node::onEnter();
    setupPhysics();
}