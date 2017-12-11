
#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

#include "cocos2d.h"

class TestScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(TestScene)
    
};

#endif