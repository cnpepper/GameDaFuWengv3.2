#ifndef __UTIL_H__
#define __UTIL_H__

#define winSize Director::getInstance()->getWinSize()
#include "cocos2d.h"
USING_NS_CC;

struct Util
{
	static Point map2GL(const Point& ptMap, TMXTiledMap* map)
	{
		Point ptUI;
		ptUI.x = ptMap.x * map->getTileSize().width;
		ptUI.y = (ptMap.y + 1)* map->getTileSize().height;

		Point ptGL = ptUI;
		ptGL.y = map->getContentSize().height - ptUI.y;
		return ptGL;
	}
	static Point GL2map(const Point& ptGL, TMXTiledMap* map)
	{
		Point ptUI = ptGL;
		ptUI.y = map->getContentSize().height - ptGL.y;

		int x = ptUI.x / map->getTileSize().width;
		int y = ptUI.y / map->getTileSize().height;
		return ccp(x, y);
	}
	
	static Vector<String*> splitString(const char* srcStr, const char* sSep)
	{
		Vector<String*> stringList ;  
  
		int size = strlen(srcStr);  
		String* str = String::create(srcStr);  
  
		int startIndex = 0;  
		int endIndex = 0;  
		endIndex = str->_string.find(sSep);  
  
		String* spliStr = NULL;  
  
		while(endIndex > 0) {  
			spliStr = CCString::create("");  
 			/* ��ȡ�ַ��� */  
			spliStr->_string = str->_string.substr(startIndex, endIndex);  
  			/* ����ַ������б� */  
			stringList.pushBack(spliStr);  
  			/* ��ȡʣ�µ��ַ��� */  
			str->_string = str->_string.substr(endIndex + 1, size);  
			/* ������һ���ָ��������±� */  
			endIndex = str->_string.find(sSep);  
		}  
		/* ʣ�µ��ַ���Ҳ��ӽ��б� */  
		if(str->_string.compare("") != 0) {  
			stringList.pushBack(String::create(str->_string));  
		}  
  
		return stringList; 
		

	}

};



#endif