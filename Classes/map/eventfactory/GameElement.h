#ifndef _GAMEELEMENT_H
#define _GAMEELEMENT_H
#pragma once
#include "cocos2d.h"
#define CC2D cocos2d
<<<<<<< HEAD
#include "GameBaseScene.h"
class Operation:public CC2D::Layer
{
public:
	virtual void GetResult(GameBase* layer) = 0;
=======
//#include "GameBaseScene.h"
#include "SeaScene.h"
class Operation:public CC2D::Layer
{
public:
	virtual void GetResult(SeaScene* layer) = 0;
>>>>>>> origin/master
protected:
private:
};
class OperationHome :public Operation
{
public:
	OperationHome(){}
	OperationHome(int tag) :_tag(tag)
	{}
<<<<<<< HEAD
	void GetResult(GameBase* layer);
	void popupLayer(GameBase* layer);
=======
	void GetResult(SeaScene* layer);
	void popupLayer(SeaScene* layer);
>>>>>>> origin/master
	void quitButtonCallback(CC2D::Node *pNode);
protected:
private:
	int _tag;
};
<<<<<<< HEAD
=======
class OperationStock :public Operation
{
public:
	OperationStock(){}
	OperationStock(int tag) :_tag(tag)
	{}
	void GetResult(SeaScene* layer);
	//void popupLayer(SeaScene* layer);
	//void quitButtonCallback(CC2D::Node *pNode);
protected:
private:
	int _tag;
};
>>>>>>> origin/master
class GameElementFactroy
{
public:
	GameElementFactroy();
	~GameElementFactroy();
	static Operation* CreateOperate(int n)
	{
		switch (n)
		{
		case 0:
		case 4:
		case 5:
<<<<<<< HEAD
			return new OperationHome(n);//tag 为0的空地4是一级房屋5是二级房屋 都可以进入升级房屋
			break;
=======
		case 6:
		case 7:
		case 8:
		case 9:
			return new OperationHome(n);//tag 为0的空地4是一级房屋5是二级房屋 都可以进入升级房屋
			break;
		case 1:
		case 2:
		case 3:
			return new OperationStock(n);
			break;

>>>>>>> origin/master
		default:
			return NULL;
			break;
		}
	}
<<<<<<< HEAD

=======
>>>>>>> origin/master
};

#endif//_GAMEELEMENT_H

