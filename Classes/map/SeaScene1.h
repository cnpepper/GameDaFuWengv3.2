#ifndef _SEASCENE_H_
#define _SEASCENE_H_

#include "cocos2d.h"
#include "GameBaseScene.h"
class SeaScene : public GameBase
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
	CREATE_FUNC(SeaScene);
public:
	void addGameMap() override;
};

#endif // _SEASCENE_H_
