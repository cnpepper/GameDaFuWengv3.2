#include "SplashScene.h"

Scene* Splash::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = Splash::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Splash::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	_visibleSize = visibleSize;//初始化窗口尺寸
	initMoveSprite();//初始化动画精灵方法
	scheduleOnce(schedule_selector(Splash::startMoveSprite),1);

    
    return true;
}
void Splash::startMoveSprite(float df)
{
	//动画从右向做开始，最末一个精灵 cheng 首先开始从右向左移动一个位置
	MoveBy* moveChengToLeft1 = MoveBy::create(MOVE_SPLEED, Point(-_spriteSize.width, 0));
	_chengSprite->runAction(moveChengToLeft1);

	//精灵ji从左向右移动一个位置，正2个动画相当于cheng和ji交换了位置
	MoveBy* moveJiToright = MoveBy::create(MOVE_SPLEED, Point(_spriteSize.width, 0));
	CallFunc* callFunc = CallFunc::create(CC_CALLBACK_0(Splash::movekeSpriteToLeft, this));
	//ji动画结束后调用回调函数 开始精灵ke的动画
	_jiSprite->runAction(Sequence::create(moveJiToright, callFunc, NULL));
}

void Splash::movekeSpriteToLeft()
{
	//精灵 cheng从右向左再移动一个位置
	MoveBy* moveChengToLeft2 = MoveBy::create(MOVE_SPLEED, Point(-_spriteSize.width,0));
	_chengSprite->runAction(moveChengToLeft2);

	//精灵ke从左向右移动一个位置，再次同cheng交换了位置
	MoveBy* moveKeToright = MoveBy::create(MOVE_SPLEED, Point(_spriteSize.width, 0));
	CallFunc* callFunc2 = CallFunc::create(CC_CALLBACK_0(Splash::moveMaiSpriteToLeft, this));
	//ji动画结束后调用回调函数 开始精灵ke的动画
	_keSprite->runAction(Sequence::create(moveKeToright, callFunc2, NULL));

}

void Splash::moveMaiSpriteToLeft()
{
	//精灵 cheng从右向左再次移动一个位置
	MoveBy* moveChengToLeft3 = MoveBy::create(MOVE_SPLEED, Point(-_spriteSize.width, 0));
	_chengSprite->runAction(moveChengToLeft3);

	//精灵mai从左向右移动一个位置，同cheng再次交换了位置
	MoveBy* mai_Sprite_MoveBy = MoveBy::create(MOVE_SPLEED, Point(_spriteSize.width, 0));
	CallFunc* callFunc3 = CallFunc::create(CC_CALLBACK_0(Splash::spriteFadeOut, this));

	//精灵mai动画结束后调用spriteFadeOut()方法，开始场景消失的动画
	_maiSprite->runAction(Sequence::create(mai_Sprite_MoveBy, callFunc3, NULL));
}

void Splash::spriteFadeOut()
{
	//定义4个消失的FadeOut动画，持续时间2秒
	FadeOut* fadeOut1 = FadeOut::create(1 * 2);
	FadeOut* fadeOut2 = FadeOut::create(1 * 2);
	FadeOut* fadeOut3 = FadeOut::create(1 * 2);
	FadeOut* fadeOut4 = FadeOut::create(1 * 2);
	_maiSprite->runAction(fadeOut1);
	_keSprite->runAction(fadeOut2);
	_jiSprite->runAction(fadeOut3);
	CallFunc* callFunc4 = CallFunc::create(CC_CALLBACK_0(Splash::gotoMenuScene, this));

	//动画结束后调用gotoMenuScene()方法进入MenuScene场景界面
	_chengSprite->runAction(Sequence::create(fadeOut4, callFunc4, NULL));
}

void Splash::gotoMenuScene()
{
	Director::getInstance()->replaceScene(MenuScene::createScene());
}
void Splash::initMoveSprite()
{
	_maiSprite = Sprite::create(MAI_IMAGE);
	_keSprite = Sprite::create(KE_IMAGE);
	_jiSprite = Sprite::create(JI_IMAGE);
	_chengSprite = Sprite::create(CHENG_IMAGE);

	_spriteSize = _maiSprite->getContentSize();

	_maiSprite->setPosition(Point(_visibleSize.width / 2 - (2 * _spriteSize.width), _visibleSize.height / 2));
	_keSprite->setPosition(Point(_visibleSize.width / 2 - _spriteSize.width, _visibleSize.height / 2));
	_jiSprite->setPosition(Point(_visibleSize.width / 2, _visibleSize.height / 2));
	_chengSprite->setPosition(Point(_visibleSize.width / 2 + _spriteSize.width, _visibleSize.height / 2));

	_maiSprite->setAnchorPoint(Point(0, 0.5));
	_keSprite->setAnchorPoint(Point(0, 0.5));
	_jiSprite->setAnchorPoint(Point(0, 0.5));
	_chengSprite->setAnchorPoint(Point(0, 0.5));

	this->addChild(_maiSprite);
	this->addChild(_keSprite);
	this->addChild(_jiSprite);
	this->addChild(_chengSprite);
}