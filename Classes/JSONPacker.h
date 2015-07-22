//
//  JSONPacker.h
//  BouncingBall
//
//  Created by Liang Fan on 7/16/15.
//
//

#ifndef __BouncingBall__JSONPacker__
#define __BouncingBall__JSONPacker__

#include "cocos2d.h"
#include "Constants.h"

namespace JSONPacker
{
    struct BallConfig
    {
        float relativeX;
        float relativeY;
        std::string color;
        int hp;
    };
    
    struct BlockConfig
    {
        
    };
    
    struct MapState
    {
        std::vector<BallConfig> ballsOnStage;
        std::vector<BallConfig> ballsInBag;
        Goal stageGoal;
 //       cocos2d::Vector<Block*> blocks;
        
    };

    //TODO: improve this speed
    const MapState unpackMapStateJSON(std::string json);
    std::string packMapStateJSON(MapState mapstate);
}


#endif /* defined(__BouncingBall__JSONPacker__) */
