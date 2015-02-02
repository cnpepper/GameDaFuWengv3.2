#include "SeaScene.h"

USING_NS_CC;

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
	addGameMap();
    //////////////////////////////
    // 1. super init first
    if ( !GameBase::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//GameBase::initWayArry();
	//GameBase::addPlayer();
    return true;
}

void SeaScene::addGameMap()
{
	GameBase::_GameMap = TMXTiledMap::create("map/sea.tmx");
	this->addChild(GameBase::_GameMap);
}