#pragma once
#include "BulletBase.h"
#include "Enemy.h"

class EnemyBullet:public BulletBase
{
	int image;
	Enemy** enemy;

public:
	EnemyBullet(T_Location location);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isBulletDeath() override;
	virtual int GetDamage();
};

