//
//  MainScene.cpp
//  MyProject
//
//  Created by Shota Miyazato on 2016/04/27.
//
//

USING_NS_CC;
#include "MainScene.hpp"
#include "Constants.h"

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    /*
     背景
     */
    //背景生成
    Sprite* backGround = Sprite::create("images/sample.png");
    //スプライトのサイズ取得
    Size backGroundContentSize = backGround->getContentSize();
    //設定解像度のの縦比率を取得
    float backGroundMagnification = DESIGN_RESOLUTION_SIZE.height / backGroundContentSize.height;
    //画面サイズに合わせる
    backGround->setContentSize(Size(backGroundContentSize.width * backGroundMagnification, backGroundContentSize.height * backGroundMagnification));
    //中心に配置
    backGround->setPosition(Vec2(DESIGN_RESOLUTION_SIZE.width / 2, DESIGN_RESOLUTION_SIZE.height / 2));
    //画面に表示
    this->addChild(backGround, 0);
    
    return true;
}

