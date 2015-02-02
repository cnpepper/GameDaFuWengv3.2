#include "SeaScene.h"

USING_NS_CC;
<<<<<<< HEAD

=======
#include "ConstUtil.h"
#include "GameManager.h"
#include "CocosToast.h"
#include "GameElement.h"
#include "PlayerManager.h"
>>>>>>> origin/master
Scene* SeaScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = SeaScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SeaScene::init()
{
<<<<<<< HEAD
	addGameMap();
    //////////////////////////////
    // 1. super init first
    if ( !GameBase::init() )
=======
    //////////////////////////////
    // 1. super init first
	if (!GameBase::init())
>>>>>>> origin/master
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
<<<<<<< HEAD
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//GameBase::initWayArry();
	//GameBase::addPlayer();
    return true;
}

void SeaScene::addGameMap()
{
	GameBase::_GameMap = TMXTiledMap::create("map/sea.tmx");
	this->addChild(GameBase::_GameMap);
=======
	_visibleSize = visibleSize;
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//开启默认调度器
	

	addPlist();
	addGameMap();
	addRightBanner();//添加右侧的状态栏
	drawTable(2);//画状态栏中的分割线
	initTiledGrid();//初始化路线
	setWayPassToGrid();//初始化数组
	addPlayerAnimation();//添加人物动画，需要修改
	addPlayer();//添加人物
	addUserControl();//骰子
	addGoButton();//go按钮

	GameManager::getInstance()->gamelayer = this;
	Layer::scheduleUpdate();
    return true;
}


void SeaScene::drawTable(int playerNumber)
{
	auto ts = Director::getInstance()->getWinSize();
	auto tdraw = DrawNode::create();
	this->addChild(tdraw);

	for (int i = 0; i < playerNumber; i++)
	{
		tdraw->drawSegment(Vec2(tableStartPosition_x, tableStartPosition_y - 2 * i*tableHeight),
			Vec2(tableStartPosition_x + 3 * tableWidth, tableStartPosition_y - 2 * i*tableHeight), 1,
			Color4F(0, 1, 0, 1));

		tdraw->drawSegment(Vec2(tableStartPosition_x, tableStartPosition_y - 2 * (i + 1)*tableHeight),
			Vec2(tableStartPosition_x + 3 * tableWidth, tableStartPosition_y - 2 * (i + 1)*tableHeight), 1,
			Color4F(0, 1, 0, 1));

		tdraw->drawSegment(Vec2(tableStartPosition_x + tableWidth, tableStartPosition_y - tableHeight - 2 * i*tableHeight),
			Vec2(tableStartPosition_x + 3 * tableWidth, tableStartPosition_y - tableHeight - 2 * i*tableHeight), 1,
			Color4F(0, 1, 0, 1));

		tdraw->drawSegment(Vec2(tableStartPosition_x + tableWidth, tableStartPosition_y - 2 * i*tableHeight),
			Vec2(tableStartPosition_x + tableWidth, tableStartPosition_y - 2 * tableHeight - 2 * i*tableHeight), 1,
			Color4F(0, 1, 0, 1));
	}
	
}
void SeaScene::addPlayer()
{
	Sprite* player_me = Sprite::create(PLAYER_ME);
	player_me->setPosition(tableStartPosition_x + tableWidth / 2, tableStartPosition_y - tableHeight);	
	this->addChild(player_me,10);

	LabelTTF *player_me_money = LabelTTF::create();	player_me_money->setString("$");
	player_me_money->setAnchorPoint(ccp(0, 0.5)); player_me_money->setFontSize(25);
	player_me_money->setPosition(tableStartPosition_x + tableWidth, tableStartPosition_y - tableHeight / 2); 
	this->addChild(player_me_money,10);

	LabelTTF *player_me_strength = LabelTTF::create();
	player_me_strength->setString("+");
	player_me_strength->setAnchorPoint(ccp(0, 0.5));
	player_me_strength->setFontSize(28);
	player_me_strength->setPosition(tableStartPosition_x + tableWidth, tableStartPosition_y - tableHeight / 2 * 3); 
	this->addChild(player_me_strength,10);

	Sprite* player_enemy1 = Sprite::create(PLAYER_ENEMY1);
	player_enemy1->setPosition(tableStartPosition_x + tableWidth / 2, tableStartPosition_y - 3 * tableHeight);
	this->addChild(player_enemy1);

	LabelTTF* player_enemy1_money = LabelTTF::create();
	player_enemy1_money->setString("$");
	player_enemy1_money->setAnchorPoint(ccp(0, 0.5));
	player_enemy1_money->setFontSize(25);
	player_enemy1_money->setPosition(tableStartPosition_x + tableWidth, tableStartPosition_y - tableHeight / 2 * 5);
	this->addChild(player_enemy1_money,10);

	LabelTTF* player_enemy1_strength = LabelTTF::create();
	player_enemy1_strength->setString("+");
	player_enemy1_strength->setAnchorPoint(ccp(0, 0.5));
	player_enemy1_strength->setFontSize(28);
	player_enemy1_strength->setPosition(tableStartPosition_x + tableWidth, tableStartPosition_y - tableHeight / 2 * 7);
	this->addChild(player_enemy1_strength, 10);

	//添加玩家数据
	{
		_player1Money = LabelTTF::create();
		char buffer[32] = { 0 };
		int nMoney = PlayerManager::getInstance()->player1Money;
		sprintf(buffer, "%d", nMoney);
		_player1Money->setString(buffer);
		_player1Money->setAnchorPoint(ccp(0, 0.5)); _player1Money->setFontSize(20);
		_player1Money->setPosition(tableStartPosition_x + tableWidth + 15, tableStartPosition_y - tableHeight / 2);
		this->addChild(_player1Money, 10);
	}
	
	{
		_player2Money = LabelTTF::create();
		char buffer[32] = { 0 };
		int nMoney = PlayerManager::getInstance()->player2Money;
		sprintf(buffer, "%d", nMoney);
		_player2Money->setString(buffer);
		_player2Money->setAnchorPoint(ccp(0, 0.5)); _player2Money->setFontSize(20);
		_player2Money->setPosition(tableStartPosition_x + tableWidth+15, tableStartPosition_y - tableHeight / 2 * 5);
		this->addChild(_player2Money, 10);
	}


	addGameplayer();

	/*
	bool bt=false;
	Sprite* _spritePlayer1 = Sprite::createWithSpriteFrameName("player1_anim_01.png");
	_spritePlayer1->setAnchorPoint(CCPointZero);
	for (size_t i = 0; i < 15; ++i)
	{
		for (size_t j = 0; j < 20; ++j)
		{
			
			if (_WayArry[i][j]._point.x != 0 && _WayArry[i][j]._point.y != 0 )
			{
				_spritePlayer1->setPosition(_WayArry[i][j]._point);
				bt = true;
			}
		}
		if (bt)
		{
			break;
		}
	}
	this->addChild(_spritePlayer1,10);
	*/
	/*
	struct timeval now;
	gettimeofday(&now, NULL);
	unsigned rand_seed = (unsigned)(now.tv_sec * 1000 + now.tv_usec / 1000);    //都转化为毫秒 
	srand(rand_seed);
	player1 = RicherPlayer::create(PLAYER_1_NAME, PLAYER_1_TAG, false);
	int _rand1 = rand() % (wayLayerPass_vector.size());
	
	Vec2 vec2ForPlayer1 = wayLayerPass_vector.at(_rand1);
	vec2ForPlayer1.y += tiledHeight;
	player1->setPosition(vec2ForPlayer1);
	player1->setAnchorPoint(ccp(0, 0.5));
	int col = vec2ForPlayer1.x / tiledWidth;
	int row = vec2ForPlayer1.y / tiledHeight;
	*/
}
void SeaScene::addRightBanner()
{
	Sprite* rightBanner = Sprite::create(RIGHT_BANNER);
	rightBanner->setAnchorPoint(Point::ZERO);
	rightBanner->setPosition(Point(tableStartPosition_x, 0));
	this->addChild(rightBanner);
}
void SeaScene::addPlist()
{
	SpriteFrameCache* frameCache = SpriteFrameCache::sharedSpriteFrameCache();
	frameCache->addSpriteFramesWithFile(DICE_PLIST);
	frameCache->addSpriteFramesWithFile(PLAYER1_ANIM_PLIST);
	frameCache->addSpriteFramesWithFile(PLAYER2_ANIM_PLIST);
	//frameCache->addSpriteFramesWithFile();
	//frameCache->addSpriteFramesWithFile();
}
void SeaScene::addUserControl()
{
	_diceSprite = Sprite::createWithSpriteFrameName(DICE_PNG_1);
	//dice->setAnchorPoint(CCPointZero);
	_diceSprite->setPosition((800 - tableStartPosition_x) / 2 + tableStartPosition_x, _visibleSize.height / 2 - 150);
	_diceSprite->setScale(2.0f);
	this->addChild(_diceSprite,10);
}
void SeaScene::initWayArry()
{
	TMXLayer* ly = _GameMap->layerNamed("way");//获取图层
	Size mapSize = ly->getLayerSize();//获取图层的大小
	for (size_t i = 0; i < 15;++i)
	{
		for (size_t j = 0; j < 20; ++j)
		{
			int tag = ly->tileGIDAt(Point(j, i));//tileMap的原点在左下角
			if (tag != 0)
			{
				//获取point
				Sprite* sprite = ly->tileAt(Point(j,i));
				SeaScene::_WayArry[i][j]._point = sprite->getPosition();
				CCLOG("look");
			}
		}
	}
}
void SeaScene::initTiledGrid()
{
	tiledColsCount = 20;
	tiledRowsCount = 15;

	canPassGrid = new bool*[tiledRowsCount];

	for (size_t i = 0; i < tiledRowsCount; ++i)
	{
		canPassGrid[i] = new bool[tiledColsCount];
		memset(canPassGrid[i], 0, tiledColsCount*sizeof(bool));//初始化
	}

	
}
void SeaScene::setWayPassToGrid()
{
	TMXLayer* wayLayer = _GameMap->layerNamed("way");
	Size mapSize = wayLayer->getLayerSize();

	for (size_t j = 0; j < mapSize.width; j++)
	{
		for (size_t i = 0; i < mapSize.height; i++)
		{
			Sprite* sp = wayLayer->tileAt(Point(j, i));
			if (sp)
			{
				float x = sp->getPositionX();
				float y = sp->getPositionY();

				int col = x / tiledWidth;
				int row = y / tiledHeight;

				canPassGrid[row][col] = true;
				//取得位置坐标，保存到对象中
				Point p = sp->getPosition();
				wayLayerPassVec.push_back(p);

			}
		}
	}
}
void SeaScene::onExit()
{
	CC_SAFE_DELETE(canPassGrid);
	Layer::onExit();
}
void SeaScene::addGoButton()
{
// 	Sprite* goButton = Sprite::create("map/go_normal.png");
// 	goButton->setPosition(Point(tableStartPosition_x + 2 * tableWidth, tableStartPosition_y - tableHeight * 6));
	MenuItemImage* menu = MenuItemImage::create("map/go_normal.png", "map/go_press.png", CC_CALLBACK_0(SeaScene::GoButtonCallBack, this));
	_buttonMenu = CCMenu::createWithItem(menu);
	_buttonMenu->setAnchorPoint(CCPointZero);
	_buttonMenu->setPosition(Point(tableStartPosition_x + 2 * tableWidth-30, tableStartPosition_y - tableHeight * 6));
	this->addChild(_buttonMenu);
}

void SeaScene::addPlayerAnimation()
{
// 	Vector<SpriteFrame* > VecPlayer1UpAnim;
// 	Vector<SpriteFrame* > VecPlayer1DownAnim;
// 	Vector<SpriteFrame* > VecPlayer1LeftAnim;
// 	Vector<SpriteFrame* > VecPlayer1RightAnim;
	
	char name[20];
	memset(name, 0, 20);
	//左
	for (size_t i = 1; i <= 4; ++i)
	{
		sprintf(name,"player1_anim_0%d.png",i);
		VecPlayer1LeftAnim.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}
	//右
	for (size_t i = 5; i <= 8; ++i)
	{
		sprintf(name, "player1_anim_0%d.png", i);
		VecPlayer1RightAnim.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}
	//下
	for (size_t i = 9; i <= 12; ++i)
	{
		if (i == 9)
		{
			sprintf(name, "player1_anim_0%d.png", i);
		}
		else
		{
			sprintf(name, "player1_anim_%d.png", i);
		}
		
		VecPlayer1DownAnim.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}
	//上
	for (size_t i = 13; i <= 16; ++i)
	{
		sprintf(name, "player1_anim_%d.png", i);
		VecPlayer1UpAnim.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}


	//////////////////////////////////////////////////////////////////////////
	//左
	for (size_t i = 1; i <= 4; ++i)
	{
		sprintf(name, "player2_anim_0%d.png", i);
		VecPlayer2LeftAnim.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}
	//右
	for (size_t i = 5; i <= 8; ++i)
	{
		sprintf(name, "player2_anim_0%d.png", i);
		VecPlayer2RightAnim.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}
	//下
	for (size_t i = 9; i <= 12; ++i)
	{
		if (i == 9)
		{
			sprintf(name, "player2_anim_0%d.png", i);
		}
		else
		{
			sprintf(name, "player2_anim_%d.png", i);
		}

		VecPlayer2DownAnim.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}
	//上
	for (size_t i = 13; i <= 16; ++i)
	{
		sprintf(name, "player2_anim_%d.png", i);
		VecPlayer2UpAnim.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}

// 	Animation* player1AnimationLeft = Animation::createWithSpriteFrames(VecPlayer1LeftAnim, 0.1f);
// 	Animation* player1AnimationRight = Animation::createWithSpriteFrames(VecPlayer1RightAnim, 0.1f);
// 	Animation* player1AnimationDown = Animation::createWithSpriteFrames(VecPlayer1DownAnim, 0.1f);
// 	Animation* player1AnimationUp = Animation::createWithSpriteFrames(VecPlayer1UpAnim, 0.1f);
// 	GameManager* pt = GameManager::getInstance();
// 	pt->player1AnimateLeft = Animate::create(player1AnimationLeft);
// 	pt->player1AnimateRight = Animate::create(player1AnimationRight);
// 	pt->player1AnimateDown = Animate::create(player1AnimationDown);
// 	pt->player1AnimateUp = Animate::create(player1AnimationUp);

}
Animate* SeaScene::GetPlayerAnimate(int tag, float dt)
{
	int player = PlayerManager::getInstance()->_curPlayer;
	Animation* player1Animation = NULL;
	if (tag == UP)
	{
		if (1 == player)
		{
			player1Animation = Animation::createWithSpriteFrames(VecPlayer1UpAnim, dt);
		}
		else if (2 == player)
		{
			player1Animation = Animation::createWithSpriteFrames(VecPlayer2UpAnim, dt);
		}
		
		return Animate::create(player1Animation);

	}
	else if (tag == DOWN)
	{
		if (1 == player)
		{
			player1Animation = Animation::createWithSpriteFrames(VecPlayer1DownAnim, dt);
		}
		else if (2 == player)
		{
			player1Animation = Animation::createWithSpriteFrames(VecPlayer2DownAnim, dt);
		}
		return Animate::create(player1Animation);
	}
	else if (tag == LEFT)
	{
		if (1 == player)
		{
			player1Animation = Animation::createWithSpriteFrames(VecPlayer1LeftAnim, dt);
		}
		else if (2 == player)
		{
			player1Animation = Animation::createWithSpriteFrames(VecPlayer2LeftAnim, dt);
		}
		return Animate::create(player1Animation);
	}
	else if (tag == RIGHT)
	{
		if (1 == player)
		{
			player1Animation = Animation::createWithSpriteFrames(VecPlayer1RightAnim, dt);
		}
		else if (2 == player)
		{
			player1Animation = Animation::createWithSpriteFrames(VecPlayer2RightAnim, dt);
		}
		return Animate::create(player1Animation);
	}
	
}
void SeaScene::DoGameElement()
{
	CCLOG("laksjdlaskdlasdlasdjalsd");
	//获取当前地图的tag标签
	int ntag = -1;
	TMXLayer* ly = _GameMap->getLayer("way");
	int nGid = ly->getTileGIDAt(GameManager::getInstance()->_Player1Point);
	if (nGid)
	{
		auto TiledMap = _GameMap->getPropertiesForGID(nGid).asValueMap();
		if (!TiledMap.empty())
		{
			ntag = TiledMap["tag"].asInt();
		}
	}

	GameElementFactroy factroy;
	Operation* operation =  factroy.CreateOperate(ntag);
	if (operation)
	{
		operation->GetResult(this);
	}
	
}
void SeaScene::updateWalk(float dt)
{
	int playerfront = 0;
	int curplayer = PlayerManager::getInstance()->_curPlayer;
	if ( 1 == curplayer )
	{
		playerfront = _player1front;
	}
	else if ( 2 == curplayer )
	{
		playerfront = _player2front;
	}
	
	do 
	{
		if (--_ndic == -2)
		{
			Show* show = Show::create();
			CallFunc* callfunc = CallFunc::create(CC_CALLBACK_0(SeaScene::DoGameElement, this));
			Sequence* sequence = Sequence::create(callfunc, show, NULL);
			_buttonMenu->runAction(sequence);
			break;
		}
		Sprite* curplayer = PlayerManager::getInstance()->_curPlayerSprite;
		TMXLayer* wayLayer = _GameMap->layerNamed("way");
		int x = curplayer->getPositionX() / 32;
		int y = (32 * 14 - curplayer->getPositionY()) / 32;
		int nGid = wayLayer->getTileGIDAt(Point(x, y));

		if (playerfront == Direction::UP)
		{
			if (wayLayer->getTileGIDAt(Point(x, y - 1)))//在瓦片地图中使用图块获取地图的时候要使用瓦片的图的坐标系
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x,y-1);
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX(), curplayer->getPositionY() + 32)));
				Animate* player1Animate = GetPlayerAnimate(UP, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);
			
			}
			else if (wayLayer->getTileGIDAt(Point(x + 1, y)))
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x+1, y);
				//如果进入这个分支是向右转，把玩家方向设置成右
				playerfront = RIGHT;
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX() + 32, curplayer->getPositionY())));
				Animate* player1Animate = GetPlayerAnimate(RIGHT, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);

			}
			else if (wayLayer->getTileGIDAt(Point(x - 1, y)))
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x-1, y);
				//如果进入这个分支是向左转，把玩家方向设置成左
				playerfront = LEFT;
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX() - 32, curplayer->getPositionY())));
				Animate* player1Animate = GetPlayerAnimate(LEFT, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);
			}
		}
		else if (playerfront == Direction::DOWN)
		{
			if (wayLayer->getTileGIDAt(Point(x, y + 1)))
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x, y + 1);
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX(), curplayer->getPositionY() - 32)));
				Animate* player1Animate = GetPlayerAnimate(DOWN, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);
			}
			else if (wayLayer->getTileGIDAt(Point(x + 1, y)))
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x+1, y);
				//如果进入这个分支是向右转，把玩家方向设置成右
				playerfront = RIGHT;
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX() + 32, curplayer->getPositionY())));
				Animate* player1Animate = GetPlayerAnimate(RIGHT, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);
			}
			else if (wayLayer->getTileGIDAt(Point(x - 1, y)))
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x-1, y);
				//如果进入这个分支是向左转，把玩家方向设置成左
				playerfront = LEFT;
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX() - 32, curplayer->getPositionY())));
				Animate* player1Animate = GetPlayerAnimate(LEFT, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);
			}
		}
		else if (playerfront == Direction::LEFT)
		{
			if (wayLayer->getTileGIDAt(Point(x - 1, y)))
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x-1, y);
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX() - 32, curplayer->getPositionY())));
				Animate* player1Animate = GetPlayerAnimate(LEFT, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);
			}
			else if (wayLayer->getTileGIDAt(Point(x, y + 1)))
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x, y + 1);
				//如果进入这个分支是向左转，把玩家方向设置成左
				playerfront = DOWN;
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX(), curplayer->getPositionY() - 32)));
				Animate* player1Animate = GetPlayerAnimate(DOWN, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);
			}
			else if (wayLayer->getTileGIDAt(Point(x, y - 1)))
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x, y - 1);
				//如果进入这个分支是向左转，把玩家方向设置成左
				playerfront = UP;
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX(), curplayer->getPositionY() + 32)));
				Animate* player1Animate = GetPlayerAnimate(UP, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);
			}
		}
		else if (playerfront == Direction::RIGHT)
		{
			if (wayLayer->getTileGIDAt(Point(x + 1, y)))
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x+1, y);
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX() + 32, curplayer->getPositionY())));
				Animate* player1Animate = GetPlayerAnimate(RIGHT, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);
			}
			else if (wayLayer->getTileGIDAt(Point(x, y + 1)))
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x, y + 1);
				//如果进入这个分支是向下转，把玩家方向设置成下
				playerfront = DOWN;
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX(), curplayer->getPositionY() - 32)));
				Animate* player1Animate = GetPlayerAnimate(DOWN, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);
			}
			else if (wayLayer->getTileGIDAt(Point(x, y - 1)))
			{
				//保存玩家走到了哪个位置
				GameManager::getInstance()->_Player1Point = Point(x, y - 1);
				//如果进入这个分支是向上转，把玩家方向设置成上
				playerfront = UP;
				MoveTo* moveto = MoveTo::create(0.8f, Point(Point(curplayer->getPositionX(), curplayer->getPositionY() + 32)));
				Animate* player1Animate = GetPlayerAnimate(UP, 0.2f);
				Spawn* spawn = Spawn::create(moveto, player1Animate, NULL);//两个动作同时进行
				curplayer->runAction(spawn);
			}
		}
	} while (0);

	if (1 == curplayer)
	{
		_player1front = playerfront;
	}
	else if (2 == curplayer)
	{
		_player2front = playerfront;
	}
}
Animate* SeaScene::getAnimatefordic(Vector<SpriteFrame* > &dicVec)
{
	Animation* dicAnimation = Animation::createWithSpriteFrames(dicVec, 0.2f);
	return Animate::create(dicAnimation);
	
}
void SeaScene::GoButtonCallBack()
{

	//根据当前玩家标识，设置当前玩家的精灵
	int player = PlayerManager::getInstance()->_curPlayer;
	if (1 == player)
	{
		PlayerManager::getInstance()->_curPlayer = 2;
		PlayerManager::getInstance()->_curPlayerSprite = _player2Sprite;
	}
	else if (2 == player)
	{
		PlayerManager::getInstance()->_curPlayer = 1;
		PlayerManager::getInstance()->_curPlayerSprite = _player1Sprite;
	}
	Hide* hide = Hide::create();
	_buttonMenu->runAction(hide);

	Vector<SpriteFrame* > dicVec;
	char name[20] = {0};
	for (int n = 0; n < 10;++n)
	{
		_ndic = rand() % 6;
		sprintf(name, "dice_0%d.png", _ndic + 1);
		dicVec.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}
	srand(time_t(NULL));
	_ndic = rand() % 6;
	sprintf(name, "dice_0%d.png", _ndic + 1);
	dicVec.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));

	Animate* dicAnimate = getAnimatefordic(dicVec);
	auto dicCallFunc = CallFuncN::create(CC_CALLBACK_0(SeaScene::DoWalkWhitPlayer, this));//create里边必须用CC_ALLBACK
	Sequence* dicquence = Sequence::create(dicAnimate,dicCallFunc ,NULL);
	_diceSprite->runAction(dicquence);
	
}
void SeaScene::DoWalkWhitPlayer()
{
	schedule(schedule_selector(SeaScene::updateWalk), 1.0f, _ndic + 1, 0);//第一个参数的调用函数是有固定格式的，返回值为void 带一个float参数
}
void SeaScene::addGameplayer()
{
	//设置人物坐标
	_player1Sprite = Sprite::createWithSpriteFrameName("player1_anim_09.png");
	_player1Sprite->setAnchorPoint(CCPointZero);
	_player1Sprite->setPosition(wayLayerPassVec[3]);
	this->addChild(_player1Sprite);
	_player1front = Direction::DOWN;
	
	//设置人物坐标
	_player2Sprite = Sprite::createWithSpriteFrameName("player2_anim_09.png");
	_player2Sprite->setAnchorPoint(CCPointZero);
	_player2Sprite->setPosition(wayLayerPassVec[20]);
	this->addChild(_player2Sprite);
	_player2front = Direction::DOWN;

}
void SeaScene::addGameMap()
{
	_GameMap = TMXTiledMap::create("map/sea.tmx");
	this->addChild(_GameMap);
}
void SeaScene::update(float dt)
{
	//更新游戏数据
	if (_player1Money!=NULL)
	{
		char buffer[32] = { 0 };
		int nMoney = PlayerManager::getInstance()->player1Money;
		sprintf(buffer, "%d", nMoney);
		_player1Money->setString(buffer);
	}
	//更新游戏数据
	if (_player2Money != NULL)
	{
		char buffer[32] = { 0 };
		int nMoney = PlayerManager::getInstance()->player2Money;
		sprintf(buffer, "%d", nMoney);
		_player2Money->setString(buffer);
	}

>>>>>>> origin/master
}