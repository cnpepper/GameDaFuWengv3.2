<<<<<<< HEAD
=======
﻿/****************************************************** 
* Program Assignment :  滑动选择地图 
* Author : 刘建均 
* Date : 2015 / 1 / 20  21 : 59
* Description : 实现了触屏滑动选择的效果
***************************************************** / 
/******************************************************* 
* Source code in :源文件路径
* Function List: 函数表
* void singleTouchDown(CC2D::Object* pSender, CC2D::EXT::Control::EventType event);
* void addBackgroundSprite();//添加背景
* void addScrollview();//添加滑动对象及其包含的sprite
* void adjustScrollView(float distance);//自定义方法，用来进行拖动后的位置调整
*******************************************************/
>>>>>>> origin/master
#ifndef __MAPCHOOSE_SCENE_H__
#define __MAPCHOOSE_SCENE_H__

#include "cocos2d.h"
#include "GUI/CCScrollView/CCScrollView.h"
#include "GUI/CCControlExtension/CCControl.h"
#define CC2D cocos2d
#define EXT extension
<<<<<<< HEAD
//����һЩ����
const int MAP_COUNT = 3;//���������Źؿ�ͼƬ
const int TOUCH_DISTANCE = 50;//���ƻ�������
class MapChooseScene : public CC2D::Layer,CC2D::EXT::ScrollViewDelegate//ʹ�û�����Ҫ�̳������
=======
//定义一些常量
const int MAP_COUNT = 3;//定义了三张关卡图片
const int TOUCH_DISTANCE = 200;//手势滑动距离
class MapChooseScene : public CC2D::Layer,CC2D::EXT::ScrollViewDelegate//使用滑动需要继承这个类
>>>>>>> origin/master
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static CC2D::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
       
    // implement the "static create()" method manually
	CREATE_FUNC(MapChooseScene);
private:
<<<<<<< HEAD
	//����һЩ����
	void singleTouchDown(CC2D::Object* pSender, CC2D::EXT::Control::EventType event);
	void addBackgroundSprite();//��ӱ���
	void addScrollview();//��ӻ��������������sprite
	void adjustScrollView(float distance);//�Զ��巽�������������϶����λ�õ���

	//�̳���Ӧ�����ķ���
=======
	//定义一些方法
	void singleTouchDown(CC2D::Object* pSender, CC2D::EXT::Control::EventType event);
	void addBackgroundSprite();//添加背景
	void addScrollview();//添加滑动对象及其包含的sprite
	void adjustScrollView(float distance);//自定义方法，用来进行拖动后的位置调整

	//继承响应触屏的方法
>>>>>>> origin/master
	void onTouchEnded(CC2D::Touch *touch, CC2D::Event *unused_event);
	bool onTouchBegan(CC2D::Touch *touch, CC2D::Event *unused_event);
	void onTouchMoved(CC2D::Touch *touch, CC2D::Event *unused_event);

<<<<<<< HEAD
	//�̳� ScrollvewDelegate ����Ҫʵ�ֵ�3������
	void scrollViewDidScroll(CC2D::EXT::ScrollView* view) override;
	void scrollViewDidZoom(CC2D::EXT::ScrollView* view) override;
	//void scrollViewMoveOver(CC2D::EXT::ScrollView* view) override;
	//����һЩ��Ա
	CC2D::Size _visibleSize;
	CC2D::Layer* _spritesContainer; //���ڴ��3�Źؿ�ͼƬ��sprite����
	int _currentPage;//��ǰͼƬ�ǵڼ��Źؿ�
	CC2D::Point _beginTouchPoint;//����ʱ���µ�λ��
	CC2D::EXT::ScrollView* _scrollView;//��������ʵ��
=======
	//继承 ScrollvewDelegate 类需要实现的3个方法
	void scrollViewDidScroll(CC2D::EXT::ScrollView* view) override;
	void scrollViewDidZoom(CC2D::EXT::ScrollView* view) override;
	//void scrollViewMoveOver(CC2D::EXT::ScrollView* view) override;
	//定义一些成员
	CC2D::Size _visibleSize;
	CC2D::Layer* _spritesContainer; //用于存放3张关卡图片的sprite容器
	int _currentPage;//当前图片是第几张关卡
	CC2D::Point _beginTouchPoint;//触摸时按下的位置
	CC2D::EXT::ScrollView* _scrollView;//滑动对象实例
>>>>>>> origin/master
private:
	bool _bDoChoose;
};

#endif // __HELLOWORLD_SCENE_H__
