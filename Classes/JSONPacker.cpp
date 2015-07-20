//
//  JSONPacker.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/16/15.
//
//

#include "JSONPacker.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "Constants.h"

using namespace cocos2d;

namespace JSONPacker {
    //Read Map state
    //Create Map State
    const MapState unpackMapStateJSON(std::string json)
    {
        rapidjson::Document document;
        document.Parse<0>(json.c_str());
        
      //  rapidjson::Value& balls = document["ball"];
        std::vector<BallConfig> ballConfigs;
        for (int i =0; i < document["ball"].Capacity();++i)
        {
            const rapidjson::Value& ball = document["ball"][i];
            float relativeX = ball["relativeX"].GetDouble();
            float relativeY = ball["relativeY"].GetDouble();
            std::string color = ball["color"].GetString();
            int hp = ball["hp"].GetInt();

            BallConfig config = {relativeX, relativeY, color, hp};
            ballConfigs.push_back(config);
        }
        MapState mapState = { ballConfigs };
        return mapState;
    }
    
    std::string packMapStateJSON(const MapState mapState)
    {
        
    }
    
  }