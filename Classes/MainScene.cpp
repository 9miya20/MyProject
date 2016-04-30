//
//  MainScene.cpp
//  MyProject
//
//  Created by Shota Miyazato on 2016/04/27.
//
//

#include "MainScene.hpp"
#include "Constants.h"
#include "MySprite.hpp"
#include "ScreenManager.hpp"

USING_NS_CC;

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
    
    //画面全体のサイズ取得
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //画面左下の点取得
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /*
     背景
     */
    //背景生成
    Sprite* backGround = Sprite::create("images/sample2.png");
    //スプライトのサイズ取得
    Size backGroundContentSize = backGround->getContentSize();
    //設定解像度のの比率を取得
    float backGroundMagnification = 0;
    if (ScreenManager::getInstance()->judgeScreenScale()) {
        backGroundMagnification = DESIGN_RESOLUTION_SIZE.height / backGroundContentSize.height;
    } else {
        backGroundMagnification = DESIGN_RESOLUTION_SIZE.width / backGroundContentSize.width;
    }
    //画面サイズに合わせる
    //backGround->setContentSize(Size(backGroundContentSize.width * backGroundMagnification, backGroundContentSize.height * backGroundMagnification));
    backGround->setScale(backGroundMagnification);
    //中心に配置
    backGround->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    //backGround->setPosition(Vec2(DESIGN_RESOLUTION_SIZE.width, DESIGN_RESOLUTION_SIZE.height) / 2);
    //画面に表示
    this->addChild(backGround, 0);
    
    /*
     馬
     */
    Sprite* horse = Sprite::create("images/horse.png");
    Size horseSize = horse->getContentSize();
    horse->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(horse, 0);
    //馬のアニメーションフレーム生成
    Vector<SpriteFrame *> frames;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            //最後のフレームはbreak
            if (i == 2 && j == 3) break;
            Rect rect = Rect (horseSize.width * j, horseSize.height * i, horseSize.width, horseSize.height);
            auto frame = SpriteFrame::create("images/horseAtlas.png", rect);
            frames.pushBack(frame);
        }
    }
    Animation* animation = Animation::createWithSpriteFrames(frames, 0.1);
    
    //ジャンプアニメーションフレームの生成
    Vector<FiniteTimeAction *> jumpAnimationFrames;
    jumpAnimationFrames.pushBack(DelayTime::create(0.1));
    //時間：0.3秒　移動距離：0　ジャンプの最高点：10　ジャンプの回数：1回
    jumpAnimationFrames.pushBack(JumpBy::create(0.3, ccp(0, 0), 10, 1));
    jumpAnimationFrames.pushBack(DelayTime::create(0.3));
    jumpAnimationFrames.pushBack(JumpBy::create(0.3, ccp(0, 0), 10, 1));
    jumpAnimationFrames.pushBack(DelayTime::create(0.1));
    horse->runAction(RepeatForever::create(Spawn::create(Animate::create(animation), Sequence::create(jumpAnimationFrames), nullptr)));
    
    return true;
}

