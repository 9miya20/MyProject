//
//  MainScene.hpp
//  MyProject
//
//  Created by Shota Miyazato on 2016/04/27.
//
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainScene);
};



#endif /* MainScene_hpp */
