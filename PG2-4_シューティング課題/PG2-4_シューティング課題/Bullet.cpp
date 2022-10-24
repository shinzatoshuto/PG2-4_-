#include "DxLib.h"
#include "Bullet.h"

Bullet::Bullet(T_Location location)
	:BulletBase(location, 5.0f,1, T_Location{ 0,2 }) {
	image = 0;
};

void Bullet::Update() {
	T_Location Location = GetLocation();
	Location.y -= speed.y;
	SetLocation(Location);
}

void Bullet::Draw() {
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), 0xff0000, TRUE);
}