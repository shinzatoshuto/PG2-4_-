#include "DxLib.h"
#include "GameMain.h"
#include "HpPotion.h"
#include "GameClear.h"
#include "GameOver.h"

//bool GameMain::HitCheck() {
//
//}

AbstractScene* GameMain::Update() {
	player->Update();

	for (int i = 0; i < EnemyMAX; i++) {
		if (enemy[i] == nullptr) {
			break;
		}
		//enemy[i]->EnemyMove(player->GetLocation().y, player->GetLocation().x);
		enemy[i]->Update();
	}

	for (int i = 0; i < 10; i++) {
		if (items[i] == nullptr) {
			break;
		}
		items[i]->Update();
	}

	//プレイヤーの弾の当たり判定
	for (int bulletscount = 0; bulletscount < _MAX_BULLETE_; bulletscount++ ) {
		BulletBase** bullets = player->GetBullets();
		if (bullets[bulletscount] == nullptr) {
			break;
		}
		for (int EnemyCount = 0; EnemyCount < EnemyMAX; EnemyCount++) {
			if (enemy[EnemyCount] == nullptr) {
				break;
			}

			if (bullets[bulletscount]->HitSphere(enemy[EnemyCount])) {
				//弾のダメージをエネミーに与える
				enemy[EnemyCount]->Hit(bullets[bulletscount]->GetDamage());

				//プレイヤーの弾とエネミーが当たった
				//弾を消す
				player->Hit(bulletscount);
				bullets = player->GetBullets();
				bulletscount--;

				//エネミーのhpがゼロ以下であれば、エネミーを消す
				if (enemy[EnemyCount]->HpCheck()) {


					for (int i = 0; i < 10; i++) {
						if (items[i] == nullptr) {
							items[i] = new HpPotion(enemy[EnemyCount]->GetLocation());
							break;
						}
					}

					//エネミーを消したときに、プレイヤーのスコアに、
					//エネミーのポイントを加算する
					player->addScore(enemy[EnemyCount]->GetPoint());

					delete enemy[EnemyCount];
					enemy[EnemyCount] = nullptr;
					for (int i = (EnemyCount + 1); i < EnemyMAX; i++) { // 次の値を調べる処理

						//iがヌルポインタだったらブレイク
						if (enemy[i] == nullptr) {
							break;
						}

						enemy[i - 1] = enemy[i];       //i - 1に現在の値を代入する
						enemy[i] = nullptr;          //iにヌルポインタを代入する
					}
				}

				break;
			}
		}
	}

	//アイテムとプレイヤーの当たり判定
	for (int ItemCount = 0; ItemCount < 10; ItemCount++) {

		//＋１がヌルポインタだったらブレイク
		if (items[ItemCount] == nullptr) {
			break;
		}

		if (player->HitSphere(items[ItemCount])) {
			player->HitItem(items[ItemCount]);

			delete items[ItemCount];
			items[ItemCount] = nullptr;

			return new GameClear;

			for (int i = ItemCount + 1; i < 10; i++) {
				if (items[ItemCount] == nullptr) {
					break;
				}

				items[i - 1] = items[i];       //現在の値に＋１の値を代入する
				items[i] = nullptr;          //i + 1にヌルポインタを代入する
			}
		}
	}

	//エネミーの弾の当たり判定
	for (int EnemyCount = 0; EnemyCount < EnemyMAX; EnemyCount++) {
		if (enemy[EnemyCount] == nullptr) {
			break;
		}
		BulletBase** enemybullets = enemy[EnemyCount]->GetBullets();
		for (int enemybulletscount = 0; enemybulletscount < Bullets; enemybulletscount++) {
			if (enemybullets[enemybulletscount] == nullptr) {
				break;
			}
			if (enemybullets[enemybulletscount]->HitSphere(player)) {
				//弾のダメージをプレイヤーに与える
				player->HitPlayer(enemybullets[enemybulletscount]->GetDamage());

				//エネミーの弾とプレイヤーが当たった
				//弾を消す
				enemy[EnemyCount]->HitPlayer(enemybulletscount);
				enemybullets = enemy[EnemyCount]->GetBullets();
				enemybulletscount--;

				//プレイヤ―のhpがゼロ以下であれば、プレイヤーを消す
				if (player->LifeCheck()) {
					//player->InitPlayer();
					return new GameOver;
				}
				break;
			}
		}
	}

	player->ScreenOutPlayer();

	return this;
}

void GameMain::Draw() {
	player->Draw();
	for (int i = 0; i < EnemyMAX; i++) {
		if (enemy[i] == nullptr) {
			break;
		}
		enemy[i]->Draw();
	}

	for (int i = 0; i < 10; i++) {
		if (items[i] == nullptr) {
			break;
		}
		items[i]->Draw();
	}
}
