#pragma once
#include "BulletBase.h"

class Bullet :public BulletBase {
	int image;
public:
	Bullet(T_Location location);

public:
	virtual void Update() override;
	virtual void Draw() override;
};