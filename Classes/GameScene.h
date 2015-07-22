#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "Constants.h"
#include "Ball.h"

class Cannon;

class GameScene : public cocos2d::Node
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    void onEnter() override;
    void setPhyWorld(cocos2d::PhysicsWorld* world){ m_world = world; };

    CREATE_FUNC(GameScene);
    
protected:
    cocos2d::PhysicsWorld* m_world;
    cocos2d::Node* _mainScene;
    
    //Ball
    cocos2d::Vector<Ball*> _ballsOnState;
    Ball* _ballWaitShooting;
    cocos2d::Vector<Ball*> _ballsInBag;
    
    Cannon* _cannon;
    cocos2d::Sprite* _edgeSp;
    const Goal _goal;
    Goal _currentState;

    void update(float dt) override;
    bool allBallIsStoped();
    void resetEgde();
    
    void updateScoreLabel(int score);
    bool onContactBegin(cocos2d::PhysicsContact &contact);
    void setupTouchHandling();
    void setupContactHandling();
    void setupBall();
    void setupMap();
    
    bool isGameOver();
    bool isGoalAchieved();
    int _totalScore;
    
    
    cocos2d::ui::Text*  _scoreLabel;
    cocos2d::ui::Text*  _redGoalLabel;
    cocos2d::ui::Text*  _blueGoalLabel;
    cocos2d::ui::Text*  _greenGoalLabel;
    
    GameState _gameState;
    
    void backButtonPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};


#endif // __HELLOWORLD_SCENE_H__
