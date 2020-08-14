#include "Enemy.h"
#include <iostream>
#include "PathManager.h"
#include "Util.h"
#include"CollisionManager.h"

Enemy::Enemy()
{
	start_point = nullptr;
	end_point = nullptr;
	//start_point->getTransform()->position = glm::vec2(0.0f,0.0f);
	//end_point->getTransform()->position = glm::vec2(0.0f, 0.0f);

	m_isPatrol = false;
	m_curHealth = ENEMYMAXHEALTH;
}

Enemy::~Enemy()
= default;

void Enemy::DecHP(int damage)
{
	m_curHealth = m_curHealth - damage;
}

int Enemy::getDetectionRadius()
{
	return m_detectionRadius;
}


void Enemy::setPath(std::vector<PathNode*> PatrolPath)
{
	/*if(start_point == nullptr || end_point == nullptr)
	{
		std::cout << "Cannot get shortest Path" << std::endl;
		return;
	}
	
	PathManager::GetShortestPath(start_point, end_point);
	std::cout << "Get: " << PathManager::getPath().size() << std::endl;
	m_path = std::move(PathManager::getPath());
	m_currentNode = m_path[0]->GetFromNode();
	m_targetNode = m_path[0]->GetToNode();
	std::cout << "Path: " << m_path.size() << std::endl;*/

	m_pPatrolPath = PatrolPath;
}

void Enemy::MovePlanetoPatrolNode()
{
	m_targetNode = m_pPatrolPath[m_nodeIndex];
	auto targetVector = Util::normalize(m_targetNode->getTransform()->position - this->getTransform()->position);
	/*std::cout << "x: " << targetVector.x << " y:" << targetVector.y << std::endl;

	float buffer = 0.01;
	if (targetVector.x >= 1-buffer && targetVector.x<=1+buffer)
	{
		this->setAngle(90.0f);
	}
	else if (targetVector.x >= -1 - buffer && targetVector.x <= -1 + buffer)
	{
		this->setAngle(-90.0f);
	}
	else if (targetVector.y >= 1 - buffer && targetVector.y <= 1 + buffer)
	{
		this->setAngle(180.0f);
	}
	else if (targetVector.y >= -1 - buffer && targetVector.y <= -1 + buffer)
	{
		this->setAngle(0.0f);
	}*/

	this->getRigidBody()->velocity = targetVector;
	this->getTransform()->position += this->getRigidBody()->velocity * this->getRigidBody()->maxSpeed;
	if (abs(Util::distance(this->getTransform()->position, m_targetNode->getTransform()->position)) < 10.0f)
	{
		m_nodeIndex++;
		if (m_nodeIndex > m_pPatrolPath.size() - 1)
		{
			m_nodeIndex = 0;
		}
	}
}

void Enemy::addPathNode(PathNode* node)
{
	m_pPatrolPath.push_back(node);
}

void Enemy::detectPlayer(Sprite* player)
{
	m_DetectPlayer = CollisionManager::circleRectCheck(this->getTransform()->position, (float)m_detectionRadius, player->getTransform()->position, player->getWidth(), player->getHeight());
	//std::cout << m_DetectPlayer << std::endl;
}


