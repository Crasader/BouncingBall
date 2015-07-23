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
    bool init() override;
    void setDisplayStar(int starNums);
    
protected:
    
};

#endif /* defined(__BouncingBall__LevelGrid__) */
