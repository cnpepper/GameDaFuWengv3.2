<<<<<<< HEAD
/*
* node����Ӹ�Toast  layer�ĸ��ڵ�

* msg����ʾ����Ϣ

* time��toast��ʾ��ʱ�䳤��

* point��toast��ʾ��λ������
=======
﻿/****************************************************** 
* Program Assignment :  Toast 提示框 
* Author : 刘建均 
* Date : 2015 / 1 / 26  21 : 59
* Description :
***************************************************** / 
/******************************************************* 
* Source code in :源文件路径
* Function List: 函数表
*******************************************************/
/*
* node：添加该Toast  layer的父节点

* msg：显示的信息

* time：toast显示的时间长短

* point：toast显示的位置坐标
>>>>>>> origin/master

*/

#ifndef _COCOSTOAST_H
#define _COCOSTOAST_H

#pragma once
#include <iostream>
#include "cocos2d.h"
<<<<<<< HEAD
#include "extensions/cocos-ext.h"
=======
#include "cocos-ext.h"
>>>>>>> origin/master
#define CC2D cocos2d
#define EXT extension


class CocosToast:public CC2D::LayerColor
{
public:
	CocosToast();
	~CocosToast();
	static void createToast(Node* node,const std::string& msg,const float &time,CC2D::Point point);
	void removeToast(Node* node);
};
#endif//_COCOSTOAST_H
