#pragma once
#include "BulletBase.h"
#include "SphereCollider.h"

class CharaBase{
protected:
	T_Location CharaSpeed;
	BulletBase** bullets;
	int* CharaImage = nullptr;

public:
	virtual ~CharaBase();

public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Hit() = 0;

	T_Location GetSpeed();
	void SetSpeed(T_Location Speed);
	BulletBase** GetBullets();
};