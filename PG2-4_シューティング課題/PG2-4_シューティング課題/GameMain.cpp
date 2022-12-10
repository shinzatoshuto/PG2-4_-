#include "DxLib.h"
#include "GameMain.h"
#include "HpPotion.h"

//bool GameMain::HitCheck() {
//
//}

AbstractScene* GameMain::Update() {
	player->Update();

	for (int i = 0; i < 10; i++) {
		if (enemy[i] == nullptr) {
			break;
		}
		enemy[i]->Update();
		enemy[i]->GetPlayerLocation(player->GetLocation().y, player->GetLocation().x);
	}

	for (int i = 0; i < 10; i++) {
		if (items[i] == nullptr) {
			break;
		}
		items[i]->Update();
	}



	BulletBase** bullets = player->GetBullets();
	for (int bulletscount = 0; bulletscount < 30; bulletscount++ ) {
		if (bullets[bulletscount] == nullptr) {
			break;
		}
		for (EnemyCount = 0; EnemyCount < 10; EnemyCount++) {
			if (enemy[EnemyCount] == nullptr) {
				break;
			}

			if (bullets[bulletscount]->HitSphere(enemy[EnemyCount])) {
				//�e�̃_���[�W���G�l�~�[�ɗ^����
				enemy[EnemyCount]->Hit(bullets[bulletscount]->GetDamage());

				//�v���C���[�̒e�ƃG�l�~�[����������
				//�e������
				player->Hit(bulletscount);
				bullets = player->GetBullets();
				bulletscount--;

				//�G�l�~�[��hp���[���ȉ��ł���΁A�G�l�~�[������
				if (enemy[EnemyCount]->HpCheck()) {


					for (int i = 0; i < 10; i++) {
						if (items[i] == nullptr) {
							items[i] = new HpPotion(enemy[EnemyCount]->GetLocation());
							break;
						}
					}

					//�G�l�~�[���������Ƃ��ɁA�v���C���[�̃X�R�A�ɁA
					//�G�l�~�[�̃|�C���g�����Z����
					player->addScore(enemy[EnemyCount]->GetPoint());

					delete enemy[EnemyCount];
					enemy[EnemyCount] = nullptr;
					for (int i = (EnemyCount + 1); i < 10; i++) { // ���̒l�𒲂ׂ鏈��

						//i���k���|�C���^��������u���C�N
						if (enemy[i] == nullptr) {
							break;
						}

						enemy[i - 1] = enemy[i];       //i - 1�Ɍ��݂̒l��������
						enemy[i] = nullptr;          //i�Ƀk���|�C���^��������
					}
				}
			}
		}
	}

	//�A�C�e���ƃv���C���[�̓����蔻��
	for (int ItemCount = 0; ItemCount < 10; ItemCount++) {

		//�{�P���k���|�C���^��������u���C�N
		if (items[ItemCount] == nullptr) {
			break;
		}

		if (player->HitSphere(items[ItemCount])) {
			player->HitItem(items[ItemCount]);

			delete items[ItemCount];
			items[ItemCount] = nullptr;
			for (int i = ItemCount + 1; i < 10; i++) {
				if (items[ItemCount] == nullptr) {
					break;
				}

				items[i - 1] = items[i];       //���݂̒l�Ɂ{�P�̒l��������
				items[i] = nullptr;          //i + 1�Ƀk���|�C���^��������
			}
		}
	}

	for (EnemyCount = 0; EnemyCount < 10; EnemyCount++) {
		if (enemy[EnemyCount] == nullptr) {
			break;
		}
		BulletBase** enemybullets = enemy[EnemyCount]->GetBullets();
		for (int enemybulletscount = 0; enemybulletscount < 30; enemybulletscount++) {
			if (enemybullets[enemybulletscount] == nullptr) {
				break;
			}
			if (enemybullets[enemybulletscount]->HitSphere(player)) {
				//�e�̃_���[�W���v���C���[�ɗ^����
				player->HitPlayer(enemybullets[enemybulletscount]->GetDamage());

				//�G�l�~�[�̒e�ƃv���C���[����������
				//�e������
				enemy[EnemyCount]->HitPlayer(enemybulletscount);
				enemybullets = enemy[EnemyCount]->GetBullets();
				enemybulletscount--;

				//�v���C���\��hp���[���ȉ��ł���΁A�v���C���[������
				if (player->LifeCheck()) {
					player->InitPlayer();
				}
			}
		}
	}

	player->ScreenOutPlayer();

	return this;
}

void GameMain::Draw() {
	player->Draw();
	for (int i = 0; i < 10; i++) {
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
