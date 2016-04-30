//
//  ScreenManager.cpp
//  MyProject
//
//  Created by 宮里章太 on 2016/04/30.
//
//

#include "ScreenManager.hpp"
#include "Constants.h"

using namespace cocos2d;

static ScreenManager* _instanceScreenManager = nullptr;

ScreenManager* ScreenManager::getInstance()
{
    if (!_instanceScreenManager)
    {
        _instanceScreenManager = new ScreenManager();
    }
    return _instanceScreenManager;
}

void ScreenManager::purge()
{
    CC_SAFE_DELETE(_instanceScreenManager);
}

bool ScreenManager::judgeScreenScale()
{
    //それぞれのスケール取得
    Size visibleSize = Director::getInstance()->getVisibleSize();
    const float scaleW = visibleSize.width / DESIGN_RESOLUTION_SIZE.width;
    const float scaleH = visibleSize.height/ DESIGN_RESOLUTION_SIZE.height;
    
    //スケールの大きい方を固定する
    //ResolutionPolicy::FIXED_HEIGHT
    if (scaleH > scaleW) return true;
    //ResolutionPolicy::FIXED_WIDTH
    return false;
}

