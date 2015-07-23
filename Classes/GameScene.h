#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "Constants.h"
#include "Ball.h"


class Cannon;
class PassCode;

class GameScene : public cocos2d::Node
{
public:
    void setPhyWorld(cocos2d::PhysicsWorld* world){ m_world = world; };

    CREATE_FUNC(GameScene);
    
protected:
    bool init() override;
    void onEnter() override;
    cocos2d::Scene* _physicsScene;
    
    cocos2d::PhysicsWorld* m_world;
    cocos2d::Node* _mainScene;
    
    //Ball
    cocos2d::Vector<Ball*> _ballsOnState;
    Ball* _ballWaitShooting;
    cocos2d::Vector<Ball*> _ballsInBag;
    
    Cannon* _cannon;
    cocos2d::Sprite* _edgeSp;
    PassCode* _passCode;
    
    int _currentScore;
    
    int _oneStarScore;
    int _twoStarScore;
    int _threeStarScore;

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
    
    void triggerGameOver();
    
    //Util Method
    int evaluateStars(int currentScore);

    
    cocos2d::ui::Text*  _scoreLabel;
    
    GameState _gameState;
    
    void backButtonPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};


#endif // __HELLOWORLD_SCENE_H__
