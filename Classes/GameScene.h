#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ball.h"
#include "Constants.h"
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
private:
    Ball* _ball;
    bool onContactBegin(cocos2d::PhysicsContact &contact);
    void setupTouchHandling();
    void setupContactHandling();
    void setupBall();
    void setupMap();
    bool ballIsInShootingArea();
    bool isInShootingArea(cocos2d::Vec2 touchPos);
    
    int _totalScore;
    
    cocos2d::Sprite* _selectedSprite;
    GameState _gameState;
};


#endif // __HELLOWORLD_SCENE_H__
