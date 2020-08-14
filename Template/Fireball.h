#pragma once
#include "../src/Sprite.h"

class FireBall :public Sprite
{
public:
	FireBall(float x, float y, int face);
	~FireBall();
	void draw() override;
	void update() override;
	void clean() override;
	bool getIsActive() { return m_active; }
	void setUnactive()
	{
		m_active = false;
	}

	void m_buildAnimations();
	int getMaxhealth() override { return 0; }

private:
	int m_speed;
	bool m_active = true;
	int m_damage;
	int face;
};
