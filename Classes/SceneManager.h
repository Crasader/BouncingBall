//
//  SceneManager.h
//  BouncingBall
//
//  Created by Liang Fan on 7/16/15.
//
//

#ifndef __BouncingBall__SceneManager__
#define __BouncingBall__SceneManager__

class GameScene;
class LevelSelect;
//class SceneManager : NetworkingDelegate
class SceneManager
{
public:
    static SceneManager* getInstance();
    void enterGameScene(std::string configFile);
    void enterLevelSelect();
    void backToLobby();
    
    void showPeerList();
    void receiveMultiplayerInvitations();
    void sendData(const void* data, unsigned long length);
private:
//    std::unique_ptr<NetworkingWrapper> networkingWrapper;
    GameScene* _gameScene;
    LevelSelect* _levelSelect;
    SceneManager();
    ~SceneManager();
    
 //   void receivedData(const void* state, unsigned long length);
 //   void stateChanged(ConnectionState state);
};
#endif /* defined(__BouncingBall__SceneManager__) */
