#include "PopupLayer.h"

PopupLayer::PopupLayer():
m__pMenu(NULL)
, m_contentPadding(0)
, m_contentPaddingTop(0)
, m_callbackListener(NULL)
, m_callback(NULL)
, m__sfBackGround(NULL)
, m__s9BackGround(NULL)
, m__ltContentText(NULL)
, m__ltTitle(NULL)
{
    
}

PopupLayer::~PopupLayer()
{
    CC_SAFE_RELEASE(m__pMenu);
    CC_SAFE_RELEASE(m__sfBackGround);
    CC_SAFE_RELEASE(m__ltContentText);
    CC_SAFE_RELEASE(m__ltTitle);
    CC_SAFE_RELEASE(m__s9BackGround);
}

bool PopupLayer::init()
{
	if(!Layer::init())
	{
		return false;
	}
		this->setContentSize(CCSizeZero);
        
        // 初始化需要的 Menu
        Menu* menu = Menu::create();
        menu->setPosition(CCPointZero);
        setMenuButton(menu);
		setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	    auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);

	    listener->onTouchBegan = [](Touch *t,Event *e){
			CCLog("PopupLayer touch");
           return true;
    };
		// _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}


PopupLayer* PopupLayer::create(const char *backgroundImage)
{
    PopupLayer* ml = PopupLayer::create();
    ml->setSpriteBackGround(Sprite::create(backgroundImage));
    ml->setSprite9BackGround(Scale9Sprite::create(backgroundImage));
    return ml;
}

void PopupLayer::setTitle(const char *title, int fontsize)
{
    LabelTTF* ltfTitle = LabelTTF::create(title, "", fontsize);
    setLabelTitle(ltfTitle);
}

void PopupLayer::setContentText(const char *text, int fontsize, int padding, int paddingTop)
{
    LabelTTF* ltf = LabelTTF::create(text, "", fontsize);
    setLabelContentText(ltf);
    m_contentPadding = padding;
    m_contentPaddingTop = paddingTop;
}

void PopupLayer::setCallbackFunc(cocos2d::Object *target, SEL_CallFuncN callfun)
{
    m_callbackListener = target;
    m_callback = callfun;    
}


bool PopupLayer::addButton(const char *normalImage, const char *selectedImage, const char *title, int tag)
{
	Size winSize = CCDirector::getInstance()->getWinSize();
    Point pCenter = ccp(winSize.width / 2, winSize.height / 2);
    
    // 创建图片菜单按钮
    MenuItemImage* menuImage = MenuItemImage::create(normalImage, selectedImage, this, menu_selector(PopupLayer::buttonCallback));
    menuImage->setTag(tag);
    menuImage->setPosition(pCenter);
    
    // 添加文字说明并设置位置

	Size imenu = menuImage->getContentSize();
    LabelTTF* ttf = LabelTTF::create(title, "", 20);
    ttf->setColor(ccc3(0, 0, 0));
    ttf->setPosition(ccp(imenu.width / 2, imenu.height / 2));
    menuImage->addChild(ttf);

	
    getMenuButton()->addChild(menuImage);
    return true;
}

void PopupLayer::buttonCallback(cocos2d::CCObject *pSender)
{
    Node* node = dynamic_cast<Node*>(pSender);
    CCLog("touch tag: %d", node->getTag());
    if (m_callback && m_callbackListener){
        (m_callbackListener->*m_callback)(node);
    }
   // this->removeFromParent();
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
    } else {
        Scale9Sprite *background = getSprite9BackGround();
        background->setContentSize(getContentSize());
        background->setPosition(ccp(winSize.width / 2, winSize.height / 2));
        this->addChild(background, 0, 0);
        contentSize = getContentSize();
    }
    
    
    // 添加按钮，并设置其位置
    this->addChild(getMenuButton());
    float btnWidth = contentSize.width / (getMenuButton()->getChildrenCount() + 1);
    
	Vector<Node*> vecArray = getMenuButton()->getChildren();

	int j=0;
	for(auto it=vecArray.begin();it!=vecArray.end();it++)
	{
		Node* node = dynamic_cast<Node*>(*it);
		node->setPosition(Point(winSize.width/2 - contentSize.width/2+btnWidth*(j+1),winSize.height/2-contentSize.height/3));
		j++;
	}

    // 显示对话框标题
    if (getLabelTitle())
	{
        getLabelTitle()->setPosition(ccpAdd(pCenter, ccp(0, contentSize.height / 2 -20)));
		getLabelTitle()->setColor(ccc3(0,0,0));
        this->addChild(getLabelTitle());
    }
    
    // 显示文本内容
    if (getLabelContentText())
	{
        LabelTTF* ltf = getLabelContentText();
        ltf->setPosition(ccp(winSize.width / 2, winSize.height / 2));
        ltf->setDimensions(CCSizeMake(contentSize.width - m_contentPadding * 2, contentSize.height - m_contentPaddingTop));
        ltf->setHorizontalAlignment(kCCTextAlignmentLeft);
		ltf->setColor(ccc3(0,0,0));
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
