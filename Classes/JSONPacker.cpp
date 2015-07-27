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
            float xPos = ball["xPos"].GetDouble();
            float yPos = ball["yPos"].GetDouble();
            Vec2 pos = Vec2(xPos, yPos);
            std::string color = ball["color"].GetString();

            BallConfig config = {pos, color};
            ballsOnStage.push_back(config);
        }
        
        std::vector<std::string> ballsInBag;
        for (int i =0; i < document["ballBag"].Capacity();++i)
        {
            std::string color = document["ballBag"][i].GetString();

            ballsInBag.push_back(color);
        }
        
        std::vector<Vec2> rocks;
        for (int i =0; i < document["rock"].Capacity();++i)
        {
            const rapidjson::Value& rock = document["rock"][i];
            float xPos = rock["xPos"].GetDouble();
            float yPos = rock["yPos"].GetDouble();
            Vec2 pos = Vec2(xPos, yPos);
            rocks.push_back(pos);
        }
        
        std::vector<Vec2> coins;
        for (int i =0; i < document["coin"].Capacity();++i)
        {
            const rapidjson::Value& coin = document["coin"][i];
            float xPos = coin["xPos"].GetDouble();
            float yPos = coin["yPos"].GetDouble();
            Vec2 pos = Vec2(xPos, yPos);
            coins.push_back(pos);
        }
        
        std::string passCode = document["passCode"].GetString();
        
        
        rapidjson::Value& star = document["star"];
        StarConfig starConfig;
        starConfig.oneStar = star["one"].GetInt();
        starConfig.twoStar = star["two"].GetInt();
        starConfig.threeStar = star["three"].GetInt();
        
        
        MapState mapState = { ballsOnStage, ballsInBag, rocks, coins, passCode, starConfig };
        return mapState;
    }
    
    std::string packMultiSyncDataJSON(MultiSyncData multiSyncData)
    {
        rapidjson::Document document;
        document.SetObject();
        /*
     //   document.AddMember("multiplayState", multiSyncData.multiplayState, document.GetAllocator());
        switch (multiSyncData.multiplayState) {
            case MultiplayState::sendDeviceName:
            {
                document.AddMember("deviceName", multiSyncData.deviceName, document.GetAllocator());
            }
                break;
            case MultiplayState::shooting:
            {
                document.AddMember("angle", multiSyncData.angle, document.GetAllocator());
                document.AddMember("speed", multiSyncData.speed, document.GetAllocator());
            }
                break;
            default:
                break;
        }
        
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);
        
        std::string returnString(buffer.GetString(), buffer.Size());
         */
       // return returnString;

    }
    
    MultiSyncData unpackMultiSyncDataJSON(std::string json)
    {
        rapidjson::Document document;
        document.Parse<0>(json.c_str());
        
        MultiSyncData data;
 
 //       data.multiplayState = static_cast<MultiplayState>(document["multiplayState"].GetInt());
        /*
        switch (data.multiplayState) {
            case MultiplayState::sendDeviceName:
            {
                data.deviceName = document["deviceName"].GetString();
            }
                break;
            case MultiplayState::shooting:
            {
                data.angle = document["angle"].GetDouble();
                data.speed = document["speed"].GetDouble();
            }
                break;
            default:
                break;
        }
         */
        
   //     return data;
    }
    
  }