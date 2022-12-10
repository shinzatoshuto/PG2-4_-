#include "DxLib.h"
#include "Bullet.h"
#include "Player.h"

int Bullet::x;
int Bullet::y;
int Bullet::bull[30];

Bullet::Bullet(T_Location location)
	:BulletBase(location, 5.0f,1, T_Location{ 30,30 }) {
	image = 0;
	x = 0;
	y = 0;
};

void Bullet::Update() {
	T_Location Location = GetLocation();
	for (int i = 0; i < 30; i++) {
		switch (num[i]) {
		case 1:
			Location.y -= speed.y;
			break;
		case 2:
			Location.y += speed.y;
			break;
		case 3:
			Location.x -= speed.x;
			break;
		case 4:
			Location.x += speed.x;
			break;
		}
	}

	SetLocation(Location);
}

void Bullet::Draw() {
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), 0xff0000, TRUE);
}

bool Bullet::isBulletDeath() {
	float x = GetLocation().x + GetRadius();
	float y = GetLocation().y + GetRadius();

	if (x < 0) {
		return true;
	}
	if (x > 1280) {
		return true;
	}
	if (y < 0) {
		return true;
	}
	if (y > 720) {
		return true;
	}

	return false;
}

int Bullet::GetDamage() {
	return damage;
}

