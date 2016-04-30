//
//  MySprite.cpp
//  MyProject
//
//  Created by 宮里章太 on 2016/04/30.
//
//

#include "MySprite.hpp"

USING_NS_CC;

bool MySprite::init()
{
    if (! Node::init())
    {
        return false;
    }
    
    return true;
}

void MySprite::onEnter()
{
    Node::onEnter();
}
