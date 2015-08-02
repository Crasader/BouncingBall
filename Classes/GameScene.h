#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "Constants.h"
#include "Ball.h"
#include "Coin.h"
#include "Rock.h"
#include "JSONPacker.h"


class Cannon;
class PassCode;
class Dogi;
class Explode;
class ItemBox;
class LevelClear;

class GameScene : public cocos2d::Node
{
public:
    static GameScene* createWithLevel(int level);
    void setPhyWorld(cocos2d::PhysicsWorld* world){ _physicsWorld = world; };
    void receivedData(const void* data, unsigned long length);
    void setGameState(GameState gameState);
    void setMultiplay(bool isMultiplay);
    GameState getStateByItem(ItemCategory itemCategory) const;
    void setTutorialStep(TutorialStep step);
    
protected:
    //for multi
    bool _isMultiplay;
    bool _simulating;
    
    bool initWithLevel(int level);
    void onEnter() override;
    
    //tutorial
    bool _tutorial;
    TutorialStep _tutorialStep;
    bool onContactBeginTutorial(cocos2d::PhysicsContact &contact);
    void onContactEndTutorial(cocos2d::PhysicsContact &contact);
    
    
    std::vector<cocos2d::Vec2> getBallPosOnState() const;
    void setBallPosOnState(std::vector<cocos2d::Vec2> ballPos);
    void stopAllBall();
    void disableTouchEvent();
    
    cocos2d::Scene* _physicsScene;
    
    cocos2d::ui::TextBMFont* _scoreLabel;
    GameState _gameState;
    
    cocos2d::PhysicsWorld* _physicsWorld;
    cocos2d::Node* _mainScene;

    //Ball
    cocos2d::Vector<Ball*> _ballsOnState;
    Ball* _ballWaitShooting;
    cocos2d::Sprite* _ballPreview;
    cocos2d::Vector<Ball*> _ballsInBag;

    
    //pointer instance
    Cannon* _cannon;
    Dogi* _dogi;
    cocos2d::Sprite* _edgeSp;
    PassCode* _passCode;
    ItemBox* _itemBox;
    cocos2d::ui::Button* _nextBallHolder;
    
    
    //coin && rock
    cocos2d::Vector<Coin*> _coinOnStage;
    cocos2d::Vector<Rock*> _rocksOnStage;
    std::vector<cocos2d::Vec2> _nextBallPos;
    
    int _currentScore;
    int _opponetScore;  //only for multi
    
    int _oneStarScore;
    int _twoStarScore;
    int _threeStarScore;
    int _level;

    void update(float dt) override;
    void updateBallPreview();
    void updateTutorial();
    
    void setupContactHandling();
    bool onContactBegin(cocos2d::PhysicsContact &contact);
    void onContactEnd(cocos2d::PhysicsContact &contact);

    void setupTouchHandling();
    void setupContanctHandling();
    
    void setupTutorialTouchHandling();
    void setupTutorialContanctHandling();
    
    void backButtonPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void ballHolderButtonPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    
    void createNextBall();
    void setupMap();
    void triggerGameOver();
    
    LevelClear* createLevelClearPanel();
    
    void shootCurrentBall();
    
    //Util Method
    
    int evaluateStars(int currentScore);
    std::string getConfigFileName();
    void resetAllBallHp();
    void enableCoin();
    bool allBallIsSpeedAreLowEnough();
    void resetEgde();
    void updateScoreLabel(int score);
    
    bool isGameOver();
    bool canUserGetItem();

    void createCoinByPosWhenBallHpIsZero(cocos2d::Vec2 pos);
    void createItemWhenTouchedItemBox(ItemCategory itemCategory);
    
    //for multiPlay
    void performInput(JSONPacker::MultiInputData multiInputData);
    bool isMyselfHost(std::string deviceName);
    bool canPlayfirst();
    void sendData(JSONPacker::MultiInputData multiInputData);
    void displayInfo(std::string info, float second = 1.0f,float scale = 1.0f);
    
    bool isMyTurn();
    
};


#endif // __HELLOWORLD_SCENE_H__
