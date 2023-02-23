#pragma once
#include "SphereCollider.h"

class BulletBase :public SphereCollider {
protected:
	int damage;
	T_Location speed;

public:

public:
	BulletBase(T_Location location, float radius, int damage, T_Location speed)
		: SphereCollider(location,radius), damage(damage), speed(speed)
	{
	}

public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual bool isBulletDeath() = 0;
	virtual int GetDamage();
};