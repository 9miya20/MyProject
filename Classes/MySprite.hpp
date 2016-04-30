//
//  MySprite.hpp
//  MyProject
//
//  Created by 宮里章太 on 2016/04/30.
//
//

#ifndef MySprite_hpp
#define MySprite_hpp

class MySprite : public cocos2d::Sprite
{
public:
    CREATE_FUNC(MySprite);
    bool init() override;
    void onEnter() override;
};


#endif /* MySprite_hpp */
