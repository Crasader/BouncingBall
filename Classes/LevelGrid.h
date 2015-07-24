//
//  LevelGrid.h
//  BouncingBall
//
//  Created by Liang Fan on 7/24/15.
//
//

#ifndef __BouncingBall__LevelGrid__
#define __BouncingBall__LevelGrid__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

class LevelGrid : public cocos2d::Node
{
public:
    CREATE_FUNC(LevelGrid);
    void setDisplayStar(int starNums);
    void setLevel(int level);
    int getLevel();
    
protected:
    int _level;
    bool init() override;
};

#endif /* defined(__BouncingBall__LevelGrid__) */
