#include "DxLib.h"
#include <math.h>
#include "SphereCollider.h"

SphereCollider::SphereCollider(T_Location location, float radius) {
	this->location.x = location.x;
	this->location.y = location.y;
	this->radius = radius;
}

//当たり判定
bool SphereCollider::HitSphere(SphereCollider s) {
	//円と円の当たり判定
	//自分から相手のベクトルを求める
	T_Location location = s.GetLocation();
	float x = this->location.x - location.x;
	float y = this->location.y - location.y;

	//絶対値に変換
	x = fabsf(x);
	y = fabsf(y);

	//ベクトルの大きさを取得
	float xy = (x * x) + (y * y);
	double VectorSize = sqrt(xy); //平方根

	float radius = this->radius + s.GetRadius();

	//自分の半径 ＋ 相手の半径　より小さい時当たってる
	bool ret = (VectorSize <= radius);
	return ret;
}

float SphereCollider::GetRadius() {
	return radius;
}

T_Location SphereCollider::GetLocation() {
	return location;
}

void SphereCollider::SetLocation(T_Location value) {
	location.x = value.x;
	location.y = value.y;
}