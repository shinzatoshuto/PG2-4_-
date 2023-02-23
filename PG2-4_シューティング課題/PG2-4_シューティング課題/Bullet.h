#pragma once
#include "Enemy.h"
#include "BulletBase.h"
#include "Player.h"

class Bullet :public BulletBase {
	int image;
	Enemy** enemy;

public:
	static int x, y;
	static int bull[_MAX_BULLETE_];

public:
	Bullet(T_Location location);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isBulletDeath() override;
	virtual int GetDamage();
};