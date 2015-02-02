#ifndef _WALK_H
#define _WALK_H

#pragma once

class CWALK
{
public:
	CWALK();
	~CWALK();
public:
	void DoWalk(CCTMXLayer &_ctmxl,int step);//在哪里 走几步
private:
	int _x;//x坐标
	int _y;//y坐标
	int _direction;//方向

	
};

#endif // !
