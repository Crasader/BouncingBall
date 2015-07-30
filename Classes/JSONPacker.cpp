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
    
    std::string packMultiInputDataJSON(const MultiInputData& multiInputData)
    {
        rapidjson::Document document;
        document.SetObject();
        
        int gameState = static_cast<int>(multiInputData.gameState);
        
        document.AddMember("gameState",gameState, document.GetAllocator());
        
        switch (multiInputData.gameState) {
            case GameState::sendDeviceName:
            {
                document.AddMember("deviceName", multiInputData.deviceName.c_str(), document.GetAllocator());
            }
                break;
            case GameState::shooting:
            {
                document.AddMember("angle", multiInputData.angle, document.GetAllocator());
            }
                break;
            case GameState::waiting:
            {
                rapidjson::Value ballPos(rapidjson::kArrayType);
                for (auto pos : multiInputData.ballPos) {
                    rapidjson::Value posValue(rapidjson::kObjectType);
                    posValue.AddMember("x", pos.x, document.GetAllocator());
                    posValue.AddMember("y", pos.y, document.GetAllocator());
                    ballPos.PushBack(posValue,document.GetAllocator());
                }
                document.AddMember("ballPos",ballPos,document.GetAllocator());
            }
            default:
                break;
        }
        
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);
        
        std::string returnString(buffer.GetString(), buffer.Size());
        return returnString;

    }
    
    MultiInputData unpackMultiInputDataJSON(std::string json)
    {
        rapidjson::Document document;
        document.Parse<0>(json.c_str());
        
        MultiInputData data;
 
        data.gameState = static_cast<GameState>(document["gameState"].GetInt());
        
        switch (data.gameState) {
            case GameState::sendDeviceName:
            {
                data.deviceName = document["deviceName"].GetString();
            }
                break;
            case GameState::waiting:
            {
                std::vector<Vec2> ballPos;
                for (int i =0; i < document["ballPos"].Capacity(); ++i) {
                    Vec2 pos;
                    pos.x = document["ballPos"][i]["x"].GetDouble();
                    pos.y = document["ballPos"][i]["y"].GetDouble();
                    ballPos.push_back(pos);
                }
                data.ballPos = ballPos;
            }
                break;
            case GameState::shooting:
            {
                data.angle = document["angle"].GetDouble();
            }
                break;
            default:
                break;
        }
        
        return data;
    }
    
}