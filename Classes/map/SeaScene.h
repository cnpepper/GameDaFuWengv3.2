<<<<<<< HEAD
#ifndef _SEASCENE_H_
#define _SEASCENE_H_

#include "cocos2d.h"
#include "GameBaseScene.h"
=======
﻿/****************************************************** 
* Program Assignment :  海洋地图场景
* Author : 刘建均 
* Date : 2015 / 1 / 26  21 : 59
* Description :
***************************************************** / 
/******************************************************* 
* Source code in :源文件路径
* Function List: 函数表
*******************************************************/
#ifndef _SEA_SCENE_H__
#define _SEA_SCENE_H__

#include "cocos2d.h"
#include "GameBaseScene.h"
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

>>>>>>> origin/master
class SeaScene : public GameBase
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
<<<<<<< HEAD
    // implement the "static create()" method manually
	CREATE_FUNC(SeaScene);
public:
	void addGameMap() override;
};

#endif // _SEASCENE_H_
=======
    // a selector callback
    
    
    // implement the "static create()" method manually
	CREATE_FUNC(SeaScene);
public:
	void addGameMap();//添加瓦片地图，并初始化瓦片地图对象
	void addPlayer();//添加游戏角色部分信息的方法，绘制状态栏
	void onExit() override;//退出时候释放资源
	void addGoButton();//添加按钮 应该合并在addplayer中
	void addPlayerAnimation();//初始化动画 应该放在初始化loding场景中
	cocos2d::Animate* getAnimatefordic(cocos2d::Vector<cocos2d::SpriteFrame* > &dicVec);//把精灵帧生成动画对象 骰子的动画

	void initWayArry();//废弃
	void initTiledGrid();//废弃
	void setWayPassToGrid();//废弃
	
	
	
private:
	//一些方法
	void drawTable(int playerNumber);//画表格 用来放置角色，虚化
	void addRightBanner();//添加右边地图空白部分背景，上方放置人物信息，虚化
	void addUserControl();//添加用户操作部分，骰子，虚化
	void addPlist();//加载plist文件，移到loding中
	void updateWalk(float dt);//调度器的回调方法，里边是自动行走的算法暂时放在这里
	void GoButtonCallBack();//虚化或者放入子类
	void addGameplayer();

	void DoGameElement();//游戏时对于玩家每步走到的位置执行什么行为的处理方法

	//我要每一帧都更新一下玩家的状态
	void update(float dt) override;//重写父类的虚函数
public:
	//一些成员
	cocos2d::TMXTiledMap* _GameMap;
	cocos2d::Size _visibleSize;
	//下边这些废弃
	WAYSTRUCT _WayArry[15][20];
	int tiledColsCount;//关卡地图总的列数
	int tiledRowsCount;//关卡地图总的行数
	bool** canPassGrid;//根据地图行列创建二维数组
	std::vector<cocos2d::Point> wayLayerPassVec;
	//上边的是废弃的

	static int* p;
	cocos2d::CCMenu* _buttonMenu;//gobutton 为了让点击后隐藏


	cocos2d::Sprite* _player1Sprite;
	cocos2d::Sprite* _player2Sprite;
public:
	//保存玩家行走动画帧 应该放在玩家类里管理
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1UpAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1DownAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1LeftAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1RightAnim;

	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer2UpAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer2DownAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer2LeftAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer2RightAnim;

	//定义一个拿到动画的函数
	cocos2d::Animate* GetPlayerAnimate(int tag,float dt);
	void DoWalkWhitPlayer();//go 按钮的回调函数执行了一个调度器
	int _ndic;
	cocos2d::Sprite* _diceSprite;
	int _player1front;//任务方向
	int _player2front;//任务方向

	//
	cocos2d::LabelTTF *_player1Money;
	cocos2d::LabelTTF *_player2Money;
};

#endif // _GAMEBASE_SCENE_H__
>>>>>>> origin/master
