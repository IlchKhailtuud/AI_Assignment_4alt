#pragma once
#include "Sprite.h"

class FireBall :public Sprite
{
public:
	FireBall(float x, float y, int face);
	~FireBall();
	
	void draw() override;
	void update() override;
	void clean() override;
	
	void setUnactive()
	{
		m_bIsActive = false;
	}
	
	int getMaxhealth() override { return 0; }

	bool bIsActive() { return m_bIsActive; }
	void setActive();
	
private:
	void m_buildAnimations();
	int m_speed;
	bool m_bIsActive;
	int m_damage;
	int face;
};
