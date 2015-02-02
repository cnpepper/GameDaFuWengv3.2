/****************************************************** 
* Program Assignment :  片头动画场景 
* Author : 刘建均 
* Date : 2015 / 1 / 6  21 : 59
* Description : 主要实现了片头动画的展示和跳转到菜单场景
***************************************************** / 
/******************************************************* 
* Source code in :源文件路径
* Function List: 函数表
* void movekeSpriteToLeft();//定义ke.png精灵向左移动的方法
* void moveMaiSpriteToLeft();//定义mai.png精灵向左移动的方法
* void initMoveSprite();//初始化图片
* void startMoveSprite(float df);//开始移动
* void gotoMenuScene();//动画结束后跳转场景
* void spriteFadeOut();//动画逐渐消失方法
*******************************************************/
#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__

#include "cocos2d.h"
#include "ConstUtil.h"
USING_NS_CC;
#include "MenuScene.h"
class Splash : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
	CREATE_FUNC(Splash);
public:
	//定义了一些方法
	const double MOVE_SPLEED = 0.5f;//动画的播放速度
	void movekeSpriteToLeft();//定义ke.png精灵向左移动的方法
	void moveMaiSpriteToLeft();//定义mai.png精灵向左移动的方法
	void initMoveSprite();//初始化图片
	void startMoveSprite(float df);//开始移动
	void gotoMenuScene();//动画结束后跳转场景
	void spriteFadeOut();//动画逐渐消失方法

public:
	//定义一些成员
	Sprite* _maiSprite;//mai.png
	Sprite* _keSprite;//mai.png
	Sprite* _jiSprite;//mai.png
	Sprite* _chengSprite;//mai.png

	Size _visibleSize;//窗口大小
	Size _spriteSize;//每张图片大小


};

#endif // __SPLASH_SCENE_H__
