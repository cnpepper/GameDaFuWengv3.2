#ifndef __GAME_BASE_SCENE_H__
#define __GAME_BASE_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ConstUtil.h"
#include "RicherPlayer.h"
#include "RouteNavigation.h"
#include "PopupLayer\PopupLayer.h"
#include "Util.h"

USING_NS_CC;
USING_NS_CC_EXT;

const int tableStartPosition_x = 650;
const int tableStartPosition_y = 450;
const int tableWidth = 50;
const int tableHeight = 40;
const int tiledWidth = 32;
const int tiledHeight = 32;
const int FONT_SIZE = 20;

const int Dialog_Size_Width = 400;
const int Dialog_Size_Height = 220;

const int Btn_OK_TAG = 1;
const int Btn_Cancel_TAG = 0;

class GameBaseScene: public Layer
{
public:
	static int tiledColsCount;
	static int tiledRowsCount;
	
	static bool** canPassGrid;

	static Vector<Sprite*> pathMarkVector;

	static int blank_land_tiledID;
	static int strength_30_tiledID;
	static int strength_50_tiledID;
	static int strength_80_tiledID;

	static int randomEvent_tiledID;
	static int lottery_tiledID;
	static int stock_tiledID;

	static int player1_building_1_tiledID;
	static int player1_building_2_tiledID;
	static int player1_building_3_tiledID;

	static int player2_building_1_tiledID;
	static int player2_building_2_tiledID;
	static int player2_building_3_tiledID;

	std::vector<Vec2> wayLayerPass_vector;

	RicherPlayer* player1;
	RicherPlayer* player2;
	RicherPlayer* player3;

    static Scene* createScene();
  	static TMXTiledMap* _map;
    virtual bool init();  
	virtual void addMap();
	virtual void initTiledGrid();
	void setWayPassToGrid();
	void onExit();

	void addPlayerAnimation();
	void goButtonCallback(CCObject* pSender);
    CREATE_FUNC(GameBaseScene);
	 
	static Vector<RicherPlayer*> players_vector;
	static void drawPathColor(std::vector<int> rowVector,std::vector<int> colVector);


	static TMXLayer* landLayer;

	void initLandLayerFromMap();

	virtual void initPropTiledID(); 
private:
	char money1[20];
	char money2[20];
	//CC_SYNTHESIZE(Vector<RicherPlayer*> ,players_vector,Players_vector);
	void drawTable(int playerNumber);
	void addPlayer();
	void addRightBanner();
	void addGoButton();
	void registerNotificationObserver();
	void receivedNotificationOMsg(Object* data);

	SpriteFrameCache* diceFrameCache;
	 CC_SYNTHESIZE(Menu*, _menu, Menu);
	 CC_SYNTHESIZE(LabelTTF *, player1_money_label, Player1_money_label);
     CC_SYNTHESIZE(LabelTTF *, player2_money_label, Player2_money_label);

	 CC_SYNTHESIZE(LabelTTF *, player1_strength_label, Player1_strength_label);
	 CC_SYNTHESIZE(LabelTTF *, player2_strength_label, Player2_strength_label);
	 
	 void addPlayerInfo();
	 void addDice();
	 CC_SYNTHESIZE(Animate *, dice_animate, Dice_animate);
	 CC_SYNTHESIZE(Sprite *, diceSprite, DiceSprite);
	int randNumber ;
	void addPathMark();
	
	Vector<SpriteFrame*>  digiteRoundVector;
	Vector<Sprite*> refreshRoundVector;
	int gameRoundCount;
	void refreshRoundDisplay();
	void addDigiteRoundSprite();


	void  showBuyLandDialog(int landTag);
	void buyLandCallback(Node *pNode);

	PopupLayer* popDialog;
	void initPopDialog();

	float buy_land_x;
	float buy_land_y;
	void sendMSGPickOneToGO(float dt);
	void doSomeForParticle();
	Sprite* circleSprite;

	ActionInterval * scaleby1ForBuyLand;  
	ActionInterval * scaleby2ForBuyLand;  
	Sprite* foot1Sprite;
	Sprite* foot2Sprite;
	Sprite* starFish1Sprite;
	Sprite* starFish2Sprite;
	Sprite* heart1Sprite;
	Sprite* heart2Sprite;
	FadeOut* landFadeOut;
	FadeIn* landFadeIn;
	Vector<Sprite*> displayVector;

	RicherPlayer* getPlayerByTiled(float x,float y);
	void refreshMoneyLabel(RicherPlayer* player,int money);
	void payTolls(int payTag,float x,float y ,int playerTag);
	void playParticle(Point point ,char* plistName);
	void buyLand(int buyTag,float x,float y ,Sprite* landSprite,int landLevel,RicherPlayer* player ,char* particlelistName);
	int displayArea(float x,float y,RicherPlayer* player,int building_1_tiledID,int building_2_tiledID,int building_3_tiledID);
};

#endif