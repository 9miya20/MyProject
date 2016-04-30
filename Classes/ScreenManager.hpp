//
//  ScreenManager.hpp
//  MyProject
//
//  Created by 宮里章太 on 2016/04/30.
//
//

#ifndef ScreenManager_hpp
#define ScreenManager_hpp

#include "cocos2d.h"

class ScreenManager : public cocos2d::Layer
{
public:
    static ScreenManager* getInstance();
    static void purge();
    bool judgeScreenScale();
};


#endif /* ScreenManager_hpp */
