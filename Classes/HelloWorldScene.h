#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
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
    CREATE_FUNC(HelloWorld);
private:
    bool onContactBegin(cocos2d::PhysicsContact &contact);
    cocos2d::Sprite* _ball;
};

#endif // __HELLOWORLD_SCENE_H__
