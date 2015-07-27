//
//  ItemBox.h
//  BouncingBall
//
//  Created by Liang Fan on 7/28/15.
//
//

#ifndef __BouncingBall__ItemBox__
#define __BouncingBall__ItemBox__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "constants.h"

class ItemBox : public cocos2d::Node {
public:
    CREATE_FUNC(ItemBox);
    bool init() override;
    void addItem(ItemCategory item);
    ItemCategory pickUpItemFromPos(cocos2d::Vec2 pos);
protected:
    std::vector<Sprite*> _items;
};

#endif /* defined(__BouncingBall__ItemBox__) */
