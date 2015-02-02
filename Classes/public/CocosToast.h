<<<<<<< HEAD
/*
* node£ºÌí¼Ó¸ÃToast  layerµÄ¸¸½Úµã

* msg£ºÏÔÊ¾µÄÐÅÏ¢

* time£ºtoastÏÔÊ¾µÄÊ±¼ä³¤¶Ì

* point£ºtoastÏÔÊ¾µÄÎ»ÖÃ×ø±ê
=======
ï»¿/******************************************************Â 
*Â ProgramÂ AssignmentÂ :Â Â Toast æç¤ºæ¡†Â 
*Â Author : åˆ˜å»ºå‡Â 
*Â Date : 2015 / 1 / 26Â Â 21 : 59
* Description :
***************************************************** /Â 
/*******************************************************Â 
*Â SourceÂ codeÂ inÂ :æºæ–‡ä»¶è·¯å¾„
*Â FunctionÂ List:Â å‡½æ•°è¡¨
*******************************************************/
/*
* nodeï¼šæ·»åŠ è¯¥Toast  layerçš„çˆ¶èŠ‚ç‚¹

* msgï¼šæ˜¾ç¤ºçš„ä¿¡æ¯

* timeï¼štoastæ˜¾ç¤ºçš„æ—¶é—´é•¿çŸ­

* pointï¼štoastæ˜¾ç¤ºçš„ä½ç½®åæ ‡
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
