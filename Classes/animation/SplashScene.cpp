#include "SplashScene.h"

Scene* Splash::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = Splash::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Splash::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	_visibleSize = visibleSize;//��ʼ�����ڳߴ�
	initMoveSprite();//��ʼ���������鷽��
	scheduleOnce(schedule_selector(Splash::startMoveSprite),1);

    
    return true;
}
void Splash::startMoveSprite(float df)
{
	//��������������ʼ����ĩһ������ cheng ���ȿ�ʼ���������ƶ�һ��λ��
	MoveBy* moveChengToLeft1 = MoveBy::create(MOVE_SPLEED, Point(-_spriteSize.width, 0));
	_chengSprite->runAction(moveChengToLeft1);

	//����ji���������ƶ�һ��λ�ã���2�������൱��cheng��ji������λ��
	MoveBy* moveJiToright = MoveBy::create(MOVE_SPLEED, Point(_spriteSize.width, 0));
	CallFunc* callFunc = CallFunc::create(CC_CALLBACK_0(Splash::movekeSpriteToLeft, this));
	//ji������������ûص����� ��ʼ����ke�Ķ���
	_jiSprite->runAction(Sequence::create(moveJiToright, callFunc, NULL));
}

void Splash::movekeSpriteToLeft()
{
	//���� cheng�����������ƶ�һ��λ��
	MoveBy* moveChengToLeft2 = MoveBy::create(MOVE_SPLEED, Point(-_spriteSize.width,0));
	_chengSprite->runAction(moveChengToLeft2);

	//����ke���������ƶ�һ��λ�ã��ٴ�ͬcheng������λ��
	MoveBy* moveKeToright = MoveBy::create(MOVE_SPLEED, Point(_spriteSize.width, 0));
	CallFunc* callFunc2 = CallFunc::create(CC_CALLBACK_0(Splash::moveMaiSpriteToLeft, this));
	//ji������������ûص����� ��ʼ����ke�Ķ���
	_keSprite->runAction(Sequence::create(moveKeToright, callFunc2, NULL));

}

void Splash::moveMaiSpriteToLeft()
{
	//���� cheng���������ٴ��ƶ�һ��λ��
	MoveBy* moveChengToLeft3 = MoveBy::create(MOVE_SPLEED, Point(-_spriteSize.width, 0));
	_chengSprite->runAction(moveChengToLeft3);

	//����mai���������ƶ�һ��λ�ã�ͬcheng�ٴν�����λ��
	MoveBy* mai_Sprite_MoveBy = MoveBy::create(MOVE_SPLEED, Point(_spriteSize.width, 0));
	CallFunc* callFunc3 = CallFunc::create(CC_CALLBACK_0(Splash::spriteFadeOut, this));

	//����mai�������������spriteFadeOut()��������ʼ������ʧ�Ķ���
	_maiSprite->runAction(Sequence::create(mai_Sprite_MoveBy, callFunc3, NULL));
}

void Splash::spriteFadeOut()
{
	//����4����ʧ��FadeOut����������ʱ��2��
	FadeOut* fadeOut1 = FadeOut::create(1 * 2);
	FadeOut* fadeOut2 = FadeOut::create(1 * 2);
	FadeOut* fadeOut3 = FadeOut::create(1 * 2);
	FadeOut* fadeOut4 = FadeOut::create(1 * 2);
	_maiSprite->runAction(fadeOut1);
	_keSprite->runAction(fadeOut2);
	_jiSprite->runAction(fadeOut3);
	CallFunc* callFunc4 = CallFunc::create(CC_CALLBACK_0(Splash::gotoMenuScene, this));

	//�������������gotoMenuScene()��������MenuScene��������
	_chengSprite->runAction(Sequence::create(fadeOut4, callFunc4, NULL));
}

void Splash::gotoMenuScene()
{
	Director::getInstance()->replaceScene(MenuScene::createScene());
}
void Splash::initMoveSprite()
{
	_maiSprite = Sprite::create(MAI_IMAGE);
	_keSprite = Sprite::create(KE_IMAGE);
	_jiSprite = Sprite::create(JI_IMAGE);
	_chengSprite = Sprite::create(CHENG_IMAGE);

	_spriteSize = _maiSprite->getContentSize();

	_maiSprite->setPosition(Point(_visibleSize.width / 2 - (2 * _spriteSize.width), _visibleSize.height / 2));
	_keSprite->setPosition(Point(_visibleSize.width / 2 - _spriteSize.width, _visibleSize.height / 2));
	_jiSprite->setPosition(Point(_visibleSize.width / 2, _visibleSize.height / 2));
	_chengSprite->setPosition(Point(_visibleSize.width / 2 + _spriteSize.width, _visibleSize.height / 2));

	_maiSprite->setAnchorPoint(Point(0, 0.5));
	_keSprite->setAnchorPoint(Point(0, 0.5));
	_jiSprite->setAnchorPoint(Point(0, 0.5));
	_chengSprite->setAnchorPoint(Point(0, 0.5));

	this->addChild(_maiSprite);
	this->addChild(_keSprite);
	this->addChild(_jiSprite);
	this->addChild(_chengSprite);
}