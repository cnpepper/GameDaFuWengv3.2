#ifndef _WALK_H
#define _WALK_H

#pragma once

class CWALK
{
public:
	CWALK();
	~CWALK();
public:
	void DoWalk(CCTMXLayer &_ctmxl,int step);//������ �߼���
private:
	int _x;//x����
	int _y;//y����
	int _direction;//����

	
};

#endif // !
