<<<<<<< HEAD
=======
﻿/****************************************************** 
* Program Assignment : 弹出的文字类
* Author : 刘建均 
* Date : 2015 / 1 / 26  21 : 59
* Description :
***************************************************** / 
/******************************************************* 
* Source code in :源文件路径
* Function List: 函数表
*******************************************************/
>>>>>>> origin/master
#ifndef __POPUPLAYER_H__
#define __POPUPLAYER_H__

#include "cocos2d.h"
USING_NS_CC;
#include "GUI/CCControlExtension/CCControl.h"
#include "ConstUtil.h"
<<<<<<< HEAD
#include "cocos2d/extensions/cocos-ext.h"
USING_NS_CC_EXT;
const int Pop_FontSize = 20;//���������С
=======
#include "cocos-ext.h"
USING_NS_CC_EXT;
const int Pop_FontSize = 20;//定义字体大小
>>>>>>> origin/master
class PopupLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
	CREATE_FUNC(PopupLayer);
	
	PopupLayer();
	~PopupLayer();
	static PopupLayer* create(const char* backgroundImage);
<<<<<<< HEAD
	void setTitle(const char* title, int fontsize=Pop_FontSize);//���öԻ������
	void setContentText(const char* text, int fontsize = Pop_FontSize,int padding = 50, int paddintTop = 100);//�����ı�������
	void setCallbackFunc(Object* target, SEL_CallFuncN callfun);//���ð����Ļص�����
	bool addButton(const char* normalImage, const char* selectedImage, const char*title,int tag=0);//��ӶԻ���ť

	virtual void onEnter();//����ʱ����
	virtual void onExit();//�˳�ʱ����

	void buttonCallback(CCObject* pSender);

	int _contentPadding;//�ı��������ߵĿհ׾���
	int _contentPaddingTop;//�ı������ϱ߿հ׾���
=======
	void setTitle(const char* title, int fontsize=Pop_FontSize);//设置对话框标题
	void setContentText(const char* text, int fontsize = Pop_FontSize,int padding = 50, int paddintTop = 100);//设置文本框内容
	void setCallbackFunc(Object* target, SEL_CallFuncN callfun);//设置按键的回调方法
	bool addButton(const char* normalImage, const char* selectedImage, const char*title,int tag=0);//添加对话框按钮

	virtual void onEnter();//进入时调用
	virtual void onExit();//退出时调用

	void buttonCallback(CCObject* pSender);

	int _contentPadding;//文本内容两边的空白距离
	int _contentPaddingTop;//文本内容上边空白距离
>>>>>>> origin/master

	CCObject* _callbackListener;

	SEL_CallFuncN _callbakc;
	//
	CC_SYNTHESIZE_RETAIN(Menu*, _pMenu,MenuButton);
	CC_SYNTHESIZE_RETAIN(Sprite*,_sfbackground,SpriteBackGround);

	CC_SYNTHESIZE_RETAIN(Scale9Sprite*, _s9BackGround, Sprite9BackGround);
	CC_SYNTHESIZE_RETAIN(LabelTTF*, _ltTitle, LabelTitle);
	CC_SYNTHESIZE_RETAIN(LabelTTF*, _ltContentText, LabelContentText);
public:

};

#endif // __HELLOWORLD_SCENE_H__
