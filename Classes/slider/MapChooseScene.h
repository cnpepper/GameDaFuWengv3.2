<<<<<<< HEAD
=======
ï»¿/******************************************************Â 
*Â ProgramÂ AssignmentÂ :Â Â æ»‘åŠ¨é€‰æ‹©åœ°å›¾Â 
*Â Author : åˆ˜å»ºå‡Â 
*Â Date : 2015 / 1 / 20Â Â 21 : 59
* Description : å®žçŽ°äº†è§¦å±æ»‘åŠ¨é€‰æ‹©çš„æ•ˆæžœ
***************************************************** /Â 
/*******************************************************Â 
*Â SourceÂ codeÂ inÂ :æºæ–‡ä»¶è·¯å¾„
*Â FunctionÂ List:Â å‡½æ•°è¡¨
* void singleTouchDown(CC2D::Object* pSender, CC2D::EXT::Control::EventType event);
* void addBackgroundSprite();//æ·»åŠ èƒŒæ™¯
* void addScrollview();//æ·»åŠ æ»‘åŠ¨å¯¹è±¡åŠå…¶åŒ…å«çš„sprite
* void adjustScrollView(float distance);//è‡ªå®šä¹‰æ–¹æ³•ï¼Œç”¨æ¥è¿›è¡Œæ‹–åŠ¨åŽçš„ä½ç½®è°ƒæ•´
*******************************************************/
>>>>>>> origin/master
#ifndef __MAPCHOOSE_SCENE_H__
#define __MAPCHOOSE_SCENE_H__

#include "cocos2d.h"
#include "GUI/CCScrollView/CCScrollView.h"
#include "GUI/CCControlExtension/CCControl.h"
#define CC2D cocos2d
#define EXT extension
<<<<<<< HEAD
//¶¨ÒåÒ»Ð©³£Á¿
const int MAP_COUNT = 3;//¶¨ÒåÁËÈýÕÅ¹Ø¿¨Í¼Æ¬
const int TOUCH_DISTANCE = 50;//ÊÖÊÆ»¬¶¯¾àÀë
class MapChooseScene : public CC2D::Layer,CC2D::EXT::ScrollViewDelegate//Ê¹ÓÃ»¬¶¯ÐèÒª¼Ì³ÐÕâ¸öÀà
=======
//å®šä¹‰ä¸€äº›å¸¸é‡
const int MAP_COUNT = 3;//å®šä¹‰äº†ä¸‰å¼ å…³å¡å›¾ç‰‡
const int TOUCH_DISTANCE = 200;//æ‰‹åŠ¿æ»‘åŠ¨è·ç¦»
class MapChooseScene : public CC2D::Layer,CC2D::EXT::ScrollViewDelegate//ä½¿ç”¨æ»‘åŠ¨éœ€è¦ç»§æ‰¿è¿™ä¸ªç±»
>>>>>>> origin/master
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static CC2D::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
       
    // implement the "static create()" method manually
	CREATE_FUNC(MapChooseScene);
private:
<<<<<<< HEAD
	//¶¨ÒåÒ»Ð©·½·¨
	void singleTouchDown(CC2D::Object* pSender, CC2D::EXT::Control::EventType event);
	void addBackgroundSprite();//Ìí¼Ó±³¾°
	void addScrollview();//Ìí¼Ó»¬¶¯¶ÔÏó¼°Æä°üº¬µÄsprite
	void adjustScrollView(float distance);//×Ô¶¨Òå·½·¨£¬ÓÃÀ´½øÐÐÍÏ¶¯ºóµÄÎ»ÖÃµ÷Õû

	//¼Ì³ÐÏìÓ¦´¥ÆÁµÄ·½·¨
=======
	//å®šä¹‰ä¸€äº›æ–¹æ³•
	void singleTouchDown(CC2D::Object* pSender, CC2D::EXT::Control::EventType event);
	void addBackgroundSprite();//æ·»åŠ èƒŒæ™¯
	void addScrollview();//æ·»åŠ æ»‘åŠ¨å¯¹è±¡åŠå…¶åŒ…å«çš„sprite
	void adjustScrollView(float distance);//è‡ªå®šä¹‰æ–¹æ³•ï¼Œç”¨æ¥è¿›è¡Œæ‹–åŠ¨åŽçš„ä½ç½®è°ƒæ•´

	//ç»§æ‰¿å“åº”è§¦å±çš„æ–¹æ³•
>>>>>>> origin/master
	void onTouchEnded(CC2D::Touch *touch, CC2D::Event *unused_event);
	bool onTouchBegan(CC2D::Touch *touch, CC2D::Event *unused_event);
	void onTouchMoved(CC2D::Touch *touch, CC2D::Event *unused_event);

<<<<<<< HEAD
	//¼Ì³Ð ScrollvewDelegate ÀàÐèÒªÊµÏÖµÄ3¸ö·½·¨
	void scrollViewDidScroll(CC2D::EXT::ScrollView* view) override;
	void scrollViewDidZoom(CC2D::EXT::ScrollView* view) override;
	//void scrollViewMoveOver(CC2D::EXT::ScrollView* view) override;
	//¶¨ÒåÒ»Ð©³ÉÔ±
	CC2D::Size _visibleSize;
	CC2D::Layer* _spritesContainer; //ÓÃÓÚ´æ·Å3ÕÅ¹Ø¿¨Í¼Æ¬µÄspriteÈÝÆ÷
	int _currentPage;//µ±Ç°Í¼Æ¬ÊÇµÚ¼¸ÕÅ¹Ø¿¨
	CC2D::Point _beginTouchPoint;//´¥ÃþÊ±°´ÏÂµÄÎ»ÖÃ
	CC2D::EXT::ScrollView* _scrollView;//»¬¶¯¶ÔÏóÊµÀý
=======
	//ç»§æ‰¿ ScrollvewDelegate ç±»éœ€è¦å®žçŽ°çš„3ä¸ªæ–¹æ³•
	void scrollViewDidScroll(CC2D::EXT::ScrollView* view) override;
	void scrollViewDidZoom(CC2D::EXT::ScrollView* view) override;
	//void scrollViewMoveOver(CC2D::EXT::ScrollView* view) override;
	//å®šä¹‰ä¸€äº›æˆå‘˜
	CC2D::Size _visibleSize;
	CC2D::Layer* _spritesContainer; //ç”¨äºŽå­˜æ”¾3å¼ å…³å¡å›¾ç‰‡çš„spriteå®¹å™¨
	int _currentPage;//å½“å‰å›¾ç‰‡æ˜¯ç¬¬å‡ å¼ å…³å¡
	CC2D::Point _beginTouchPoint;//è§¦æ‘¸æ—¶æŒ‰ä¸‹çš„ä½ç½®
	CC2D::EXT::ScrollView* _scrollView;//æ»‘åŠ¨å¯¹è±¡å®žä¾‹
>>>>>>> origin/master
private:
	bool _bDoChoose;
};

#endif // __HELLOWORLD_SCENE_H__
