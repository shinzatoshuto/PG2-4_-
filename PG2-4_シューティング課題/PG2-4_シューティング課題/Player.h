#pragma once
#include "CharaBase.h"
#include "ItemBase.h"
#include "Image.h"

#define _MAX_BULLETE_  30

class Player :public CharaBase,public SphereCollider{
	int score;
	int life;

public:
	int bulflg;
	int BulletsCount;

public:
	Player(T_Location location, float rudius);

public:
	void InitPlayer();
	void ScreenOutPlayer();
    void Update() override;
	void Draw() override;
	void Hit() override;
	void Hit(int BulletsCount);
	void HitPlayer(int damage);
	void HitItem(class ItemBase* item);
	bool LifeCheck();
	int GetScore();
	void addScore(int point);
	void KeyInput();
};