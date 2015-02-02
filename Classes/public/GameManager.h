<<<<<<< HEAD
=======
﻿/****************************************************** 
* Program Assignment : 游戏管理类
* Author : 刘建均 
* Date : 2015 / 1 / 26  21 : 59
* Description :
***************************************************** / 
/******************************************************* 
* Source code in :源文件路径
* Function List: 函数表
*******************************************************/
>>>>>>> origin/master
#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
#pragma once
#include <iostream>
#include "cocos2d.h"
<<<<<<< HEAD
#include "GameBaseScene.h"
=======
//#include "GameBaseScene.h"
#include "SeaScene.h"
>>>>>>> origin/master
class GameManager
{
public:
	GameManager();
	~GameManager();
static	GameManager* getInstance()
	{
		static GameManager* p = NULL;
		if (!p)
		{
			p = new GameManager();
		}
		return p;
	}


	cocos2d::Animate* player1AnimateLeft;
	cocos2d::Animate* player1AnimateRight;
	cocos2d::Animate* player1AnimateDown;
	cocos2d::Animate* player1AnimateUp;

<<<<<<< HEAD
	GameBase* gamebaselayer;

	//������ͣ����λ����map��
	cocos2d::Point _Player1Point;
=======
	cocos2d::Animate* player2AnimateLeft;
	cocos2d::Animate* player2AnimateRight;
	cocos2d::Animate* player2AnimateDown;
	cocos2d::Animate* player2AnimateUp;

	SeaScene* gamelayer;

	//玩家最后停留的位置在map里
	cocos2d::Point _Player1Point;//虽然名称是player1但是实际上是所有玩家公用的部分
>>>>>>> origin/master

};
#endif//_GAMEMANAGER_H
