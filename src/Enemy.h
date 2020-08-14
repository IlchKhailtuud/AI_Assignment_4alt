#pragma once
#include "Sprite.h"
#include"PathNode.h"

const int ENEMYMAXHEALTH = 100;

class Enemy:public Sprite
{
public:
	Enemy();
	~Enemy();
	
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	void DecHP(int damage);
	int getDetectionRadius();
	void setStartNode(PathNode* start) { start_point = start; }
	void setEndNode(PathNode* end) { end_point = end; }
	void setPath(std::vector<PathNode*> PatrolPath);
	void MovePlanetoPatrolNode();
	void setPatrolMode(bool isPatrol) { m_isPatrol = isPatrol; }
	bool getPatrolMode() { return m_isPatrol; }
	void addPathNode(PathNode* node);
	std::vector<PathNode*> getPatrolPath() { return m_pPatrolPath; }
	bool getHasLOS() { return m_hasLOS; };
	void setHasLOS(bool hasLOS) { m_hasLOS = hasLOS; }
	void detectPlayer(Sprite* player);
	virtual int getMaxhealth() { return ENEMYMAXHEALTH; }
	bool getDetect() { return m_DetectPlayer; }
protected:
	
public:
	
protected:
	float 	m_accel,
			m_vel,
			m_velMax;
	int m_nodeIndex;
	
	int	m_detectionRadius;
	bool m_isPatrol,
		m_hasLOS,
		m_DetectPlayer;
	
	PathNode* start_point, * end_point;
	PathNode* m_targetNode, * m_currentNode;
	std::vector<PathConnection*> m_path;
	std::vector<PathNode*> m_pPatrolPath;
};
