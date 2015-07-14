//
//  Surface.h
//  BouncingBall
//
//  Created by Liang Fan on 7/14/15.
//
//

#ifndef __BouncingBall__Surface__
#define __BouncingBall__Surface__

#include "Constants.h"

class Surface : public cocos2d::Node
{
public:
    CREATE_FUNC(Surface);
    bool init() override;
    void setSurfaceType(std::string name);
    void setSurfaceType(SurfaceType name);
    void onEnter() override;
    
    
private:
    SurfaceType surfaceType;
};
#endif /* defined(__BouncingBall__Surface__) */
