#include "DxLib.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include <math.h>
#include "CircleEnemyBullet.h"

#define Attacking_Interval 20
int Enemy::AcType;

//void Enemy::inputCSV()
//{
//	FILE* fp;    //FILE�^�\����
//	errno_t error;
//	error = fopen_s(&fp, "Data/Enemy.csv", "r");
//
//	if (error != 0)
//	{
//		//�t�@�C�����J���ĂȂ�
//		return;
//	}
//	else
//	{
//		//�t�@�C�����J����
//		char line[100];
//		for (int i = 0; fgets(line, 100, fp) != NULL; i++) {
//			sscanf_s(line, "%d, %f, %f, %d, %d, %d", 
//				&moveInfo[i].pattern,
//				&moveInfo[i].destination.x,
//				&moveInfo[i].destination.y,
//				&moveInfo[i].nextArrayNum,
//				&moveInfo[i].waitFrameTime,
//				&moveInfo[i].attackType
//			);
//		}
//		return;
//	}
//
//	fclose(fp);  //�t�@�C�������
//}

Enemy::Enemy(T_Location location, float rudius)
	:SphereCollider(location, rudius) {
	//inputCSV();

	hp = 10;
	point = 10;
	BulletsCount = 0;
	interval = 0;
	Move = 0;
	shotNum = 0;
	AcType = 0;

	CharaSpeed = T_Location{ 3.0,3.0 };

	bullets = new BulletBase * [Bullets];
	for (int i = 0; i < Bullets; i++) {
		bullets[i] = nullptr;
	}
}

void Enemy::Update() {

	/*switch (moveInfo[current].pattern) {
	case 0:
		EMove();
		break;

	case 1:
		if (moveInfo[current].waitFrameTime <= waitTime++) {
			waitTime = 0;
			current = moveInfo[current].nextArrayNum;
		}
		break;

	default:
		break;
	}*/

	//EnemyMove(GetPlayerY, GetPlayerX);
	/*shotNum++;
	bullets[BulletsCount] = new CircleEnemyBullet(GetLocation(), 3.f, (20 * shotNum));*/
	//bullets[BulletsCount] = new EnemyBullet(GetLocation());

	/*if (moveInfo[current].attackType != 0) {
		interval++;
		if (Attacking_Interval <= interval) {
			if (BulletsCount < Bullets && bullets[BulletsCount] == nullptr) {
				interval = 0;
				if (moveInfo[current].attackType == 1) {
					bullets[BulletsCount] = new EnemyBullet(GetLocation());
				}
				else if (moveInfo[current].attackType == 2) {
					shotNum++;
					bullets[BulletsCount] = new CircleEnemyBullet(GetLocation(), 3.f, (20 * shotNum));
				}
			}
		}
	}*/

	interval++;
	if (Attacking_Interval <= interval) {
		if (BulletsCount < Bullets && bullets[BulletsCount] == nullptr) {
			interval = 0;
			if (AcType == 1) {
				bullets[BulletsCount] = new EnemyBullet(GetLocation());
			}
			else if (AcType == 2) {
				shotNum++;
				bullets[BulletsCount] = new CircleEnemyBullet(GetLocation(), 3.f, (20 * shotNum));
			}
		}
	}

	for (BulletsCount = 0; BulletsCount < Bullets; BulletsCount++) {
		if (bullets[BulletsCount] == nullptr) {
			break;
		}
		bullets[BulletsCount]->Update();

		if (bullets[BulletsCount]->isBulletDeath()) {
			delete bullets[BulletsCount];      //���݂�BulletsCount���f���[�g
			bullets[BulletsCount] = nullptr;   //���݂�BulletsCount�Ƀk���|�C���^��}��

			//�l�����߂�
			for (int i = (BulletsCount + 1); i < Bullets; i++) { //���̒l�𒲂ׂ鏈��

				//�{�P���k���|�C���^��������u���C�N
				if (bullets[i] == nullptr) {
					break;
				}

				bullets[i - 1] = bullets[i];       //i - 1�Ɍ��݂̒l��������
				bullets[i] = nullptr;          //i�Ƀk���|�C���^��������
			}

			bullets[BulletsCount--];   //�}�C�i�X���Č��݂̒l�����߂�
		}
	}

}

void Enemy::Draw() {
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), 0xffff00, TRUE);
	int i;
	for (i = 0; i < Bullets; i++) {
		if (bullets[i] == nullptr) {
			break;
		}
		bullets[i]->Draw();
	}
	DrawFormatString(10, 40, 0xffffff, "%d", BulletsCount);
	DrawFormatString(500, 400, 0xffffff, "%lf", dx);
	DrawFormatString(500, 450, 0xffffff, "%lf", dy);
	DrawFormatString(500, 500, 0xffffff, "%lf", Angle);
}

void Enemy::Hit() {

}

void Enemy::HitPlayer(int bulletcount) {
	delete bullets[bulletcount];      //���݂�BulletsCount���f���[�g
	bullets[bulletcount] = nullptr;   //���݂�BulletsCount�Ƀk���|�C���^��}��

	//�l�����߂�
	for (int i = bulletcount; i < Bullets; i++) {

		//�{�P���k���|�C���^��������u���C�N
		if (bullets[i + 1] == nullptr) {
			break;
		}

		bullets[i] = bullets[i + 1];       //���݂̒l�Ɂ{�P�̒l��������
		bullets[i + 1] = nullptr;          //i + 1�Ƀk���|�C���^��������
	}
}

void Enemy::Hit(int damage) {
	if (damage >= 0) {
		hp -= damage;
		if (hp < 0) {
			hp = 0;
		}
	}
}

bool Enemy::HpCheck() {
	bool rex = (hp <= 0);
	return rex;
}

int Enemy::GetPoint() {
	return point;
}

void Enemy::EnemyMove(float PlayerY, float PlayerX) {

	//�G�l�~�[�ǔ�
	T_Location location = GetLocation();

	//�G�l�~�[�ƃv���C���[�̊p�x�Ƌ���
	dx = PlayerX - location.x;
	dy = PlayerY - location.y;
	Angle = atanf(dy / dx);

	if (location.x < PlayerX) {
		location.x += 0.5f;
	}
	else {
		location.x -= 0.5f;
	}

	if (location.y < PlayerY) {
		location.y += 0.5f;
	}
	else {
		location.y -= 0.5f;
	}

	SetLocation(location);
	
}

void Enemy::EMove() {
	T_Location newLocation = GetLocation();

	/*�ړ��������ړ���؂�ւ��鏈��*/
	if ((newLocation.x == moveInfo[current].destination.x) && (newLocation.y == moveInfo[current].destination.y)) {
		current = moveInfo[current].nextArrayNum;
		return;
	}
	else {
		/*�ړI�n����Ȃ�������*/
		if (newLocation.x != moveInfo[current].destination.x) {
			/*�ړI�̕����傫��������*/
			if (newLocation.x < moveInfo[current].destination.x) {
				/*X�Ƀv���X����*/
				newLocation.x += CharaSpeed.x;

				/*�ړI�n���傫���Ȃ�����*/
				if (moveInfo[current].destination.x < newLocation.x) {
					newLocation.x = moveInfo[current].destination.x;
				}
			}
			else {
				/*X�Ƀ}�C�i�X����*/
				newLocation.x -= CharaSpeed.x;

				/*�ړI�n���傫���Ȃ�����*/
				if (newLocation.x < moveInfo[current].destination.x) {
					newLocation.x = moveInfo[current].destination.x;
				}
			}
		}

		/*�ړI�n����Ȃ�������*/
		if (newLocation.y != moveInfo[current].destination.y) {
			/*�ړI�̕����傫��������*/
			if (newLocation.y < moveInfo[current].destination.y) {
				/*X�Ƀv���X����*/
				newLocation.y += CharaSpeed.y;

				/*�ړI�n���傫���Ȃ�����*/
				if (moveInfo[current].destination.y < newLocation.y) {
					newLocation.y = moveInfo[current].destination.y;
				}
			}
			else {
				/*X�Ƀ}�C�i�X����*/
				newLocation.y -= CharaSpeed.y;

				/*�ړI�n���傫���Ȃ�����*/
				if (newLocation.y < moveInfo[current].destination.y) {
					newLocation.y = moveInfo[current].destination.y;
				}
			}
		}
	}

	SetLocation(newLocation);
}