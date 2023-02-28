#include "DxLib.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include <math.h>
#include "CircleEnemyBullet.h"

#define Attacking_Interval 20
int Enemy::AcType;

//void Enemy::inputCSV()
//{
//	FILE* fp;    //FILE型構造体
//	errno_t error;
//	error = fopen_s(&fp, "Data/Enemy.csv", "r");
//
//	if (error != 0)
//	{
//		//ファイルが開けてない
//		return;
//	}
//	else
//	{
//		//ファイルが開けた
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
//	fclose(fp);  //ファイルを閉じる
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
			delete bullets[BulletsCount];      //現在のBulletsCountをデリート
			bullets[BulletsCount] = nullptr;   //現在のBulletsCountにヌルポインタを挿入

			//値を求める
			for (int i = (BulletsCount + 1); i < Bullets; i++) { //次の値を調べる処理

				//＋１がヌルポインタだったらブレイク
				if (bullets[i] == nullptr) {
					break;
				}

				bullets[i - 1] = bullets[i];       //i - 1に現在の値を代入する
				bullets[i] = nullptr;          //iにヌルポインタを代入する
			}

			bullets[BulletsCount--];   //マイナスして現在の値を求める
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
	delete bullets[bulletcount];      //現在のBulletsCountをデリート
	bullets[bulletcount] = nullptr;   //現在のBulletsCountにヌルポインタを挿入

	//値を求める
	for (int i = bulletcount; i < Bullets; i++) {

		//＋１がヌルポインタだったらブレイク
		if (bullets[i + 1] == nullptr) {
			break;
		}

		bullets[i] = bullets[i + 1];       //現在の値に＋１の値を代入する
		bullets[i + 1] = nullptr;          //i + 1にヌルポインタを代入する
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

	//エネミー追尾
	T_Location location = GetLocation();

	//エネミーとプレイヤーの角度と距離
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

	/*移動処理＆移動を切り替える処理*/
	if ((newLocation.x == moveInfo[current].destination.x) && (newLocation.y == moveInfo[current].destination.y)) {
		current = moveInfo[current].nextArrayNum;
		return;
	}
	else {
		/*目的地じゃなかったら*/
		if (newLocation.x != moveInfo[current].destination.x) {
			/*目的の方が大きかったら*/
			if (newLocation.x < moveInfo[current].destination.x) {
				/*Xにプラスする*/
				newLocation.x += CharaSpeed.x;

				/*目的地より大きくなったら*/
				if (moveInfo[current].destination.x < newLocation.x) {
					newLocation.x = moveInfo[current].destination.x;
				}
			}
			else {
				/*Xにマイナスする*/
				newLocation.x -= CharaSpeed.x;

				/*目的地より大きくなったら*/
				if (newLocation.x < moveInfo[current].destination.x) {
					newLocation.x = moveInfo[current].destination.x;
				}
			}
		}

		/*目的地じゃなかったら*/
		if (newLocation.y != moveInfo[current].destination.y) {
			/*目的の方が大きかったら*/
			if (newLocation.y < moveInfo[current].destination.y) {
				/*Xにプラスする*/
				newLocation.y += CharaSpeed.y;

				/*目的地より大きくなったら*/
				if (moveInfo[current].destination.y < newLocation.y) {
					newLocation.y = moveInfo[current].destination.y;
				}
			}
			else {
				/*Xにマイナスする*/
				newLocation.y -= CharaSpeed.y;

				/*目的地より大きくなったら*/
				if (newLocation.y < moveInfo[current].destination.y) {
					newLocation.y = moveInfo[current].destination.y;
				}
			}
		}
	}

	SetLocation(newLocation);
}