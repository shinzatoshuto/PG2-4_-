#include "DxLib.h"
#include "Bullet.h"
#include "Player.h"

int Bullet::x;
int Bullet::y;
int Bullet::bull[_MAX_BULLETE_];

Bullet::Bullet(T_Location location)
	:BulletBase(location, 5.0f,1, T_Location{ 10,10 }) {
	image = 0;
	x = 0;
	y = 0;
};

void Bullet::Update() {
	T_Location Location = GetLocation();
	Location.x += speed.x;
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

