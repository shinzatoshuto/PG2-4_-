#include "DxLib.h"
#include "Player.h"
#include "shooter.h"
#include "Key.h"
#include "Bullet.h"
#include "HpPotion.h"
#define _DEBUG_MODE_

Player::Player(T_Location location, float radius)
	:SphereCollider(location, radius)
{
	score = 0;
	life = 10;
	bulflg = 1;
	BulletsCount = 0;

	bullets = new BulletBase * [_MAX_BULLETE_];
	for (int i = 0; i < _MAX_BULLETE_; i++) {
		bullets[i] = nullptr;
	}
}

void Player::InitPlayer() {
	T_Location location;
	location.x = 10;
	location.y = 100;
	SetLocation(location);

	this->life = 10;
}

void Player::ScreenOutPlayer() {
	T_Location l;
	l.x = GetLocation().x;
	l.y = GetLocation().y;

	if (l.x < 10) {
		l.x = 10;
		SetLocation(l);
	}
	if (l.x > 1270) {
		l.x = 1270;
		SetLocation(l);
	}
	if (l.y < 10) {
		l.y = 10;
		SetLocation(l);
	}
	if (l.y > 710) {
		l.y = 710;
		SetLocation(l);
	}
}

void Player::Update() {
	KeyInput();

	for (BulletsCount = 0; BulletsCount < _MAX_BULLETE_; BulletsCount++) {
		if (bullets[BulletsCount] == nullptr) {
			break;
		}
		bullets[BulletsCount]->Update();

		if (bullets[BulletsCount]->isBulletDeath()) {
			delete bullets[BulletsCount];      //現在のBulletsCountをデリート
			bullets[BulletsCount] = nullptr;   //現在のBulletsCountにヌルポインタを挿入

			//値を求める
			for (int i = (BulletsCount + 1); i < _MAX_BULLETE_; i++) { // 次の値を調べる処理

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

void Player::Draw() {
#ifdef _DEBUG_MODE_
	DrawFormatString(20, 20, 0xffffff, "Life = %d", this->life);
	DrawFormatString(20, 35, 0xffffff, "BulletsCount = %d", this->BulletsCount);
	DrawFormatString(20, 50, 0xffffff, "bulflg = %d", this->bulflg);
	DrawFormatString(20, 65, 0xffffff, "x = %d", Bullet::x);
	DrawFormatString(20, 80, 0xffffff, "y = %d", Bullet::y);

#endif

	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 0, 255));

	int i;
	for (i = 0; i < _MAX_BULLETE_; i++) {
		if (bullets[i] == nullptr) {
			break;
		}
		bullets[i]->Draw();
	}
}

void Player::Hit() {

}

void Player::Hit(int BulletsCount) {
	delete bullets[BulletsCount];      //現在のBulletsCountをデリート
	bullets[BulletsCount] = nullptr;   //現在のBulletsCountにヌルポインタを挿入

	//値を求める
	for (int i = BulletsCount; i < _MAX_BULLETE_; i++) {

		//＋１がヌルポインタだったらブレイク
		if (bullets[i + 1] == nullptr) {
			break;
		}

		bullets[i] = bullets[i + 1];       //現在の値に＋１の値を代入する
		bullets[i + 1] = nullptr;          //i + 1にヌルポインタを代入する
	}
}

void Player::HitPlayer(int damage) {
	if (damage >= 0) {
		life -= damage;
		if (life < 0) {
			life = 0;
	 	}
	}
}

void Player::HitItem(ItemBase* item) {
	E_ITEM_TYPE type = item->GetType();
	switch (type) {

		//switch文の中で変数の値をいじるときは
		//｛｝を使う
		case E_ITEM_TYPE::Hp_Potion:
		{
			HpPotion* potion = dynamic_cast<HpPotion*>(item);
			if (potion == nullptr) {
				throw - 1;
			}
			this->life += potion->GetHealPower();
			break;
		}

		default:
			break;
	}
}

bool Player::LifeCheck() {
	bool rec = (life <= 0);
	return rec;
}

int Player::GetScore() {
	return score;
}

void Player::addScore(int point) {
	if (point > 0) {
		score += point;
	}
}

void Player::KeyInput() {
	T_Location l;
	if (Key::KeyPresse(KEY_INPUT_W) || Key::PadPresse(PAD_INPUT_UP)) {
		l.x = GetLocation().x;
		l.y = GetLocation().y - 2.0f;
		SetLocation(l);
		bulflg = 1;
	}
	if (Key::KeyPresse(KEY_INPUT_S) || Key::PadPresse(PAD_INPUT_DOWN)) {
		l.x = GetLocation().x;
		l.y = GetLocation().y + 2.0f;
		SetLocation(l);
		bulflg = 2;
	}
	if (Key::KeyPresse(KEY_INPUT_A) || Key::PadPresse(PAD_INPUT_LEFT)) {
		l.x = GetLocation().x - 2.0f;
		l.y = GetLocation().y;
		SetLocation(l);
		bulflg = 3;
	}
	if (Key::KeyPresse(KEY_INPUT_D) || Key::PadPresse(PAD_INPUT_RIGHT)) {
		l.x = GetLocation().x + 2.0f;
		l.y = GetLocation().y;
		SetLocation(l);
		bulflg = 4;
	}
	if (Key::KeyOnClick(KEY_INPUT_E) || Key::PadOnClick(PAD_INPUT_1)) {
		if (BulletsCount < _MAX_BULLETE_ && bullets[BulletsCount] == nullptr) {
			bullets[BulletsCount] = new Bullet(GetLocation());
			bullets[BulletsCount]->num[BulletsCount] = bulflg;
		}
	}
}