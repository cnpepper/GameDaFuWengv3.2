#include "GameBaseScene.h"

	 int GameBaseScene::tiledColsCount;
	 int GameBaseScene::tiledRowsCount;
	 bool** GameBaseScene::canPassGrid;
	 Vector<RicherPlayer*>  GameBaseScene::players_vector;
	 Vector<Sprite*> GameBaseScene::pathMarkVector;
	 TMXLayer* GameBaseScene::landLayer;
	 TMXTiledMap* GameBaseScene::_map;

     int  GameBaseScene::blank_land_tiledID;
	 int  GameBaseScene::strength_30_tiledID;
	 int  GameBaseScene::strength_50_tiledID;
	 int  GameBaseScene::strength_80_tiledID;

	 int  GameBaseScene::randomEvent_tiledID;
	 int  GameBaseScene::lottery_tiledID;
	 int  GameBaseScene::stock_tiledID;

	int GameBaseScene::player1_building_1_tiledID;
	int GameBaseScene::player1_building_2_tiledID;
	int GameBaseScene::player1_building_3_tiledID;

	int GameBaseScene::player2_building_1_tiledID;
	int GameBaseScene::player2_building_2_tiledID;
	int GameBaseScene::player2_building_3_tiledID;


Scene* GameBaseScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameBaseScene::create();

	scene->addChild(layer);

	return scene;

}


bool GameBaseScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	addMap();
	initTiledGrid();
	setWayPassToGrid();
	addRightBanner();
	drawTable(2);
	addPathMark();
	addPlayer();
	addGoButton();
	registerNotificationObserver();
	addDice();
	addDigiteRoundSprite();
	refreshRoundDisplay();
	initLandLayerFromMap();
	initPropTiledID();
	initPopDialog();
	doSomeForParticle();
	return true;
}

void GameBaseScene::doSomeForParticle()
{
	landFadeOut = FadeOut::create(0.1);
	landFadeIn = FadeIn::create(0.1);
	landFadeOut->retain();
	landFadeIn->retain();	

	scaleby1ForBuyLand = ScaleBy::create(0.1, 1.5);  
	scaleby2ForBuyLand = ScaleBy::create(0.5, 0.7);  
	scaleby1ForBuyLand->retain();
	scaleby2ForBuyLand->retain();		
	foot1Sprite = Sprite::create(PLAYER1_1_PARTICLE_PNG);
	addChild(foot1Sprite);
	foot1Sprite->setAnchorPoint(ccp(0,0));

	foot2Sprite = Sprite::create(PLAYER2_1_PARTICLE_PNG);
	addChild(foot2Sprite);
	foot2Sprite->setAnchorPoint(ccp(0,0));

	starFish1Sprite = Sprite::create(PLAYER1_2_PARTICLE_PNG);
	addChild(starFish1Sprite);
	starFish1Sprite->setAnchorPoint(ccp(0,0));

	starFish2Sprite = Sprite::create(PLAYER2_2_PARTICLE_PNG);
	addChild(starFish2Sprite);
	starFish2Sprite->setAnchorPoint(ccp(0,0));

	heart1Sprite = Sprite::create(PLAYER1_3_PARTICLE_PNG);
	addChild(heart1Sprite);
	heart1Sprite->setAnchorPoint(ccp(0,0));

	heart2Sprite = Sprite::create(PLAYER2_3_PARTICLE_PNG);
	addChild(heart2Sprite);
	heart2Sprite->setAnchorPoint(ccp(0,0));


}


void GameBaseScene::initPopDialog()
{
	popDialog = PopupLayer::create(DIALOG_BG);
	
    popDialog->setContentSize(CCSizeMake(Dialog_Size_Width, Dialog_Size_Height)); 
    popDialog->setTitle(DIALOG_TITLE);
	popDialog->setContentText("", 20, 60, 250);
    popDialog->setCallbackFunc(this, callfuncN_selector(GameBaseScene::buyLandCallback));

    popDialog->addButton(BUTTON_BG1, BUTTON_BG3, OK, Btn_OK_TAG);
    popDialog->addButton(BUTTON_BG2, BUTTON_BG3, CANCEL, Btn_Cancel_TAG);
    this->addChild(popDialog);
	popDialog->setVisible(false);
}

void GameBaseScene::initLandLayerFromMap()
{
	landLayer = _map->layerNamed("land");
}

void GameBaseScene::addDigiteRoundSprite()
{
	gameRoundCount=0;
	auto frameCache = SpriteFrameCache::getInstance();
    frameCache->addSpriteFramesWithFile("map/digital_round.plist");

	digiteRoundVector.pushBack(frameCache->getSpriteFrameByName(DIGITAL_0));
	digiteRoundVector.pushBack(frameCache->getSpriteFrameByName(DIGITAL_1));
	digiteRoundVector.pushBack(frameCache->getSpriteFrameByName(DIGITAL_2));
	digiteRoundVector.pushBack(frameCache->getSpriteFrameByName(DIGITAL_3));
	digiteRoundVector.pushBack(frameCache->getSpriteFrameByName(DIGITAL_4));
	digiteRoundVector.pushBack(frameCache->getSpriteFrameByName(DIGITAL_5));
	digiteRoundVector.pushBack(frameCache->getSpriteFrameByName(DIGITAL_6));
	digiteRoundVector.pushBack(frameCache->getSpriteFrameByName(DIGITAL_7));
	digiteRoundVector.pushBack(frameCache->getSpriteFrameByName(DIGITAL_8));
	digiteRoundVector.pushBack(frameCache->getSpriteFrameByName(DIGITAL_9));

}

void GameBaseScene::refreshRoundDisplay()
{

	for(auto it = refreshRoundVector.begin();it != refreshRoundVector.end();it++)
	{
		((Sprite*) *it)->setVisible(false);
	}

	refreshRoundVector.clear();
	int count = gameRoundCount;
	Sprite* st;

	if(count ==0 )
	{
		st = Sprite::createWithSpriteFrame(digiteRoundVector.at(0));
		addChild(st);
		refreshRoundVector.pushBack(st);
	}
	while(count!=0)
	{
		st = Sprite::createWithSpriteFrame(digiteRoundVector.at(count%10));
		addChild(st);
		refreshRoundVector.pushBack(st);
		count = count/10;

	}
	refreshRoundVector.reverse();

	for(int i = 0;i< refreshRoundVector.size();i++)
	{
		Sprite * sp = refreshRoundVector.at(i);
		sp->setPosition(ccp((tableStartPosition_x+50)+(i*25),50));
		sp->setVisible(true);
	}

}

void GameBaseScene::addPathMark()
{
	
	Sprite* mark1 = Sprite::create(PATH_MARK_1);
	Sprite* mark2 = Sprite::create(PATH_MARK_2);
	Sprite* mark3 = Sprite::create(PATH_MARK_3);
	Sprite* mark4 = Sprite::create(PATH_MARK_4);
	Sprite* mark5 = Sprite::create(PATH_MARK_5);
	Sprite* mark6 = Sprite::create(PATH_MARK_6);


	mark1->setAnchorPoint(ccp(0,0));
	mark2->setAnchorPoint(ccp(0,0));
	mark3->setAnchorPoint(ccp(0,0));
	mark4->setAnchorPoint(ccp(0,0));
	mark5->setAnchorPoint(ccp(0,0));
	mark6->setAnchorPoint(ccp(0,0));

	mark1->setVisible(false);
	mark2->setVisible(false);
	mark3->setVisible(false);
	mark4->setVisible(false);
	mark5->setVisible(false);
	mark6->setVisible(false);


	addChild(mark1);
	addChild(mark2);
	addChild(mark3);
	addChild(mark4);
	addChild(mark5);
	addChild(mark6);

	pathMarkVector.pushBack(mark1);
	pathMarkVector.pushBack(mark2);
	pathMarkVector.pushBack(mark3);
	pathMarkVector.pushBack(mark4);
	pathMarkVector.pushBack(mark5);
	pathMarkVector.pushBack(mark6);
}

void GameBaseScene::drawPathColor(std::vector<int> rowVector,std::vector<int> colVector)
{
	int stepsCount = rowVector.size()-1;

	for(int i=1;i<rowVector.size();i++)
	{
		pathMarkVector.at(i-1)->setPosition(ccp(colVector[i]*32,rowVector[i]*32));
		pathMarkVector.at(i-1)->setVisible(true);
	}
}

void GameBaseScene::addDice()
{
	diceFrameCache= SpriteFrameCache::getInstance();
	diceFrameCache->addSpriteFramesWithFile("map/dice.plist","map/dice.png");
	Vector<SpriteFrame*> diceVector ;

	char name[20];
	memset(name, 0, 20);
	for (int i=1; i<=6; i++) 
	{
		sprintf(name, "dice_%02d.png",i);
		diceVector.pushBack(diceFrameCache->getSpriteFrameByName(name));
	}

	if(!AnimationCache::getInstance()->getAnimation("dice_animation"))
	{
		AnimationCache::getInstance()->addAnimation(Animation::createWithSpriteFrames(diceVector,0.1),"dice_animation");
	}
	dice_animate = Animate::create(AnimationCache::getInstance()->getAnimation("dice_animation"));
	dice_animate->retain();
		
	diceSprite =Sprite::createWithSpriteFrame(diceFrameCache->getSpriteFrameByName("dice_01.png"));
	diceSprite->setPosition(ccp(tableStartPosition_x+2*tableWidth,tableStartPosition_y-tableHeight*4.5));
	addChild(diceSprite);

	diceSprite->runAction(RepeatForever::create(dice_animate));

}

void GameBaseScene::registerNotificationObserver()
{
	NotificationCenter::getInstance()->addObserver(
		this,
		callfuncO_selector(GameBaseScene::receivedNotificationOMsg),
		MSG_GO,
		NULL);

	NotificationCenter::getInstance()->addObserver(
		this,
		callfuncO_selector(GameBaseScene::receivedNotificationOMsg),
		MSG_BUY,
		NULL);

	NotificationCenter::getInstance()->addObserver(
		this,
		callfuncO_selector(GameBaseScene::receivedNotificationOMsg),
		MSG_PAY_TOLLS,
		NULL);	
}

void  GameBaseScene::showBuyLandDialog(int landTag)
{
	String showMessage = "";
	switch(landTag)
	{
	case MSG_BUY_BLANK_TAG:
		{
			showMessage = String::createWithFormat("Do you want to buy the land ? need $ %d",LAND_BLANK_MONEY)->getCString();
			//showMessage = "Do you want to buy the land ? need $1000 ";
			break;
		}
	case MSG_BUY_LAND_1_TAG:
		{
			showMessage = String::createWithFormat("Do you want to buy the land ? need $ %d",LAND_LEVEL_1_MONEY)->getCString();
			break;
		}
	case MSG_BUY_LAND_2_TAG:
		{
			showMessage = String::createWithFormat("Do you want to buy the land ? need $ %d",LAND_LEVEL_2_MONEY)->getCString();
			break;
		}
	}
	popDialog->setDataTag(landTag);
	popDialog->getLabelContentText()->setString(showMessage.getCString());
	popDialog->setVisible(true);

}

void GameBaseScene::buyLandCallback(Node *pNode)
{
	if(pNode->getTag() == Btn_OK_TAG)
	{
		switch(popDialog->getDataTag())
		{
			case MSG_BUY_BLANK_TAG:
				{
					buyLand(MSG_BUY_BLANK_TAG,buy_land_x,buy_land_y,foot1Sprite,player1_building_1_tiledID,player1,PLAYER1_1_PARTICLE_PLIST);
	
					log( "need $1000 ");
					break;
				}
			case MSG_BUY_LAND_1_TAG:
				{
					buyLand(MSG_BUY_LAND_1_TAG,buy_land_x,buy_land_y,starFish1Sprite,player1_building_2_tiledID,player1,PLAYER1_1_PARTICLE_PLIST);

					log( "need $2000 ");					
					break;
				}
			case MSG_BUY_LAND_2_TAG:
				{
					buyLand(MSG_BUY_LAND_2_TAG,buy_land_x,buy_land_y,heart1Sprite,player1_building_3_tiledID,player1,PLAYER1_1_PARTICLE_PLIST);

					log( "need $3000 ");					
					break;
				}
		}
		popDialog->setVisible(false);
		this->scheduleOnce(schedule_selector( GameBaseScene::sendMSGPickOneToGO),1.0f);	
		log("Btn_OK_TAG");
	}else
	{
		popDialog->setVisible(false);
		NotificationCenter::getInstance()->postNotification(MSG_PICKONE_TOGO,String::createWithFormat("%d",MSG_PICKONE_TOGO_TAG));
	}
	
}

void GameBaseScene::sendMSGPickOneToGO(float dt)
{
	NotificationCenter::getInstance()->postNotification(MSG_PICKONE_TOGO,String::createWithFormat("%d",MSG_PICKONE_TOGO_TAG));
}

void  GameBaseScene::playParticle(Point point ,char* plistName)
{
	ParticleSystem* particleSystem_foot = ParticleSystemQuad::create(plistName);
	particleSystem_foot->retain();
	ParticleBatchNode *batch = ParticleBatchNode::createWithTexture(particleSystem_foot->getTexture());
	batch->addChild(particleSystem_foot);	
	addChild(batch);

	particleSystem_foot->setPosition( point + ccp(tiledWidth/2,tiledHeight/2));										
	particleSystem_foot->release();
	

}

void GameBaseScene::receivedNotificationOMsg(Object* data)
{
	String * srcDate = (String*)data;
	Vector<String*> messageVector = Util::splitString(srcDate->getCString(),"-");
	int retMsgType = messageVector.at(0)->intValue();
	Vector<Node*> vecMenuItem = getMenu()->getChildren();
	log("received go message is: %d",retMsgType);

	switch(retMsgType)
	{
	case MSG_BUY_BLANK_TAG:
		{
			buy_land_x = messageVector.at(1)->floatValue();
			buy_land_y = messageVector.at(2)->floatValue();
			int playerTag = messageVector.at(3)->intValue();
			
			switch(playerTag)
			{
				case PLAYER_1_TAG:
				{
					showBuyLandDialog(MSG_BUY_BLANK_TAG);
					break;
				}
				case PLAYER_2_TAG:
				{
					buyLand(MSG_BUY_BLANK_TAG,buy_land_x,buy_land_y,foot2Sprite,player2_building_1_tiledID,player2,PLAYER2_1_PARTICLE_PLIST);
					NotificationCenter::getInstance()->postNotification(MSG_PICKONE_TOGO,String::createWithFormat("%d",MSG_PICKONE_TOGO_TAG));			
					break;
				}				
			}
			break;
		}
		case MSG_BUY_LAND_1_TAG:
		{
			buy_land_x = messageVector.at(1)->floatValue();
			buy_land_y = messageVector.at(2)->floatValue();
			int playerTag = messageVector.at(3)->intValue();
			
			switch(playerTag)
			{
				case PLAYER_1_TAG:
				{
					showBuyLandDialog(MSG_BUY_LAND_1_TAG);
					break;
				}
				case PLAYER_2_TAG:
				{
					buyLand(MSG_BUY_LAND_1_TAG,buy_land_x,buy_land_y,starFish2Sprite,player2_building_2_tiledID,player2,PLAYER2_1_PARTICLE_PLIST);
					NotificationCenter::getInstance()->postNotification(MSG_PICKONE_TOGO,String::createWithFormat("%d",MSG_PICKONE_TOGO_TAG));

					break;
				}				
			}
			break;
		}	
		case MSG_BUY_LAND_2_TAG:
		{
			buy_land_x = messageVector.at(1)->floatValue();
			buy_land_y = messageVector.at(2)->floatValue();
			int playerTag = messageVector.at(3)->intValue();
			
			switch(playerTag)
			{
				case PLAYER_1_TAG:
				{
					showBuyLandDialog(MSG_BUY_LAND_2_TAG);
					break;
				}
				case PLAYER_2_TAG:
				{
					buyLand(MSG_BUY_LAND_2_TAG,buy_land_x,buy_land_y,heart2Sprite,player2_building_3_tiledID,player2,PLAYER2_1_PARTICLE_PLIST);
					NotificationCenter::getInstance()->postNotification(MSG_PICKONE_TOGO,String::createWithFormat("%d",MSG_PICKONE_TOGO_TAG));

					break;
				}				
			}
			break;
		}


	case MSG_GO_SHOW_TAG:
		{
			for(auto it=vecMenuItem.begin();it!=vecMenuItem.end();it++)
			{
				Node* node = dynamic_cast<Node*>(*it);
				MoveBy* moveBy = MoveBy::create(0.3,ccp(-(node->getContentSize().width)*2,0));
				node->runAction(moveBy);
		
			}
			diceSprite->resume();
			gameRoundCount++;
			refreshRoundDisplay();
			break;
		}
	case  MSG_GO_HIDE_TAG:
		{
			for(auto it=vecMenuItem.begin();it!=vecMenuItem.end();it++)
			{
				Node* node = dynamic_cast<Node*>(*it);
				MoveBy* moveBy = MoveBy::create(0.3,ccp((node->getContentSize().width)*2,0));
				//RotateBy* rotateBy =RotateBy::create(1,360,10);
			   //Action* action =Spawn::create(moveBy,rotateBy,NULL);
				node->runAction(moveBy);
		
			}

			char temp[20];
			memset(temp, 0, 20);
			sprintf(temp, "dice_%02d.png",randNumber);
			diceSprite->setSpriteFrame(diceFrameCache->getSpriteFrameByName(temp));
			diceSprite->pause();
			break;
		}
	case MSG_PAY_TOLLS_1_TAG:
		{
			buy_land_x = messageVector.at(1)->floatValue();
			buy_land_y = messageVector.at(2)->floatValue();
			int playerTag = messageVector.at(3)->intValue();
			payTolls(MSG_PAY_TOLLS_1_TAG,buy_land_x,buy_land_y,playerTag);
			break;
		}
			
	case MSG_PAY_TOLLS_2_TAG:
		{
			buy_land_x = messageVector.at(1)->floatValue();
			buy_land_y = messageVector.at(2)->floatValue();
			int playerTag = messageVector.at(3)->intValue();
			payTolls(MSG_PAY_TOLLS_2_TAG,buy_land_x,buy_land_y,playerTag);
			break;
		}
			
	case MSG_PAY_TOLLS_3_TAG:
		{
			buy_land_x = messageVector.at(1)->floatValue();
			buy_land_y = messageVector.at(2)->floatValue();
			int playerTag = messageVector.at(3)->intValue();
			payTolls(MSG_PAY_TOLLS_3_TAG,buy_land_x,buy_land_y,playerTag);			
			break;
		}

	}




}


void  GameBaseScene::setWayPassToGrid()
{
	TMXLayer* wayLayer = _map->layerNamed("way");


	Size _mapSize = wayLayer->getLayerSize(); 
	for (int j = 0;  j < _mapSize.width; j++) {  
		for (int i = 0;  i < _mapSize.height; i++) {  
			Sprite* _sp = wayLayer->tileAt(Point(j, i));  
			if (_sp) 
			{  
				float x = _sp->getPositionX();
				float y = _sp->getPositionY();
				int col = x/tiledWidth;
				int row = y/tiledHeight;
				canPassGrid[row][col] = true;
				Vec2 p = _sp->getPosition();
				wayLayerPass_vector.push_back(p);
				log("canPassGrid row=  %d ,col =%d ,canpass = %d" ,row,col,canPassGrid[row][col]);
			}  

		}  
	}  
	log("setWayPassToGrid finished");
}

void  GameBaseScene::addGoButton()
{
    Menu* menu = Menu::create();
	menu->setPosition(CCPointZero);
    setMenu(menu);
    MenuItemImage* goMenuItemButton = MenuItemImage::create("map/go_normal.png", "map/go_press.png", this, menu_selector(GameBaseScene::goButtonCallback));
 
    goMenuItemButton->setPosition(ccp(tableStartPosition_x+2*tableWidth,tableStartPosition_y-tableHeight*6));
	menu->addChild(goMenuItemButton);
	addChild(menu);
}

void GameBaseScene::goButtonCallback(cocos2d::CCObject *pSender)
{
	log("go button clicked");
	randNumber = rand()%6 + 1; 
	RouteNavigation::getInstance()->getPath(player1,randNumber,canPassGrid,tiledRowsCount,tiledColsCount);
	std::vector<int> colVector = RouteNavigation::getInstance()->getPathCols_vector();
	std::vector<int> rowVector = RouteNavigation::getInstance()->getPathRow_vector();

	for(int i=0;i<rowVector.size();i++)
	{
		log(" rowVector row is %d --- colVector col is %d",rowVector[i],colVector[i]);
	}
	NotificationCenter::getInstance()->postNotification(MSG_GO,String::createWithFormat("%d",MSG_GO_HIDE_TAG));
		
	player1->startGo(rowVector,colVector);

	log("go button clicked over");
}

void  GameBaseScene::addRightBanner()
{
	Sprite* rightBanner = Sprite::create(RIGHT_BANNER);
	rightBanner->setAnchorPoint(ccp(0,0));
	rightBanner->setPosition( ccp(tableStartPosition_x-10, 0));
	addChild(rightBanner);
}


void GameBaseScene:: addPlayer()
{

	addPlayerInfo();

	struct timeval now; 
	gettimeofday(&now, NULL);
	unsigned rand_seed = (unsigned)(now.tv_sec*1000 + now.tv_usec/1000);    //都转化为毫秒 
	srand(rand_seed);
	player1 = RicherPlayer::create(PLAYER_1_NAME,PLAYER_1_TAG,false);
	int _rand1 = rand()%(wayLayerPass_vector.size()); 
	log("rand %d" ,_rand1);
	Vec2 vec2ForPlayer1 = wayLayerPass_vector.at(_rand1);
	vec2ForPlayer1.y +=tiledHeight; 
	player1->setPosition(vec2ForPlayer1);
	player1->setAnchorPoint(ccp(0,0.5));
	int col = vec2ForPlayer1.x/tiledWidth;
	int row = vec2ForPlayer1.y/tiledHeight;
	log("player1 position row=  %d ,col = %d" ,row,col);
	log("player1 position x=  %f ,y = %f" , vec2ForPlayer1.x, vec2ForPlayer1.y);


	
	memset(money1, 0, 20);
	sprintf(money1, "$ %d",player1->getMoney());

	getPlayer1_money_label()->setString(money1);

	char strength1[20];
	memset(strength1, 0, 20);
	sprintf(strength1, "+ %d",player1->getStrength());
	getPlayer1_strength_label()->setString(strength1);

	addChild(player1);
	players_vector.pushBack(player1);



	player2 = RicherPlayer::create(PLAYER_2_NAME,PLAYER_2_TAG,true);
	int _rand2 = rand()%(wayLayerPass_vector.size()); 
	log("rand %d" ,_rand2);
	Vec2 vec2ForPlayer2 = wayLayerPass_vector.at(_rand2);
	vec2ForPlayer2.y +=tiledHeight; 
	player2->setPosition(vec2ForPlayer2);
	player2->setAnchorPoint(ccp(0,0.5));
	int col2 = vec2ForPlayer2.x/tiledWidth;
	int row2 = vec2ForPlayer2.y/tiledHeight;
	log("player1 position row=  %d ,col = %d" ,row2,col2);
	log("player1 position x=  %f ,y = %f" , vec2ForPlayer2.x, vec2ForPlayer2.y);
	
	memset(money2, 0, 20);
	sprintf(money2, "$ %d",player1->getMoney());

	getPlayer2_money_label()->setString(money2);

	char strength2[20];
	memset(strength2, 0, 20);
	sprintf(strength2, "+ %d",player1->getStrength());
	getPlayer2_strength_label()->setString(strength2);
	addChild(player2);
	players_vector.pushBack(player2);


	/* test player is go normal
	player3 = RicherPlayer::create("player3",PLAYER_2_TAG,true);
	int _rand3 = rand()%(wayLayerPass_vector.size()); 
	log("rand %d" ,_rand3);
	Vec2 vec2ForPlayer3 = wayLayerPass_vector.at(_rand3);
	vec2ForPlayer3.y +=tiledHeight; 
	player3->setPosition(vec2ForPlayer3);
	player3->setAnchorPoint(ccp(0,0.5));

	addChild(player3);
	players_vector.pushBack(player3);
	*/
	
}


void GameBaseScene:: addPlayerInfo()
{
	
	Sprite* player1_logo = Sprite::create(PLAYER_ME);
	player1_logo->setPosition(tableStartPosition_x+tableWidth/2,tableStartPosition_y-tableHeight);
	addChild(player1_logo);


	player1_money_label = LabelTTF::create();
	player1_money_label->setString("$");
	player1_money_label->setAnchorPoint(ccp(0,0.5));
	player1_money_label->setFontSize(FONT_SIZE);
	player1_money_label->setPosition(tableStartPosition_x+tableWidth,tableStartPosition_y-tableHeight/2);
	addChild(player1_money_label);

	player1_strength_label = LabelTTF::create();
	player1_strength_label->setString("+");
	player1_strength_label->setAnchorPoint(ccp(0,0.5));
	player1_strength_label->setFontSize(FONT_SIZE);
	player1_strength_label->setPosition(tableStartPosition_x+tableWidth,tableStartPosition_y-tableHeight/2*3);
	addChild(player1_strength_label);

	Sprite* player2_logo = Sprite::create(PLAYER_ENEMY1);
	player2_logo->setPosition(tableStartPosition_x+tableWidth/2,tableStartPosition_y-3*tableHeight);
	addChild(player2_logo);

	player2_money_label = LabelTTF::create();
	player2_money_label->setString("$");
	player2_money_label->setAnchorPoint(ccp(0,0.5));
	player2_money_label->setFontSize(FONT_SIZE);
	player2_money_label->setPosition(tableStartPosition_x+tableWidth,tableStartPosition_y-tableHeight/2*5);
	addChild(player2_money_label);

	player2_strength_label = LabelTTF::create();
	player2_strength_label->setString("+");
	player2_strength_label->setAnchorPoint(ccp(0,0.5));
	player2_strength_label->setFontSize(FONT_SIZE);
	player2_strength_label->setPosition(tableStartPosition_x+tableWidth,tableStartPosition_y-tableHeight/2*7);
	addChild(player2_strength_label);
}


void GameBaseScene:: drawTable(int playerNumber)
{
	//auto s = Director::getInstance()->getWinSize();

	auto draw = DrawNode::create();
	this->addChild(draw);

	for(int i=0;i<playerNumber;i++)
	{
		draw->drawSegment(Vec2(tableStartPosition_x,tableStartPosition_y-2*i*tableHeight), 
			Vec2(tableStartPosition_x+ 3*tableWidth,tableStartPosition_y-2*i*tableHeight), 1, 
			Color4F(0, 1, 0, 1));

		draw->drawSegment(Vec2(tableStartPosition_x,tableStartPosition_y - 2*(i+1)*tableHeight), 
			Vec2(tableStartPosition_x+ 3*tableWidth,tableStartPosition_y - 2*(i+1)*tableHeight), 1, 
			Color4F(0, 1, 0, 1));

		draw->drawSegment(Vec2(tableStartPosition_x+ tableWidth,tableStartPosition_y - tableHeight-2*i*tableHeight), 
			Vec2(tableStartPosition_x+ 3*tableWidth,tableStartPosition_y - tableHeight-2*i*tableHeight), 1, 
			Color4F(0, 1, 0, 1));

		draw->drawSegment(Vec2(tableStartPosition_x+ tableWidth,tableStartPosition_y -2*i*tableHeight), 
			Vec2(tableStartPosition_x+ tableWidth,tableStartPosition_y -2* tableHeight-2*i*tableHeight), 1, 
			Color4F(0, 1, 0, 1));
	}
}


void GameBaseScene::onExit()
{

	CC_SAFE_DELETE(canPassGrid);
	dice_animate->release();
	scaleby1ForBuyLand->release();
	scaleby2ForBuyLand->release();	
	landFadeOut->release();
	landFadeIn ->release();
	Layer::onExit();

}

RicherPlayer* GameBaseScene::getPlayerByTiled(float x,float y)
{
	int gid = landLayer->getTileGIDAt(ccp(x,y));
	if(gid == player1_building_1_tiledID || gid == player1_building_2_tiledID || gid == player1_building_3_tiledID)
		{
			return player1;
		}
	if(gid == player2_building_1_tiledID || gid == player2_building_2_tiledID || gid == player2_building_3_tiledID)
		{
			return player2;
		}
}

void  GameBaseScene::refreshMoneyLabel(RicherPlayer* player,int money)
{
	int tag = player->getTag();
	player->setMoney(player->getMoney()+ money);

	if(tag == PLAYER_1_TAG)
	{		
		memset(money1, 0, 20);
		sprintf(money1, "$ %d",player->getMoney());
		getPlayer1_money_label()->setString(money1);
	}
	if(tag == PLAYER_2_TAG)
	{
		memset(money2, 0, 20);
		sprintf(money2, "$ %d",player->getMoney());
		getPlayer2_money_label()->setString(money2);
	}
}

void GameBaseScene::payTolls(int payTag,float x,float y ,int playerTag)
{
			int money =0;
	        if(payTag == MSG_PAY_TOLLS_1_TAG)
			{
				money = LAND_BLANK_MONEY;
			}
		   if(payTag == MSG_PAY_TOLLS_2_TAG)
			{
				money = LAND_LEVEL_1_MONEY;
			}
			if(payTag == MSG_PAY_TOLLS_3_TAG)
			{
				money = LAND_LEVEL_2_MONEY;
			}
			
			displayVector.clear();

			RicherPlayer* landOwner = getPlayerByTiled(buy_land_x,buy_land_y);
			

			switch(playerTag)
			{
				case PLAYER_1_TAG:
				{
					int retMoney = displayArea(x,y,player1,player2_building_1_tiledID,player2_building_2_tiledID,player2_building_3_tiledID);
					refreshMoneyLabel(landOwner,money + retMoney);
					refreshMoneyLabel(player1,-(money + retMoney));
					NotificationCenter::getInstance()->postNotification(MSG_PICKONE_TOGO,String::createWithFormat("%d",MSG_PICKONE_TOGO_TAG));
					break;
				}
				case PLAYER_2_TAG:
				{
					int retMoney = displayArea(x,y,player2,player1_building_1_tiledID,player1_building_2_tiledID,player1_building_3_tiledID);
					refreshMoneyLabel(landOwner,money + retMoney);
					refreshMoneyLabel(player2,-(money + retMoney));
					NotificationCenter::getInstance()->postNotification(MSG_PICKONE_TOGO,String::createWithFormat("%d",MSG_PICKONE_TOGO_TAG));
					break;
				}				
			}
}

void GameBaseScene::buyLand(int buyTag,float x,float y ,Sprite* landSprite,int landLevel,RicherPlayer* player ,char* particlelistName)
{
			int money =0;

	        if(buyTag == MSG_BUY_BLANK_TAG)
			{
				money = LAND_BLANK_MONEY;				
			}
		   if(buyTag == MSG_BUY_LAND_1_TAG)
			{
				money = LAND_LEVEL_1_MONEY;
			}
			if(buyTag == MSG_BUY_LAND_2_TAG)
			{
				money = LAND_LEVEL_2_MONEY;
			}

			Point pointOfGL = Util::map2GL(ccp(x,y),GameBaseScene::_map);
					
			landSprite->setVisible(true);
			landSprite->setPosition(pointOfGL);
			Point pointOfMap = ccp(x,y);
			landSprite->runAction(Sequence::create(scaleby1ForBuyLand, scaleby2ForBuyLand,CallFunc::create([this,pointOfMap,pointOfGL,landSprite,landLevel,x,y,player,money,particlelistName]()
				{
					playParticle(pointOfGL,particlelistName);
					landSprite->setVisible(false);
					landLayer->setTileGID(landLevel,ccp(x,y));
					refreshMoneyLabel(player,-money);				
				}),NULL));

}

int GameBaseScene::displayArea(float x,float y,RicherPlayer* player,int building_1_tiledID,int building_2_tiledID,int building_3_tiledID)
{
	int sumMoney =0;
	float retX = Util::GL2map(player->getPosition(),_map).x;
	if(x == retX)
	{
		float leftX  = x - 1;
		float rightX = x + 1;
		int leftGID = landLayer->getTileGIDAt(ccp(leftX,y));
		int rightGID = landLayer->getTileGIDAt(ccp(rightX,y));
		displayVector.pushBack(landLayer->getTileAt(ccp(x,y)));
		while(leftGID != 0 && (leftGID == building_1_tiledID || leftGID == building_2_tiledID || leftGID == building_3_tiledID))
		{
			if(leftGID == building_1_tiledID)
			{
				sumMoney += LAND_BLANK_MONEY;
			}
			if(leftGID == building_2_tiledID)
			{
				sumMoney += LAND_LEVEL_1_MONEY;
			}
			if(leftGID == building_3_tiledID)
			{
				sumMoney += LAND_LEVEL_2_MONEY;
			}
			displayVector.pushBack(landLayer->getTileAt(ccp(leftX,y)));
			leftX -= 1;
			leftGID = landLayer->getTileGIDAt(ccp(leftX,y));

			if(leftGID == 0)
			{
				break;
			}
			log("leftGID: %d" ,leftGID);
		}
		while(rightGID != 0 && (rightGID == building_1_tiledID || rightGID == building_2_tiledID || rightGID == building_3_tiledID))
		{
			if(rightGID == building_1_tiledID)
			{
				sumMoney += LAND_BLANK_MONEY;
			}
			if(rightGID == building_2_tiledID)
			{
				sumMoney += LAND_LEVEL_1_MONEY;
			}
			if(rightGID == building_3_tiledID)
			{
				sumMoney += LAND_LEVEL_2_MONEY;
			}
			displayVector.pushBack(landLayer->getTileAt(ccp(rightX,y)));
			rightX += 1;
			rightGID = landLayer->getTileGIDAt(ccp(rightX,y));

			if(rightGID == 0)
			{
				break;
			}
			log("rightGID: %d" ,rightGID);
		}					
	}

	float retY = Util::GL2map(player->getPosition(),_map).y ;
	if(y == retY)
	{
		float upY  = y - 1;
		float downY = y + 1;
		int upGID = landLayer->getTileGIDAt(ccp(x,upY));
		int downGID = landLayer->getTileGIDAt(ccp(x,downY));
		displayVector.pushBack(landLayer->getTileAt(ccp(x,y)));
		while(upGID != 0 && (upGID == building_1_tiledID || upGID == building_2_tiledID || upGID == building_3_tiledID))
		{
			if(upGID == building_1_tiledID)
			{
				sumMoney += LAND_BLANK_MONEY;
			}
			if(upGID == building_2_tiledID)
			{
				sumMoney += LAND_LEVEL_1_MONEY;
			}
			if(upGID == building_3_tiledID)
			{
				sumMoney += LAND_LEVEL_2_MONEY;
			}
			displayVector.pushBack(landLayer->getTileAt(ccp(x,upY)));
			upY -= 1;
			upGID = landLayer->getTileGIDAt(ccp(x,upY));

			if(upGID == 0)
			{
				break;
			}
			log("leftGID: %d" ,upGID);
		}
		while(downGID != 0 && (downGID == building_1_tiledID || downGID == building_2_tiledID || downGID == building_3_tiledID))
		{
			if(downGID == building_1_tiledID)
			{
				sumMoney += LAND_BLANK_MONEY;
			}
			if(downGID == building_2_tiledID)
			{
				sumMoney += LAND_LEVEL_1_MONEY;
			}
			if(downGID == building_3_tiledID)
			{
				sumMoney += LAND_LEVEL_2_MONEY;
			}
			displayVector.pushBack(landLayer->getTileAt(ccp(x,downY)));
			downY += 1;
			downGID = landLayer->getTileGIDAt(ccp(x,downY));
			
			if(downGID == 0)
			{
				break;
			}
			log("rightGID: %d" ,downGID);
		}					
	}
	for(auto it=displayVector.begin();it!=displayVector.end();it++ )
	{					
		(Sprite*)(*it)->runAction(Sequence::create(landFadeOut->clone(),landFadeIn->clone(),NULL));
	}
	return sumMoney;
}