#include "Sprite.h"

Sprite::Sprite()
{
}

Sprite::~Sprite()
= default;

SpriteSheet* Sprite::getSpriteSheet()
{
	return m_pSpriteSheet;
}

Animation& Sprite::getAnimation(const std::string& name)
{
	return m_pAnimations[name];
}

void Sprite::setSpriteSheet(SpriteSheet* sprite_sheet)
{
	m_pSpriteSheet = sprite_sheet;
}

void Sprite::setAnimation(const Animation& animation)
{
	if(!m_animationExists(animation.name))
	{
		m_pAnimations[animation.name] = animation;
	}
}

void Sprite::setDirection(Direction dir)
{
	switch (dir)
	{
	case 1:
		m_dir = left;
	case 2:
		m_dir = right;
	case 3:
		m_dir = up;
	case 4:
		m_dir = down;
	}
}

bool Sprite::m_animationExists(const std::string& id)
{
	return m_pAnimations.find(id) != m_pAnimations.end();
}
