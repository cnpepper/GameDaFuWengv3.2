/****************************************************** 
* Program Assignment :  主菜单场景 
* Author : 刘建均 
* Date : 2015 / 1 / 7  20 : 19
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
#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
#include "GUI/CCControlExtension/CCControl.h"
#include "ConstUtil.h"
<<<<<<< HEAD
#include "cocos2d/extensions/cocos-ext.h"
=======
#include "cocos-ext.h"
>>>>>>> origin/master
USING_NS_CC_EXT;
#include "PopupLayer.h"
class MenuScene : public cocos2d::LayerColor/*LayerColor:一个单纯的实心色块*/
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
	CREATE_FUNC(MenuScene);
public:
	//定义了一些方法
	void menuTouchDown(Object* pSender, extension::Control::EventType event);//menu的点击回调方法
	void addBackGroundSprite();//添加场景背景方法
	void addMenuSprites();//添加menu的方法
	void popupLayer();//设置弹出提示窗口

	void quitButtonCallback(Node *pNode);
private:
	//定义一些成员
	Size _visibleSize;//窗口大小
	LabelTTF *settingsGameTTF;//场景文字


};

#endif // __SPLASH_SCENE_H__
