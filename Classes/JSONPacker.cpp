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

    //TODO: improve the efficient of this func
    const MapState unpackMapStateJSON(std::string json)
    {
        rapidjson::Document document;
        document.Parse<0>(json.c_str());
        
        std::vector<BallConfig> ballsOnStage;
        for (int i =0; i < document["ball"].Capacity();++i)
        {
            const rapidjson::Value& ball = document["ball"][i];
            float relativeX = ball["relativeX"].GetDouble();
            float relativeY = ball["relativeY"].GetDouble();
            std::string color = ball["color"].GetString();
            int hp = ball["hp"].GetInt();

            BallConfig config = {relativeX, relativeY, color, hp};
            ballsOnStage.push_back(config);
        }
        
        std::vector<BallConfig> ballsInBag;
        for (int i =0; i < document["ballBag"].Capacity();++i)
        {
            const rapidjson::Value& ball = document["ballBag"][i];
            float relativeX = ball["relativeX"].GetDouble();
            float relativeY = ball["relativeY"].GetDouble();
            std::string color = ball["color"].GetString();
            int hp = ball["hp"].GetInt();
            
            BallConfig config = {relativeX, relativeY, color, hp};
            ballsInBag.push_back(config);
        }
        
        rapidjson::Value& goal = document["goal"];
        Goal stageGoal;
        
        stageGoal.totalScore = goal["totalScore"].GetInt();
        stageGoal.timesHitBlue = goal["timesHitBlue"].GetInt();
        stageGoal.timesHitRed = goal["timesHitRed"].GetInt();
        stageGoal.timesHitGreen = goal["timesHitGreen"].GetInt();
        
        MapState mapState = { ballsOnStage, ballsInBag, stageGoal};
        return mapState;
    }
    
    std::string packMapStateJSON(const MapState mapState)
    {
        
    }
    
  }