//
//  UIConstants.h
//  BouncingBall
//
//  Created by Liang Fan on 7/15/15.
//
//

#ifndef BouncingBall_UIConstants_h
#define BouncingBall_UIConstants_h

static const float FONT_SIZE = 56.0f;
static const char* FONT_NAME = "arial.ttf";
static const cocos2d::Color3B LABEL_COLOR = cocos2d::Color3B(255, 0, 0);

const static int LEVELGIRD_ROW_NUM = 3;
const static int LEVELGIRD_COLUMN_NUM = 3;
const static int LEVEL_NUM_PER_PAGE = 9;

const static int MAX_LEVEL_PAGE_NUMS = 2;
const static int MIN_LEVEL_PAGE_NUMS = 1;

const static float GRID_INIT_X_POS = 170.0f;
const static float GRID_INIT_Y_POS = 780.0f;

const static float GRID_X_INTERVAL = 53.0f;
const static float GRID_Y_INTERVAL = 20.0f;

const static float GRID_HEIGHT = 147.5f;
const static float GRID_WIDTH = 103.0f;

const static float BALL_CONTACT_PARTICLE_SCALE = 0.2f;

#endif
