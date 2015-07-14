///Users/liang.fan/Documents/CocosProjects/BouncingBall/Classes/Surface.cpp
//  Surface.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/14/15.
//
//

#include "Surface.h"
using namespace cocos2d;


using namespace cocos2d;

bool Surface::init()
{
    if (! Node::init())
    {
        return false;
    }

    return true;
}

void Surface::onEnter()
{
    Node::onEnter();
    std::string surfaceName = this->getName();
    this->setSurfaceType(surfaceName);
    this->setScale(0.5f);
    
}
#pragma mark -
#pragma Util Method


//TODO: Improve this function
void Surface::setSurfaceType(std::string name)
{
    if (name.compare("SandSurface")) {
        setSurfaceType(SurfaceType::sand);
    } else if (name.compare("WaterSurface")) {
        setSurfaceType(SurfaceType::water);
    } else {
        
    }
}

void Surface::setSurfaceType(SurfaceType type)
{
    this->surfaceType = type;
    for (int i = 0; i < this->getChildren().size(); ++i) {
        auto surfacePiece = this->getChildren().at(i);
        //TODO: use factory to create physics body
        auto surfaceBody = PhysicsBody::createCircle(surfacePiece->getContentSize().width / 2, PhysicsMaterial(0.0f,1.0f,0.0f));
        surfaceBody->setGravityEnable(false);
        surfaceBody->setDynamic(false);
        surfaceBody->setContactTestBitmask(0x03);
        surfaceBody->setCategoryBitmask(0x02);
        surfaceBody->setCollisionBitmask(0x02);
 //       surfaceBody->setCollisionBitmask(0x03);
        surfacePiece->setPhysicsBody(surfaceBody);
    }
}

