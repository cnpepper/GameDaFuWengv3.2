#include "MapChooseScene.h"
#include "SeaScene.h"
#include "ConstUtil.h"
USING_NS_CC;
USING_NS_CC_EXT;
Scene* MapChooseScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MapChooseScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MapChooseScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
	_visibleSize = visibleSize;
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_currentPage = 1;//Ĭ���ǵ�һ���ؿ�
	addBackgroundSprite();//��ӱ���
	addScrollview();//��ӻ���

	//��Ӵ�������
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);//�����´��ݴ���
	listener->onTouchBegan = CC_CALLBACK_2(MapChooseScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(MapChooseScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(MapChooseScene::onTouchEnded, this);
	//����¼�������
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

void MapChooseScene::addScrollview()
{
	Point center = Point(_visibleSize.width/2,_visibleSize.height/2);

	_spritesContainer = Layer::create();
	// creat map sprite , append to spriteContaner
	Sprite* beachSprite = Sprite::create(BEACH_ITEM);
	Sprite* seaSprite = Sprite::create(SEA_ITEM);
	Sprite* moonSprite = Sprite::create(MOON_ITEM);

	_spritesContainer->addChild(beachSprite);
	beachSprite->setPosition(ccpAdd(center, ccp(0, 0)));

	_spritesContainer->addChild(seaSprite);
	seaSprite->setPosition(ccpAdd(center, ccp(_visibleSize.width, 0)));

	_spritesContainer->addChild(moonSprite);
	moonSprite->setPosition(ccpAdd(center, ccp(2 * _visibleSize.width, 0)));

	//do scrollview object create and setting
	_scrollView = ScrollView::create();

	_scrollView->setContainer(_spritesContainer);
	_scrollView->setDirection(ScrollView::Direction::HORIZONTAL);//ˮƽ��ʾ
	_scrollView->setTouchEnabled(false);// enabled touch  ע�� ����һ��Ҫ���ó�false ���� _scrollView �ᴦ�����¼�����_scrollView��λ�����óɳ�ʼ״̬��
	_scrollView->setPosition(CCPointZero);

	_scrollView->setViewSize(CCSizeMake(_visibleSize.width, _visibleSize.height));
	_scrollView->setContentOffset(CCPointZero, true);
	_scrollView->setContentSize(CCSizeMake(_visibleSize.width, _visibleSize.height));

	_scrollView->setDelegate(this);
	_scrollView->setBounceable(false);

	this->addChild(_scrollView);
}

bool MapChooseScene::onTouchBegan(Touch *touch, Event *unused_event)
{
	_beginTouchPoint = Director::getInstance()->convertToGL(touch->getLocationInView());
	CCLOG("TOUCH BEGAIN");
	_bDoChoose = true;
	return true;
}

void MapChooseScene::onTouchEnded(Touch *touch, Event *unused_event)
{
	Point endPoint = Director::getInstance()->convertToGL(touch->getLocationInView());
	float distance = endPoint.x - _beginTouchPoint.x;
<<<<<<< HEAD
	if (fabs(distance)>TOUCH_DISTANCE)
	{
		adjustScrollView(distance);
	}
	else if (_bDoChoose)
	{
		auto scene = SeaScene::createScene();
		Director::getInstance()->replaceScene(scene);
	}
=======
	do
	{
		if (fabs(distance)>TOUCH_DISTANCE)
		{
			adjustScrollView(distance);
			break;
		}
	
		if (_bDoChoose)
		{
			auto scene = SeaScene::createScene();
			Director::getInstance()->replaceScene(scene);
		}
	} while (0);
>>>>>>> origin/master
}

void MapChooseScene::adjustScrollView(float distance)
{
	if (distance<0)
	{
		_currentPage++;
	}
	else
	{
		_currentPage--;
	}

	if (_currentPage<1)
	{
		_currentPage = 1;
	}

	if (_currentPage > MAP_COUNT)
	{
		_currentPage = MAP_COUNT;
	}
	
	CCPoint adjustPos = Point(- _visibleSize.width * (_currentPage-1),0);
	_scrollView->setContentOffset(adjustPos,true);
}

void MapChooseScene::addBackgroundSprite()
{
	Sprite* backgound = Sprite::create(STAGE_BACKGROUND);
	backgound->setPosition(CCPointZero);
	backgound->setAnchorPoint(CCPointZero);

	this->addChild(backgound);
}

//����һЩ����
void MapChooseScene::singleTouchDown(CC2D::Object* pSender, CC2D::EXT::Control::EventType event)
{

}




//�̳���Ӧ�����ķ���
void MapChooseScene::onTouchMoved(CC2D::Touch *touch, CC2D::Event *unused_event)
{
	CCLOG("MOVED");
<<<<<<< HEAD
	_bDoChoose = false;
=======
	//_bDoChoose = false;
>>>>>>> origin/master
}

//�̳� ScrollvewDelegate ����Ҫʵ�ֵ�3������
void MapChooseScene::scrollViewDidScroll(CC2D::EXT::ScrollView* view)
{
	CCLOG("scrollViewDidScroll");
}
void MapChooseScene::scrollViewDidZoom(CC2D::EXT::ScrollView* view)
{
	CCLOG("scrollViewDidZoom");
}
// void MapChooseScene::scrollViewMoveOver(CC2D::EXT::ScrollView* view)
//{
//	CCLOG("scrollViewMoveOver");
//}