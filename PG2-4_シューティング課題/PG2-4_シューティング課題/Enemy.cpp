#include "DxLib.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include <math.h>

int Enemy::turn;

Enemy::Enemy(T_Location location, float rudius)
	:SphereCollider(location, rudius) {
	hp = 10;
	point = 10;
	BulletsCount = 0;
	interval = 0;
	turn = 0;
	Move = 0;

	CharaSpeed = T_Location{ 1.0,1.0 };

	bullets = new BulletBase * [30];
	for (int i = 0; i < 30; i++) {
		bullets[i] = nullptr;
	}
}

void Enemy::Update() {
	T_Location Location = GetLocation();
	switch (turn) {
	case 0:
		Location.y += CharaSpeed.y;
		if (Location.y > 720) {
			turn = 1;
			break;
		}
		break;
	case 1:
		Location.y -= CharaSpeed.y;
		if (Location.y < 0) {
			turn = 0;
			break;
		}
		break;
	}

	/*Move = atan2(-float(player->GetLocation().y - this->GetLocation().y), float(player->GetLocation().x - this->GetLocation().x));
	Move /= 3.14;
	Move *= 180;
	Move += 360;
	angle = (short)Move % 360;*/


	SetLocation(Location);

	if (interval > 30) {
		if (BulletsCount < 30 && bullets[BulletsCount] == nullptr) {
			bullets[BulletsCount] = new EnemyBullet(GetLocation());
			interval = 0;
		}
	}
	interval++;

	for (BulletsCount = 0; BulletsCount < 30; BulletsCount++) {
		if (bullets[BulletsCount] == nullptr) {
			break;
		}
		bullets[BulletsCount]->Update();

		if (bullets[BulletsCount]->isBulletDeath()) {
			delete bullets[BulletsCount];      //���݂�BulletsCount���f���[�g
			bullets[BulletsCount] = nullptr;   //���݂�BulletsCount�Ƀk���|�C���^��}��

			//�l�����߂�
			for (int i = (BulletsCount + 1); i < 30; i++) { //���̒l�𒲂ׂ鏈��

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
	for (i = 0; i < 30; i++) {
		if (bullets[i] == nullptr) {
			break;
		}
		bullets[i]->Draw();
	}
	DrawFormatString(10, 40, 0xffffff, "%d", BulletsCount);
}

void Enemy::Hit() {

}

void Enemy::HitPlayer(int bulletcount) {
	delete bullets[bulletcount];      //���݂�BulletsCount���f���[�g
	bullets[bulletcount] = nullptr;   //���݂�BulletsCount�Ƀk���|�C���^��}��

	//�l�����߂�
	for (int i = bulletcount; i < 30; i++) {

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

int Enemy::GetPlayerLocation(float y, float x) {
	return y, x;
}