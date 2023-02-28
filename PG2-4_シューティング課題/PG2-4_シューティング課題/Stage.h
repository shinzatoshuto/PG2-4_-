#pragma once
#include "DxLib.h"
#include "Enemy.h"

class Stage
{
public:
	static int StageNum;
	Enemy** enemy;

public:
	Stage(){
		enemy = new Enemy * [EnemyMAX];
		for (int i = 0; i < EnemyMAX; i++) {
			enemy[i] = nullptr;
		}
	}
	~Stage() {};

	void StageChapter();

};

