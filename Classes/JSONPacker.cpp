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
            
            BallConfig config = {relativeX, relativeY, color, hp};
            ballsInBag.push_back(config);
        }
        std::string passCode = document["passCode"].GetString();
        
        
        rapidjson::Value& star = document["star"];
        StarConfig starConfig;
        starConfig.oneStar = star["one"].GetInt();
        starConfig.twoStar = star["two"].GetInt();
        starConfig.threeStar = star["three"].GetInt();
        
        
        MapState mapState = { ballsOnStage, ballsInBag, passCode, starConfig};
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