#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "ItemBase.h"

class GameMain: public AbstractScene {
	Player* player;
	Enemy** enemy;
	ItemBase** items;

	int EnemyCount = 0;

public:
	GameMain()
	{
		T_Location location;
		location.x = 10;
		location.y = 100;

		float radius = 10.f;

		player = new Player(location, radius);
		enemy = new Enemy* [10];
		for (int i = 0; i < 10; i++) {
			enemy[i] = nullptr;
		}
		enemy[0] = new Enemy(T_Location{ 300,0 }, 20);

		items = new ItemBase * [10];
		for (int i = 0; i < 10; i++) {
			items[i] = nullptr;
		}
	}

	virtual ~GameMain()
	{
		delete player;
	};

	//bool HitCheck();
	virtual AbstractScene* Update() override;
	virtual void Draw() override;
};