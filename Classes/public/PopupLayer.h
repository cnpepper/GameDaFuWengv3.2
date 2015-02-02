<<<<<<< HEAD
=======
ï»¿/******************************************************Â 
*Â ProgramÂ AssignmentÂ :Â å¼¹å‡ºçš„æ–‡å­—ç±»
*Â Author : åˆ˜å»ºå‡Â 
*Â Date : 2015 / 1 / 26Â Â 21 : 59
* Description :
***************************************************** /Â 
/*******************************************************Â 
*Â SourceÂ codeÂ inÂ :æºæ–‡ä»¶è·¯å¾„
*Â FunctionÂ List:Â å‡½æ•°è¡¨
*******************************************************/
>>>>>>> origin/master
#ifndef __POPUPLAYER_H__
#define __POPUPLAYER_H__

#include "cocos2d.h"
USING_NS_CC;
#include "GUI/CCControlExtension/CCControl.h"
#include "ConstUtil.h"
<<<<<<< HEAD
#include "cocos2d/extensions/cocos-ext.h"
USING_NS_CC_EXT;
const int Pop_FontSize = 20;//¶¨Òå×ÖÌå´óÐ¡
=======
#include "cocos-ext.h"
USING_NS_CC_EXT;
const int Pop_FontSize = 20;//å®šä¹‰å­—ä½“å¤§å°
>>>>>>> origin/master
class PopupLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
	CREATE_FUNC(PopupLayer);
	
	PopupLayer();
	~PopupLayer();
	static PopupLayer* create(const char* backgroundImage);
<<<<<<< HEAD
	void setTitle(const char* title, int fontsize=Pop_FontSize);//ÉèÖÃ¶Ô»°¿ò±êÌâ
	void setContentText(const char* text, int fontsize = Pop_FontSize,int padding = 50, int paddintTop = 100);//ÉèÖÃÎÄ±¾¿òÄÚÈÝ
	void setCallbackFunc(Object* target, SEL_CallFuncN callfun);//ÉèÖÃ°´¼üµÄ»Øµ÷·½·¨
	bool addButton(const char* normalImage, const char* selectedImage, const char*title,int tag=0);//Ìí¼Ó¶Ô»°¿ò°´Å¥

	virtual void onEnter();//½øÈëÊ±µ÷ÓÃ
	virtual void onExit();//ÍË³öÊ±µ÷ÓÃ

	void buttonCallback(CCObject* pSender);

	int _contentPadding;//ÎÄ±¾ÄÚÈÝÁ½±ßµÄ¿Õ°×¾àÀë
	int _contentPaddingTop;//ÎÄ±¾ÄÚÈÝÉÏ±ß¿Õ°×¾àÀë
=======
	void setTitle(const char* title, int fontsize=Pop_FontSize);//è®¾ç½®å¯¹è¯æ¡†æ ‡é¢˜
	void setContentText(const char* text, int fontsize = Pop_FontSize,int padding = 50, int paddintTop = 100);//è®¾ç½®æ–‡æœ¬æ¡†å†…å®¹
	void setCallbackFunc(Object* target, SEL_CallFuncN callfun);//è®¾ç½®æŒ‰é”®çš„å›žè°ƒæ–¹æ³•
	bool addButton(const char* normalImage, const char* selectedImage, const char*title,int tag=0);//æ·»åŠ å¯¹è¯æ¡†æŒ‰é’®

	virtual void onEnter();//è¿›å…¥æ—¶è°ƒç”¨
	virtual void onExit();//é€€å‡ºæ—¶è°ƒç”¨

	void buttonCallback(CCObject* pSender);

	int _contentPadding;//æ–‡æœ¬å†…å®¹ä¸¤è¾¹çš„ç©ºç™½è·ç¦»
	int _contentPaddingTop;//æ–‡æœ¬å†…å®¹ä¸Šè¾¹ç©ºç™½è·ç¦»
>>>>>>> origin/master

	CCObject* _callbackListener;

	SEL_CallFuncN _callbakc;
	//
	CC_SYNTHESIZE_RETAIN(Menu*, _pMenu,MenuButton);
	CC_SYNTHESIZE_RETAIN(Sprite*,_sfbackground,SpriteBackGround);

	CC_SYNTHESIZE_RETAIN(Scale9Sprite*, _s9BackGround, Sprite9BackGround);
	CC_SYNTHESIZE_RETAIN(LabelTTF*, _ltTitle, LabelTitle);
	CC_SYNTHESIZE_RETAIN(LabelTTF*, _ltContentText, LabelContentText);
public:

};

#endif // __HELLOWORLD_SCENE_H__
