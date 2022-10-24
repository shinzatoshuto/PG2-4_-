#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Bullet.h"

class GameMain: public AbstractScene {
	Player* player;
	Bullet* bullet;
	//int* enemy[];

public:
	GameMain()
	{
		T_Location location;
		location.x = 10;
		location.y = 100;

		float radius = 10.f;

		player = new Player(location, radius);
		bullet = new Bullet(location);
	}

	virtual ~GameMain()
	{
		delete player;
	};

	//bool HitCheck();
	virtual AbstractScene* Update() override;
	virtual void Draw() override;
};