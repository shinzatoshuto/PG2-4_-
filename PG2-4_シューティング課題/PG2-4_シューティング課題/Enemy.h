#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

class Enemy:public CharaBase,public SphereCollider
{
private:
	int hp;
	int point;
	int BulletsCount;
	int interval;
	float Move;
	short angle;

	float PlayerX, PlayerY;

public:
	static int turn;

public:
	Enemy(T_Location location, float rudius);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit()override;
	void HitPlayer(int bulletcount);
	void Hit(int damage);
	bool HpCheck();
	int GetPoint();
	int GetPlayerLocation(float y,float x);
};