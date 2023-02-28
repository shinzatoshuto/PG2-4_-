#include "Stage.h"

int Stage::StageNum;

void Stage::StageChapter() {
	switch (StageNum) {
	case 0:
		enemy[0] = new Enemy(T_Location{ 1260 ,720 / 2 }, 20);
		break;

	case 1:
		enemy[0] = new Enemy(T_Location{ 1260 ,720 / 3 }, 20);
		enemy[1] = new Enemy(T_Location{ 1260 ,720 / 2 }, 20);
		break;

	default:
		break;
	}
}