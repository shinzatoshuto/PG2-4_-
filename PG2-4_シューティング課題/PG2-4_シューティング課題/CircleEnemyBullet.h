#pragma once
#include "BulletBase.h"
#include "DxLib.h"
#include "Enemy.h"

class CircleEnemyBullet: public BulletBase
{
private:
	Enemy** enemy;

public:
	CircleEnemyBullet(T_Location location, float speed, int degAngle);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isBulletDeath() override;
	virtual int GetDamage();
};

