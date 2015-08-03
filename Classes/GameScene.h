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
    void setMultiplay(bool isMultiplay);
    
protected:
    GameState _gameState;
    
    //Balls
    Ball* _ballWaitShooting;
    cocos2d::Sprite* _ballPreview;
    cocos2d::Vector<Ball*> _ballsInBag;

    
    //pointer instance
    cocos2d::Scene* _physicsScene;
    cocos2d::ui::TextBMFont* _scoreLabel;
    cocos2d::PhysicsWorld* _physicsWorld;
    cocos2d::Node* _mainScene;
    Cannon* _cannon;
    Dogi* _dogi;
    cocos2d::Sprite* _edgeSp;
    PassCode* _passCode;
    ItemBox* _itemBox;
    cocos2d::ui::Button* _nextBallHolder;
    
    
    //ojbect on state
    cocos2d::Vector<Ball*> _ballsOnState;
    cocos2d::Vector<Coin*> _coinOnStage;
    cocos2d::Vector<Rock*> _rocksOnStage;
    
    int _currentScore;
    int _oneStarScore;
    int _twoStarScore;
    int _threeStarScore;
    int _level;
    
    //life cycal
    bool initWithLevel(int level);
    void onEnter() override;
    void update(float dt) override;

    //contact event
    bool onContactBegin(cocos2d::PhysicsContact &contact);
    void onContactEnd(cocos2d::PhysicsContact &contact);

    
    //setup Method

    void setupTouchHandling();
    void setupContactHandling();
    void backButtonPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void ballHolderButtonPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void setupMap();

    
    //Game Logic
    void enableCoin();
    void createCoinByPosWhenBallHpIsZero(cocos2d::Vec2 pos);
    void createItemWhenTouchedItemBox(ItemCategory itemCategory);
    LevelClear* createLevelClearPanel();
    void shootCurrentBall();
    void dealWithHpBall(Ball* ball);
    void createNextBall();
    void triggerGameOver();
    void updateBallPreview();
    
    //Getter Setter
    std::string getConfigFileName() const;
    GameState getStateByItem(ItemCategory itemCategory) const;
    void setGameState(GameState gameState);
    std::vector<cocos2d::Vec2> getBallPosOnState() const;
    
    //Util Method
    int evaluateStars(int currentScore) const;
    bool allBallIsSpeedAreLowEnough() const;
    bool isGameOver() const;
    bool canUserGetItem() const;
    void resetAllBallHp();
    void resetEgde();
    void updateScoreLabel(int score);
    void displayInfo(std::string info, float second = 1.0f,float scale = 1.0f);
    void stopAllBall();
    void disableTouchEvent();
    

    //for multiPlay
    bool _isMultiplay;
    bool _simulating;
    int _opponetScore;
    std::vector<cocos2d::Vec2> _nextBallPos;
    
    void performInput(JSONPacker::MultiInputData multiInputData);
    bool isMyselfHost(std::string deviceName) const;
    bool canPlayfirst() const;
    void sendData(JSONPacker::MultiInputData multiInputData);
    void setBallPosOnState(std::vector<cocos2d::Vec2> ballPos);
    bool isMyTurn() const;
    
    //tutorial
    bool _tutorial;
    TutorialStep _tutorialStep;
    bool onContactBeginTutorial(cocos2d::PhysicsContact &contact);
    void onContactEndTutorial(cocos2d::PhysicsContact &contact);
    void setupTutorialTouchHandling();
    void setupTutorialContanctHandling();
    void updateTutorial();
    void setTutorialStep(TutorialStep step);
};


#endif // __HELLOWORLD_SCENE_H__
