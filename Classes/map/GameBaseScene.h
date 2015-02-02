<<<<<<< HEAD
=======
ï»¿/******************************************************Â 
*Â ProgramÂ AssignmentÂ :Â Â åœ°å›¾åœºæ™¯åŸºç±»Â 
*Â Author : åˆ˜å»ºå‡Â 
*Â Date : 2015 / 1 / 26Â Â 21 : 59
* Description : 
***************************************************** /Â 
/*******************************************************Â 
*Â SourceÂ codeÂ inÂ :æºæ–‡ä»¶è·¯å¾„
*Â FunctionÂ List:Â å‡½æ•°è¡¨
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
	void addPlayer();//Ìí¼ÓÓÎÏ·½ÇÉ«²¿·ÖĞÅÏ¢µÄ·½·¨£¬ÔÚ¿ØÖÆÀ¸ÏÖÊµÍ·Ïñ£¬×Ê½ğ£¬ÌåÁ¦ÖµµÈ
	virtual void initTiledGrid();
	void setWayPassToGrid();
	void onExit() override;
	void addGoButton();
	void addPlayerAnimation();
	void updata(float dt);
	cocos2d::Animate* getAnimatefordic(cocos2d::Vector<cocos2d::SpriteFrame* > &dicVec);
private:
	//Ò»Ğ©·½·¨
	void drawTable(int playerNumber);//»­±í¸ñ ÓÃÀ´·ÅÖÃ½ÇÉ«
	void addRightBanner();//Ìí¼ÓÓÒ±ßµØÍ¼¿Õ°×²¿·Ö±³¾°£¬ÉÏ·½·ÅÖÃÈËÎïĞÅÏ¢
	void addUserControl();//Ìí¼ÓÓÃ»§²Ù×÷²¿·Ö£¬÷»×Ó
	void addPlist();//¼ÓÔØplistÎÄ¼ş
	
	void GoButtonCallBack();
	void addGameplayer();

	void DoGameElement();
public:
	//Ò»Ğ©³ÉÔ±
	cocos2d::TMXTiledMap* _GameMap;
	cocos2d::Size _visibleSize;
	WAYSTRUCT _WayArry[15][20];
	int tiledColsCount;//¹Ø¿¨µØÍ¼×ÜµÄÁĞÊı
	int tiledRowsCount;//¹Ø¿¨µØÍ¼×ÜµÄĞĞÊı
	bool** canPassGrid;//¸ù¾İµØÍ¼ĞĞÁĞ´´½¨¶şÎ¬Êı×é
	static int* p;
	cocos2d::CCMenu* _buttonMenu;//gobutton
	std::vector<cocos2d::Point> wayLayerPassVec;

	cocos2d::Sprite* _player1Sprite;
public:
	//±£´æÍæ¼ÒĞĞ×ß¶¯»­Ö¡
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1UpAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1DownAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1LeftAnim;
	cocos2d::Vector<cocos2d::SpriteFrame* > VecPlayer1RightAnim;
	//¶¨ÒåÒ»¸öÄÃµ½¶¯»­µÄº¯Êı
	cocos2d::Animate* GetPlayerAnimate(int tag,float dt);
	void DoWalkWhitPlayer();
	int _ndic;
	cocos2d::Sprite* _diceSprite;
	int _player1front;
=======
>>>>>>> origin/master
};

#endif // _GAMEBASE_SCENE_H__
