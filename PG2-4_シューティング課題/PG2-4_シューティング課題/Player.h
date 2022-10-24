#pragma once
#include "CharaBase.h"

class Player :public CharaBase,public SphereCollider{
	int score;
	int life;

public:
	Player(T_Location location, float rudius);

public:
    void Update() override;
	void Draw() override;
	void Hit() override;
	bool LifeCheck();
	int GetScore();
	void KeyInput();
};