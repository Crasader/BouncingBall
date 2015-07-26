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
    };
    
    struct BlockConfig
    {
        
    };
    
    struct StarConfig
    {
        int oneStar;
        int twoStar;
        int threeStar;
    };
    
    struct MapState
    {
        std::vector<BallConfig> ballsOnStage;
        std::vector<BallConfig> ballsInBag;
        std::string passCode;
        StarConfig starConfig;
 //       cocos2d::Vector<Block*> blocks;
        
    };
    
    struct MultiSyncData
    {
        MultiplayState multiplayState;
        float angle;
        float speed;
        std::string deviceName;
    };

    //TODO: improve this speed
    const MapState unpackMapStateJSON(std::string json);
    
    std::string packMultiSyncDataJSON(MultiSyncData multiSyncData);
    MultiSyncData unpackMultiSyncDataJSON(std::string json);
}


#endif /* defined(__BouncingBall__JSONPacker__) */
