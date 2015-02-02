#include "PopupLayer.h"
PopupLayer::PopupLayer() :
_pMenu(NULL), 
_contentPadding(0),
_contentPaddingTop(0),
_callbackListener(NULL),
_callbakc(NULL),
_sfbackground(NULL),
_s9BackGround(NULL),
_ltContentText(NULL),
_ltTitle(NULL)
{}

PopupLayer::~PopupLayer()
{
	CC_SAFE_RELEASE(_pMenu);
	CC_SAFE_RELEASE(_sfbackground);
	CC_SAFE_RELEASE(_ltTitle);
	CC_SAFE_RELEASE(_ltContentText);
	CC_SAFE_RELEASE(_s9BackGround);


}
Scene* PopupLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = PopupLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PopupLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//初始化需要的menu 随后跟进参数向menu中添加item选项
	Menu* menu = Menu::create();
	menu->setPosition(CCPointZero);
	setMenuButton(menu);
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = [](Touch* t, Event* e)
 	{
 		CCLOG("touch");
 		return true;
	};
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    return true;
}

PopupLayer* PopupLayer::create(const char *backgroundImage)
{
	PopupLayer* ml = PopupLayer::create();
	ml->setSpriteBackGround(Sprite::create(backgroundImage));
	//ml->setSprite9BackGround(Scale9Sprite::create(backgroundImage));
	return ml;
}

void PopupLayer::setCallbackFunc(Object* target, SEL_CallFuncN callfun)
{
	//menuItem根据调用传入的对象，会进行方法的回调
	_callbackListener = target;
	_callbakc = callfun;


}
bool PopupLayer::addButton(const char* normalImage, const char* selectedImage, const char*title, int tag/* =0 */)
{
	Size winsize = CCDirector::getInstance()->getWinSize();
	Point pCenter = Point(winsize.width / 2, winsize.height / 2);
	//创建menuItem按钮 并设置回调方法
	MenuItemImage *menuImage = MenuItemImage::create(normalImage, selectedImage, this,
		menu_selector(PopupLayer::buttonCallback));
	menuImage->setTag(tag);
	menuImage->setPosition(pCenter);

	//给menuitem添加文字说明，并设置位置
	Size imenu = menuImage->getContentSize();
	LabelTTF* ttf = LabelTTF::create(title, "", 20);
	ttf->setColor(ccc3(72,10,23));
	ttf->setPosition(Point(imenu.width/2,imenu.height/2));
	menuImage->addChild(ttf);
	getMenuButton()->addChild(menuImage);
	return true;
}

void PopupLayer::buttonCallback(CCObject* pSender)
{
	Node* node = dynamic_cast<Node*>(pSender);//进行类型转换C++方式
	CCLOG("TOUCH TAG %d",node->getTag());

	if (_callbakc && _callbackListener)
	{
		//这会调用setCallbackFunc（）方法传入的MenuScene对象的quitButtonCallback
		(_callbackListener->*_callbakc)(node);//这是一个函数指针 稍后研究这个函数指针怎么来的。。
	}
	this->removeFromParent();//把对话框从父结点移除
	
}

void PopupLayer::onEnter()
{
	Layer::onEnter();

	Size winSize = Director::getInstance()->getWinSize();
	Point pCenter = ccp(winSize.width / 2, winSize.height / 2);

	Size contentSize;
	// 设定好参数，在运行时加载
	if (getContentSize().equals(CCSizeZero))
	{
		getSpriteBackGround()->setPosition(ccp(winSize.width / 2, winSize.height / 2));
		this->addChild(getSpriteBackGround(), 0, 0);
		contentSize = getSpriteBackGround()->getTexture()->getContentSize();
	}
	else {
		
		Scale9Sprite *background = getSprite9BackGround();
		background->setContentSize(this->getContentSize());
		background->setPosition(Point(winSize.width / 2, winSize.height / 2));
		this->addChild(background, 0, 0);
		contentSize = getContentSize();
		
	}


	// 添加按钮，并设置其位置
	
	this->addChild(getMenuButton());
	float btnWidth = contentSize.width / (getMenuButton()->getChildrenCount() + 1);

	Vector<Node*> vecArray = getMenuButton()->getChildren();

	int j = 0;
	for (auto it = vecArray.begin(); it != vecArray.end(); it++)
	{
		Node* node = dynamic_cast<Node*>(*it);
		node->setPosition(Point(winSize.width / 2 - contentSize.width / 2 + btnWidth*(j + 1), winSize.height / 2 - contentSize.height / 3));
		j++;
	}
	
	// 显示对话框标题
	if (getLabelTitle())
	{
		getLabelTitle()->setPosition(ccpAdd(pCenter, ccp(0, contentSize.height / 2 - 20)));
		getLabelTitle()->setColor(ccc3(0, 0, 0));
		this->addChild(getLabelTitle());
	}

	// 显示文本内容
	if (getLabelContentText())
	{
		LabelTTF* ltf = getLabelContentText();
		ltf->setPosition(ccp(winSize.width / 2, winSize.height / 2));
		ltf->setDimensions(CCSizeMake(contentSize.width - _contentPadding * 2, contentSize.height - _contentPaddingTop));
		ltf->setHorizontalAlignment(kCCTextAlignmentLeft);
		ltf->setColor(ccc3(0, 0, 0));
		this->addChild(ltf);
	}
	
	// 弹出效果
	Action* popupLayer = Sequence::create(ScaleTo::create(0.0, 0.0),
		ScaleTo::create(0.15, 1.05),
		ScaleTo::create(0.08, 0.95),
		ScaleTo::create(0.08, 1.0),
		NULL);
	this->runAction(popupLayer);
}

void PopupLayer::onExit()
{
	CCLog("popup on exit.");
	//this->removeFromParent();
	Layer::onExit();
}
void PopupLayer::setTitle(const char* title, int fontsize/* =Pop_FontSize */)
{
	LabelTTF* ltfTitle = LabelTTF::create(title, "", fontsize);
	setLabelTitle(ltfTitle);
}
void PopupLayer::setContentText(const char* text, int fontsize /* = Pop_FontSize */, int padding /* = 50 */, int paddintTop /* = 100 */)
{
	LabelTTF* ltf = LabelTTF::create(text, "", fontsize);
	setLabelContentText(ltf);
	_contentPadding = padding;
	_contentPaddingTop = paddintTop;

}