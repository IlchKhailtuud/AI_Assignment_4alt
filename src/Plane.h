#pragma once
#ifndef __PLANE__
#define __PLANE__

#include "Enemy.h"
#include "HealthBarBorder.h"
#include "HealthBarFiller.h"
#include "StateMachine.h"
#include"BehaviorState.h"

class Plane final : public Enemy
{
public:
	Plane(float x,float y,Player* player);
	~Plane();

	// Life Cycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	//void getDir();	
private:
	void m_buildAnimations();
	void MovePlane();
	//void SetNextNode();
	//void setPath(std::vector<PathConnection*> path);
	
	void m_checkCurrentConditions();
	void m_stateMachineUpdate();
	void setAttackNode();
	void Move2NearestAttackNode();
	void Melee();
public:

private:
	bool m_withinMeleeRange,
		m_attackMode;
	int m_meleeCounter;
	
	HealthBarBorder* m_pBorder;
	HealthBarFiller* m_pFiller;

	BehaviorState m_outerState, m_innerState;
	std::vector<PathNode*> m_NodeCanAttack;
	
};



#endif /* defined (__PLANE__) */
