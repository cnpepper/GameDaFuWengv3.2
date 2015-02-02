#ifndef _GAMEBASE_SCENE_H__
#define _GAMEBASE_SCENE_H__

#include "cocos2d.h"
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
	virtual void addGameMap();
	void initWayArry();
	void addPlayer();//添加游戏角色部分信息的方法，在控制栏现实头像，资金，体力值等
	virtual void initTiledGrid();
	void setWayPassToGrid();
	void onExit() override;
	void addGoButton();
	void addPlayerAnimation();
	void updata(float dt);
	cocos2d::Animate* getAnimatefordic(cocos2d::Vector<cocos2d::SpriteFrame* > &dicVec);
private:
	//一些方法
	void drawTable(int playerNumber);//画表格 用来放置角色，虚化
	void addRightBanner();//添加右边地图空白部分背景，上方放置人物信息，虚化
	void addUserControl();//添加用户操作部分，骰子，虚化
	void addPlist();//加载plist文件，移到loding中
	
	void GoButtonCallBack();//虚化或者放入子类
	void addGameplayer();

	void DoGameElement();//行走算法可保留或者放入玩家管理类中
public:
	//一些成员
	cocos2d::TMXTiledMap* _GameMap;
	cocos2d::Size _visibleSize;
	WAYSTRUCT _WayArry[15][20];
	int tiledColsCount;//关卡地图总的列数
	int tiledRowsCount;//关卡地图总的行数
	bool** canPassGrid;//根据地图行列创建二维数组
	static int* p;
	cocos2d::CCMenu* _buttonMenu;//gobutton
	std::vector<cocos2d::Point> wayLayerPassVec;

	cocos2d::Sprite* _player1Sprite;
public:
	//保存玩家行走动画帧
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1UpAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1DownAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1LeftAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1RightAnim;
	//定义一个拿到动画的函数
	cocos2d::Animate* GetPlayerAnimate(int tag,float dt);
	void DoWalkWhitPlayer();
	int _ndic;
	cocos2d::Sprite* _diceSprite;
	int _player1front;
};

#endif // _GAMEBASE_SCENE_H__
