<<<<<<< HEAD
/*
* node：添加该Toast  layer的父节点

* msg：显示的信息

* time：toast显示的时间长短

* point：toast显示的位置坐标
=======
锘�/******************************************************聽
*聽Program聽Assignment聽:聽聽Toast 鎻愮ず妗喡�
*聽Author : 鍒樺缓鍧嚶�
*聽Date : 2015 / 1 / 26聽聽21 : 59
* Description :
***************************************************** /聽
/*******************************************************聽
*聽Source聽code聽in聽:婧愭枃浠惰矾寰�
*聽Function聽List:聽鍑芥暟琛�
*******************************************************/
/*
* node锛氭坊鍔犺Toast  layer鐨勭埗鑺傜偣

* msg锛氭樉绀虹殑淇℃伅

* time锛歵oast鏄剧ず鐨勬椂闂撮暱鐭�

* point锛歵oast鏄剧ず鐨勪綅缃潗鏍�
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
