//
//  Transport.cpp
//  BouncingBall
//
//  Created by Liang Fan on 8/4/15.
//
//

#include "Transport.h"
#include "Constants.h"

bool Transport::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->_timeline = CSLoader::createTimeline("Transport.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->_timeline->retain();
    
    _circle1Setted = false;
    _circle2Setted = false;
    
    return true;
}

void Transport::syncTransportPos(cocos2d::Vec2 pos, cocos2d::Vec2 circle1Pos, cocos2d::Vec2 circle2Pos)
{
    this->setPosition(pos);
    _circle1->setPosition(circle1Pos);
    _circle2->setPosition(circle2Pos);
    _button1->setEnabled(false);
    _button1->setVisible(false);
    _circle1->getChildByName("Label1")->setVisible(false);
    _button2->setEnabled(false);
    _button2->setVisible(false);
    _circle2->getChildByName("Label2")->setVisible(false);
    _circle1Setted = true;
    _circle2Setted = true;
    enableTransport();
}

void Transport::enableTransport()
{
    PhysicsBody* body = PhysicsBody::createCircle(_circle1->getContentSize().width * 1.5/2);
    body->setDynamic(false);
    body->setCategoryBitmask(TRANSPORT_CATEGORY);
    body->setContactTestBitmask(TRANSPORT_CONTACT_MASK);
    body->setCollisionBitmask(TRANSPORT_CULLISION_MASK);
    body->setGravityEnable(false);
    _circle1->setPhysicsBody(body);
}

void Transport::onExit()
{
    _timeline->release();
    Node::onExit();
}

void Transport::runTransportAnimation()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("transport",true);
}

Sprite* Transport::getTouchedCircle(Vec2 pos) const
{
    if (_circle1->getBoundingBox().containsPoint(pos) && !_circle1Setted) {
        return _circle1;
    } else if (_circle2->getBoundingBox().containsPoint(pos) && !_circle2Setted) {
        return _circle2;
    } else {
        return nullptr;
    }
    
}

void Transport::onEnter()
{
    Node::onEnter();
    
    _circle1 = this->getChildByName<Sprite*>("circle1");
    _circle2 = this->getChildByName<Sprite*>("circle2");
    _button1 = _circle1->getChildByName<ui::Button*>("Button1");
    _button2 = _circle2->getChildByName<ui::Button*>("Button2");
    _circle1Setted = false;
    _circle2Setted = false;
    
    _button1->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        if (type == ui::Widget::TouchEventType::ENDED) {
            _circle1Setted = true;
            _button1->setEnabled(false);
            _button1->setVisible(false);
            _circle1->getChildByName("Label1")->setVisible(false);
        }
    });
    _button2->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        if (type == ui::Widget::TouchEventType::ENDED) {
            _circle2Setted = true;
            _button2->setEnabled(false);
            _button2->setVisible(false);
            _circle2->getChildByName("Label2")->setVisible(false);
        }
    });
       runTransportAnimation();
}

void Transport::enableOKButton()
{
    if (!_circle1Setted) {
        _button1->setEnabled(true);
        _button1->setVisible(true);
    }
    
    if (!_circle2Setted) {
        _button2->setEnabled(true);
        _button2->setVisible(true);
    }
}

void Transport::disableOKButton()
{
    if (!_circle1Setted) {
        _button1->setEnabled(false);
        _button1->setVisible(false);
    }
    
    if (!_circle2Setted) {
        _button2->setEnabled(false);
        _button2->setVisible(false);
    }
}

bool Transport::isReady() const
{
    return _circle1Setted && _circle2Setted;
}

Vec2 Transport::getTransportPos() const
{
    return _circle2->getPosition();
}

Vec2 Transport::getOriginTransportPos() const
{
    return _circle1->getPosition();
}