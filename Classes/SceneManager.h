//
//  SceneManager.h
//  BouncingBall
//
//  Created by Liang Fan on 7/16/15.
//
//

#ifndef __BouncingBall__SceneManager__
#define __BouncingBall__SceneManager__
#include "NetworkingWrapper.h"

class GameScene;
class LevelSelect;

class SceneManager : NetworkingDelegate
{
public:
    static SceneManager* getInstance();
    void enterGameScene(int level, bool networked);
    
    void enterLevelSelect();
    void backToLobby();
    
    void showPeerList();
    void receiveMultiplayerInvitations();
    void sendData(const void* data, unsigned long length);
    std::string getDeviceName();
    
    
private:
    std::unique_ptr<NetworkingWrapper> networkingWrapper;
    GameScene* _gameScene;
    LevelSelect* _levelSelect;
    SceneManager();
    ~SceneManager();
    
    void receivedData(const void* state, unsigned long length);
    void stateChanged(ConnectionState state);
};
#endif /* defined(__BouncingBall__SceneManager__) */
