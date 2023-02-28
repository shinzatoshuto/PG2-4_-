#include "EnemyBullet.h"
#include "DxLib.h"

EnemyBullet::EnemyBullet(T_Location location)
	:BulletBase(location, 5.0f, 1, T_Location{ 2,2 }) {
	image = 0;
};

void EnemyBullet::Update() {
	T_Location Location = GetLocation();
	Location.x -= speed.x;
	SetLocation(Location);
}

void EnemyBullet::Draw() {
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), 0xfff000, TRUE);
}

bool EnemyBullet::isBulletDeath() {
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

int EnemyBullet::GetDamage() {
	return damage;
}