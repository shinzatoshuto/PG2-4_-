#include "Stage.h"

int Stage::StageNum;

void Stage::StageChapter() {
	switch (StageNum) {
	case 0:
		for (int i = 0; i < EnemyMAX; i++) {
			enemy[i] = new Enemy(T_Location{ 1280 / 2 ,720 / 2 }, 20);
		}
		break;

	case 1:
		for (int i = 0; i < EnemyMAX; i++) {
			enemy[i] = new Enemy(T_Location{ 1280 / 2 ,720 / 2 }, 20);
		}
		break;

	default:
		break;
	}
}