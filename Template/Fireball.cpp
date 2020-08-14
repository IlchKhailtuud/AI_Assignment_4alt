#include "Fireball.h"

#include "../src/TextureManager.h"

FireBall::FireBall(float x, float y, int face)
{
	TextureManager::Instance()->loadSpriteSheet(
		"../Assets/sprites/fireball.txt",
		"../Assets/sprites/fireball.png",
		"fireball");
	setSpriteSheet(TextureManager::Instance()->getSpriteSheet("fireball"));

	// set frame width
	setWidth(16);

	// set frame height
	setHeight(16);

	getTransform()->position = glm::vec2(x, y);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	//getRigidBody()->maxSpeed = 10.0f;
	getRigidBody()->isColliding = false;

	m_speed = 10;
	this->face = face;
	//setType(FIREBALL);

	m_buildAnimations();
}

FireBall::~FireBall()
{

}

void FireBall::draw()
{
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	TextureManager::Instance()->playAnimation(
		"fireball", getAnimation("fire"),
		x, y, getWidth(), getHeight(), 0.5f, 0, 255, true);
}

void FireBall::update()
{
	this->getTransform()->position.x += m_speed * face;
}


void FireBall::m_buildAnimations()
{
	Animation fireAnimation = Animation();

	fireAnimation.name = "fire";
	fireAnimation.frames.push_back(getSpriteSheet()->getFrame("fireball-fire-0"));
	fireAnimation.frames.push_back(getSpriteSheet()->getFrame("fireball-fire-1"));
	fireAnimation.frames.push_back(getSpriteSheet()->getFrame("fireball-fire-2"));
	fireAnimation.frames.push_back(getSpriteSheet()->getFrame("fireball-fire-3"));
	fireAnimation.frames.push_back(getSpriteSheet()->getFrame("fireball-fire-4"));
	fireAnimation.frames.push_back(getSpriteSheet()->getFrame("fireball-fire-5"));

	setAnimation(fireAnimation);
}


void FireBall::clean()
{

}