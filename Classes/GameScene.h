#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "Constants.h"
#include "Ball.h"
class Cannon;

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    void onEnter() override;
    cocos2d::PhysicsWorld* m_world;
    void setPhyWorld(cocos2d::PhysicsWorld* world){ m_world = world; };

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
protected:
    cocos2d::Vector<Ball*> _balls;
    Ball* _ballWaitShooting;
    Cannon* _cannon;
    
    void update(float dt) override;
    bool allBallIsStoped();
    
    void updateScoreLabel(int score);
    bool onContactBegin(cocos2d::PhysicsContact &contact);
    void setupTouchHandling();
    void setupContactHandling();
    void setupBall();
    void setupMap();
    
    int _totalScore;
    cocos2d::ui::Text*  _scoreLabel;
    
    GameState _gameState;
    
    void backButtonPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};


#endif // __HELLOWORLD_SCENE_H__
