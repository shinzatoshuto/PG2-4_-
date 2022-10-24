#include "DxLib.h"
#include "Player.h"
#include "shooter.h"
#include "Key.h"
#include "Bullet.h"

extern Key key;

Player::Player(T_Location location, float radius)
	:SphereCollider(location, radius)
{
	score = 0;
	life = 10;

	bullets = new BulletBase * [30];
	for (int i = 0; i < 30; i++) {
		bullets[i] = nullptr;
	}
}

void Player::Update() {
	int BulletsCount;
	for (BulletsCount = 0; BulletsCount < 30; BulletsCount++) {
		if (bullets[BulletsCount] == nullptr) {
			break;
		}
		bullets[BulletsCount]->Update();
	}
	key.Update();

	KeyInput();
}

void Player::Draw() {
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 0, 255));

	int BulletsCount;
	for (BulletsCount = 0; BulletsCount < 30; BulletsCount++) {
		if (bullets[BulletsCount] == nullptr) {
			break;
		}
		bullets[BulletsCount]->Draw();
	}
	DrawFormatString(0, 0, 0xffffff, "%d", key.Pad_NowKey);
}

void Player::Hit() {
}

bool Player::LifeCheck() {
	bool rec = (life <= 0);
	return rec;
}

int Player::GetScore() {
	return score;
}

void Player::KeyInput() {
	T_Location l;
	if (key.KeyPresse(KEY_INPUT_W) || key.Pad_KeyFlg & key.PadPresse(PAD_INPUT_UP)) {
		l.x = GetLocation().x;
		l.y = GetLocation().y - 1.0f;
		SetLocation(l);
	}
	if (key.KeyPresse(KEY_INPUT_S) || key.Pad_KeyFlg & key.PadPresse(PAD_INPUT_DOWN)) {
		l.x = GetLocation().x;
		l.y = GetLocation().y + 1.0f;
		SetLocation(l);
	}
	if (key.KeyPresse(KEY_INPUT_A) || key.Pad_KeyFlg & key.PadPresse(PAD_INPUT_LEFT)) {
		l.x = GetLocation().x - 1.0f;
		l.y = GetLocation().y;
		SetLocation(l);
	}
	if (key.KeyPresse(KEY_INPUT_D) || key.Pad_KeyFlg & key.PadPresse(PAD_INPUT_RIGHT)) {
		l.x = GetLocation().x + 1.0f;
		l.y = GetLocation().y;
		SetLocation(l);
	}

	if (key.KeyOnClick(KEY_INPUT_E) || key.Pad_KeyFlg & key.PadOnClick(PAD_INPUT_1)) {
		int i;
		for (i = 0; i < 30; i++) {
			if (bullets[i] == nullptr) {
				break;
			}
		}
		bullets[i] = new Bullet(GetLocation());
	}
}