//
//  MainScene.cpp
//  MyProject
//
//  Created by Shota Miyazato on 2016/04/27.
//
//

USING_NS_CC;
#include "MainScene.hpp"

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
    
    auto sprite = Sprite::create("images/sample.png");
    
    this->addChild(sprite, 0);
    
    return true;
}

