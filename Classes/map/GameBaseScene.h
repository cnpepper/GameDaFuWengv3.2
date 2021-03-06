<<<<<<< HEAD
=======
﻿/****************************************************** 
* Program Assignment :  地图场景基类 
* Author : 刘建均 
* Date : 2015 / 1 / 26  21 : 59
* Description : 
***************************************************** / 
/******************************************************* 
* Source code in :源文件路径
* Function List: 函数表
*******************************************************/
>>>>>>> origin/master
#ifndef _GAMEBASE_SCENE_H__
#define _GAMEBASE_SCENE_H__

#include "cocos2d.h"
<<<<<<< HEAD
const int tableStartPosition_x = 650;
const int tableStartPosition_y = 450;
const int tableWidth = 50;
const int tableHeight = 40;

const int tiledWidth = 32;
const int tiledHeight = 32;

typedef enum MyEnum
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
}Direction;
typedef struct WayStruct
{
	cocos2d::Point _point;
} WAYSTRUCT;

=======
>>>>>>> origin/master
class GameBase : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    
    
    // implement the "static create()" method manually
	CREATE_FUNC(GameBase);
public:
<<<<<<< HEAD
	virtual void addGameMap();
	void initWayArry();
	void addPlayer();//������Ϸ��ɫ������Ϣ�ķ������ڿ�������ʵͷ���ʽ�����ֵ��
	virtual void initTiledGrid();
	void setWayPassToGrid();
	void onExit() override;
	void addGoButton();
	void addPlayerAnimation();
	void updata(float dt);
	cocos2d::Animate* getAnimatefordic(cocos2d::Vector<cocos2d::SpriteFrame* > &dicVec);
private:
	//һЩ����
	void drawTable(int playerNumber);//������ �������ý�ɫ
	void addRightBanner();//�����ұߵ�ͼ�հײ��ֱ������Ϸ�����������Ϣ
	void addUserControl();//�����û��������֣�����
	void addPlist();//����plist�ļ�
	
	void GoButtonCallBack();
	void addGameplayer();

	void DoGameElement();
public:
	//һЩ��Ա
	cocos2d::TMXTiledMap* _GameMap;
	cocos2d::Size _visibleSize;
	WAYSTRUCT _WayArry[15][20];
	int tiledColsCount;//�ؿ���ͼ�ܵ�����
	int tiledRowsCount;//�ؿ���ͼ�ܵ�����
	bool** canPassGrid;//���ݵ�ͼ���д�����ά����
	static int* p;
	cocos2d::CCMenu* _buttonMenu;//gobutton
	std::vector<cocos2d::Point> wayLayerPassVec;

	cocos2d::Sprite* _player1Sprite;
public:
	//����������߶���֡
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1UpAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1DownAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1LeftAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1RightAnim;
	//����һ���õ������ĺ���
	cocos2d::Animate* GetPlayerAnimate(int tag,float dt);
	void DoWalkWhitPlayer();
	int _ndic;
	cocos2d::Sprite* _diceSprite;
	int _player1front;
=======
>>>>>>> origin/master
};

#endif // _GAMEBASE_SCENE_H__
