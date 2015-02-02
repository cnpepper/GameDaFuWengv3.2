<<<<<<< HEAD
=======
﻿/****************************************************** 
* Program Assignment :  玩家管理类
* Author : 刘建均 
* Date : 2015 / 1 / 26  21 : 59
* Description :
***************************************************** / 
/******************************************************* 
* Source code in :源文件路径
* Function List: 函数表
*******************************************************/
>>>>>>> origin/master
#ifndef _PLAYERMANAGER_H
#define _PLAYERMANAGER_H
#pragma once
#include "cocos2d.h"
<<<<<<< HEAD
=======
/************************************************************************/
/* Class Name ：
*  
*/
/************************************************************************/
>>>>>>> origin/master
class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();
	static PlayerManager* getInstance()
	{
		static PlayerManager* p = NULL;
		if (!p)
		{
			p = new PlayerManager;
		}
		return p;
	}
<<<<<<< HEAD
	int player1Money;
=======
	int _curPlayer;
	cocos2d::Sprite* _curPlayerSprite;
	//玩家1的属性
	int player1Money;
	//玩家2的属性
	int player2Money;
private:
	unsigned int m_nCurrentPlayerNum;//当前玩家数量


>>>>>>> origin/master
};
#endif//_PLAYERMANAGER_H

