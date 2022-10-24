#include "DxLib.h"
#include "CharaBase.h"

CharaBase::~CharaBase() {
	if (CharaImage != nullptr) {
		delete[] CharaImage;
	}
}

T_Location CharaBase::GetSpeed() {
	return CharaSpeed;
}

void CharaBase::SetSpeed(T_Location Speed) {
	this->CharaSpeed.x = Speed.x;
	this->CharaSpeed.y = Speed.y;
}

BulletBase** CharaBase::GetBullets() {
	return bullets;
}