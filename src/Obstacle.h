#pragma once
#ifndef __OBSTACLE__
#define __OBSTACLE__
#include "Sprite.h"

class Obstacle : public Sprite
{
public:
	Obstacle(float x,float y,int w,int h);
	~Obstacle();

	// DisplayObject Life Cycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	virtual int getMaxhealth() { return ObstacleMaxHP; }
private:
	const int ObstacleMaxHP = 100;
	int m_curHP;
};



#endif /* defined (__OBSTACLE__) */