#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "ItemBase.h"

class GameMain: public AbstractScene {
	Player* player;
	Enemy** enemy;
	ItemBase** items;

	float count;

public:
	GameMain()
	{
		T_Location location;
		location.x = 10;
		location.y = 100;

		float radius = 10.f;
		count = .0f;

		player = new Player(location, radius);
		enemy = new Enemy* [EnemyMAX];
		for (int i = 0; i < EnemyMAX; i++) {
			enemy[i] = nullptr;
			enemy[i] = new Enemy(T_Location{ 1280 / 2 + count,720 / 2 + count}, 20);
			count += 50.f;
		}

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