#include "MenuScene.h"
#include "MapChooseScene.h"
USING_NS_CC;
Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	_visibleSize = visibleSize;//初始化窗口尺寸

	/*添加场景代码*/
	addBackGroundSprite();//添加场景
	addMenuSprites();//添加菜单
    
    return true;
}

void MenuScene::addBackGroundSprite()
{
	/*添加大富翁背景图片，居中显示*/
	Sprite *menuSpriteLogo = Sprite::create(MENU_LOGO);
<<<<<<< HEAD
	menuSpriteLogo->setPosition(Point(_visibleSize.width / 2, _visibleSize.height -100));//设置坐标在窗口中心
=======
	menuSpriteLogo->setPosition(Point(_visibleSize.width / 2, _visibleSize.height -70));//设置坐标在窗口中心
>>>>>>> origin/master
	menuSpriteLogo->setAnchorPoint(Point(0.5,1));//设置重心在0.5，1这个位置
	menuSpriteLogo->setScale(0.6f);//设置缩放
	this->addChild(menuSpriteLogo);

	/*添加左边彩虹图片*/
	Sprite *rainBowSprite = Sprite::create(RAINBOW);
	rainBowSprite->setPosition(Point(5, _visibleSize.height - 20));//设置坐标在窗口中心
	rainBowSprite->setAnchorPoint(Point(0, 1));//设置重心在0.5，1这个位置
	rainBowSprite->setScale(0.3f);//设置缩放
	this->addChild(rainBowSprite);

	/*设置彩虹的动画*/
	MoveBy *rainBowMove = MoveBy::create(1, Point(8, 0));
	MoveBy *rainBowMoveReverse = rainBowMove->reverse();//反转
	Sequence *rainBowAction = Sequence::create(rainBowMove, rainBowMoveReverse, NULL);
	rainBowSprite->runAction(RepeatForever::create(rainBowAction));
	
}
void MenuScene::addMenuSprites()
{
	/*网上叫九宫格按钮，可以拉伸，需要添加特殊的头文件*/
	Scale9Sprite *btnNormal = Scale9Sprite::create(NORMAL_MENU);
	Scale9Sprite *btnPress = Scale9Sprite::create(PRESS_MENU);

	LabelTTF *singleGameTTF = LabelTTF::create(SINGLE_GAME,FONT_MENU,Btn_FontSize);//创建菜单所需要的label对象
	ControlButton *singleGameBtn = ControlButton::create(singleGameTTF, btnNormal);
	singleGameBtn->setBackgroundSpriteForState(btnPress, Control::State::SELECTED);

<<<<<<< HEAD
	singleGameBtn->setPosition(Point(_visibleSize.width/2,_visibleSize.height-300));
=======
	singleGameBtn->setPosition(Point(_visibleSize.width/2,_visibleSize.height-260));
>>>>>>> origin/master
	singleGameBtn->setPreferredSize(Size(Btn_Width, Btn_Height));//设置大小
	singleGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	singleGameBtn->setTag(Btn_Single_Game_TAG);//设置Tag
	this->addChild(singleGameBtn);
	/**/
	Scale9Sprite *btnNormal2 = Scale9Sprite::create(NORMAL_MENU);
	Scale9Sprite *btnPress2 = Scale9Sprite::create(PRESS_MENU);

	LabelTTF *singleGameTTF2 = LabelTTF::create(MULTI_GAME, FONT_MENU, Btn_FontSize);//创建菜单所需要的label对象
	ControlButton *singleGameBtn2 = ControlButton::create(singleGameTTF2, btnNormal2);
	singleGameBtn2->setBackgroundSpriteForState(btnPress2, Control::State::SELECTED);

<<<<<<< HEAD
	singleGameBtn2->setPosition(Point(_visibleSize.width / 2, _visibleSize.height - 360));
=======
	singleGameBtn2->setPosition(Point(_visibleSize.width / 2, _visibleSize.height - 320));
>>>>>>> origin/master
	singleGameBtn2->setPreferredSize(Size(Btn_Width, Btn_Height));//设置大小
	singleGameBtn2->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	singleGameBtn2->setTag(Btn_Multi_Game_TAG);//设置Tag
	this->addChild(singleGameBtn2);
	/*settingbutton*/
	Scale9Sprite *btnNormal3 = Scale9Sprite::create(NORMAL_MENU);
	Scale9Sprite *btnPress3 = Scale9Sprite::create(PRESS_MENU);

	bool music_on = UserDefault::getInstance()->getBoolForKey(MUSIC_ON_KEY, true);//获取音效设置
	LabelTTF* settingsGameTTF;
	//如果音效开，则menu显示on，如果关，显示off
	if (music_on)
	{
		settingsGameTTF = LabelTTF::create(MUSIC_ON, FONT_MENU, Btn_FontSize);
	}
	else
	{
		settingsGameTTF = LabelTTF::create(MUSIC_OFF, FONT_MENU, Btn_FontSize);
	}

	ControlButton* settingsGameBtn = ControlButton::create(settingsGameTTF, btnNormal3);
	settingsGameBtn->setBackgroundSpriteForState(btnPress3, Control::State::SELECTED);

<<<<<<< HEAD
	settingsGameBtn->setPosition(Point(_visibleSize.width / 2, _visibleSize.height - 420));
=======
	settingsGameBtn->setPosition(Point(_visibleSize.width / 2, _visibleSize.height - 380));
>>>>>>> origin/master
	settingsGameBtn->setPreferredSize(Size(Btn_Width, Btn_Height));
	settingsGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);//添加setting回调
	settingsGameBtn->setTag(Btn_Music_TAG);
	addChild(settingsGameBtn);

	/*退出按钮*/
	Scale9Sprite *btnNormal4 = Scale9Sprite::create(NORMAL_MENU);
	Scale9Sprite *btnPress4 = Scale9Sprite::create(PRESS_MENU);

	LabelTTF *singleGameTTF4 = LabelTTF::create(QUIT_GAME, FONT_MENU, Btn_FontSize);//创建菜单所需要的label对象
	ControlButton *quitGameBtn = ControlButton::create(singleGameTTF4, btnNormal4);
	quitGameBtn->setBackgroundSpriteForState(btnPress4, Control::State::SELECTED);

<<<<<<< HEAD
	quitGameBtn->setPosition(Point(_visibleSize.width / 2, _visibleSize.height - 480));
=======
	quitGameBtn->setPosition(Point(_visibleSize.width / 2, _visibleSize.height - 440));
>>>>>>> origin/master
	quitGameBtn->setPreferredSize(Size(Btn_Width, Btn_Height));//设置大小
	quitGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
	quitGameBtn->setTag(Btn_Quit_Game_TAG);//设置Tag
	this->addChild(quitGameBtn);
}

void MenuScene::menuTouchDown(Object* pSender, extension::Control::EventType event)
{
	//log("single touched");
	ControlButton* button = (ControlButton*)pSender;
	int tag = button->getTag();
	switch (tag)
	{
		case Btn_Single_Game_TAG:
		{
			//log("single game");
			Director::getInstance()->replaceScene(MapChooseScene::createScene());
		}
		case Btn_Multi_Game_TAG:
		{
			//log("multi game");
			break;
		}
		case Btn_Music_TAG:
		{
			bool music_on = UserDefault::getInstance()->getBoolForKey(MUSIC_ON_KEY, true);
			if (music_on)
			{
				UserDefault::getInstance()->setBoolForKey(MUSIC_ON_KEY, false);//设置音效关
				button->setTitleForState(MUSIC_OFF, Control::State::NORMAL);//让menu文字显示off
			}
			else
			{
				UserDefault::getInstance()->setBoolForKey(MUSIC_ON_KEY, true);//设置音效开
				button->setTitleForState(MUSIC_ON, Control::State::NORMAL);// 让menu文字显示on
			}
			break;
		}
		case Btn_Quit_Game_TAG:
		{
			//log("quit game");
			popupLayer();//弹出退出对话框，代码较多，后续编写
			break;
		}
		default:
			break;
	}
}
void MenuScene::popupLayer()
{
	//定义一个弹出层，传入一张图片
	PopupLayer* popDialog = PopupLayer::create(DIALOG_BG);
	Scale9Sprite *btnNormal = Scale9Sprite::create(DIALOG_BG);
	popDialog->setSprite9BackGround(btnNormal);
	//CONTENTSIZE 是可选的设置，可以不设置，如果设置把它当作9图缩放
	popDialog->setContentSize(CCSizeMake(Quit_Dialog_Size_Width,Quit_Dialog_Size_Height));
	popDialog->setTitle(DIALOG_TITLE);
	popDialog->setContentText(DIALOG_CONTENT, 20, 60, 250);
	//设置回调函数，回调穿一个ccnode 以获取tag判断点击按钮
	popDialog->setCallbackFunc(this, callfuncN_selector(MenuScene::quitButtonCallback));
	//
	popDialog->addButton(BUTTON_BG1, BUTTON_BG3, OK, Btn_Quit_OK_TAG);
	popDialog->addButton(BUTTON_BG2, BUTTON_BG3, CANCEL, Btn_Quit_Cancel_TAG);

	this->addChild(popDialog);
}

void MenuScene::quitButtonCallback(Node *pNode)
{
	if (pNode->getTag() == Btn_Quit_OK_TAG)
	{
		Director::getInstance()->end();
	}
	else
	{
		pNode->getParent()->getParent()->removeFromParent();
	}

}