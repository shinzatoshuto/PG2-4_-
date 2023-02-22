#include "CircleEnemyBullet.h"

#define _USE_MATH_DEFINES
#include <math.h>

CircleEnemyBullet::CircleEnemyBullet(T_Location location, float speed, int degAngle)
	:BulletBase(location, 5.0f, 1, T_Location{ 2,2 }) {
	int deg = degAngle % 360;
	double rad = (M_PI / 180) * deg;
	float x = (abs(deg) == 90 || abs(deg) == 270) ? 0 : cos(rad);
	float y = sin(rad);

	this->speed = T_Location{ (speed * x),(speed * y) };
}

void CircleEnemyBullet::Update() {
	T_Location Location = GetLocation();

	Location.x += speed.x;
	Location.y += speed.y;

	SetLocation(Location);
}

void CircleEnemyBullet::Draw() {
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), 0xfff000, TRUE);
}

bool CircleEnemyBullet::isBulletDeath() {
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

int CircleEnemyBullet::GetDamage() {
	return damage;
}