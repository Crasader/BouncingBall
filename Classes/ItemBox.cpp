//
//  ItemBox.cpp
//  BouncingBall
//
//  Created by Liang Fan on 7/28/15.
//
//

#include "ItemBox.h"

using namespace cocos2d;

bool ItemBox::init() {
    if (!Node::init()) {
        return false;
    }

    return true;
}

void ItemBox::addItem(ItemCategory itemCategory)
{
    if (_items.size() == 4) {
        CCLOG("items is full");
    } else {
        //TODO: can be refactoring
        Sprite* displayItem;
        switch (itemCategory) {
            case ItemCategory::ballBox:
                displayItem = Sprite::create("ballBox.png");
            case ItemCategory::aim:
                displayItem = Sprite::create("aim.png");
            case ItemCategory::bomb:
                displayItem = Sprite::create("bomb.png");
            case ItemCategory::none:
                break;
        }
        _items.push_back(displayItem);
        displayItem->setTag(static_cast<int>(itemCategory));
        displayItem->setAnchorPoint(Vec2(0.5f, 0.5f));
        int index = _items.size() - 1;
        displayItem->setPosition(Vec2(37 + 70 * index, 35));
        this->addChild(displayItem);
    }
}

ItemCategory ItemBox::pickUpItemFromPos(cocos2d::Vec2 pos)
{
    for (int i=0; i < _items.size(); ++i) {
        if (_items[i]->getBoundingBox().containsPoint(pos)) {
            ItemCategory itemCategory = static_cast<ItemCategory>(_items[i]->getTag());
            _items.erase(_items.begin() +i);
            _items[i]->removeFromParent();
            return itemCategory;
        }
    }
    return ItemCategory::none;
    
}


bool ItemBox::isClicked(Vec2 pos)
{
    return this->getChildByName<Sprite*>("itemBackGround")->getBoundingBox().containsPoint(pos);
}