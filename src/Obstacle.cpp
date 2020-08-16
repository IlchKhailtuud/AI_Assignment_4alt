#include "Obstacle.h"

#include "TextureManager.h"

Obstacle::Obstacle(float x,float y)
{
	TextureManager::Instance()->load("../Assets/textures/obstacle.png", "obstacle");

	const auto size = TextureManager::Instance()->getTextureSize("obstacle");
	setWidth(size.x);
	setHeight(size.y);
	getTransform()->position = glm::vec2(x,y);
	getRigidBody()->velocity = glm::vec2(0, 0);
	getRigidBody()->isColliding = false;

	setType(OBSTACLE);
}

Obstacle::~Obstacle()
= default;

void Obstacle::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the target
	TextureManager::Instance()->draw("obstacle", x, y, getWidth(),getHeight(),0, 255, true);
}

void Obstacle::update()
{
}

void Obstacle::clean()
{
}
