#include "DxLib.h"
#include <math.h>
#include "SphereCollider.h"

SphereCollider::SphereCollider(T_Location location, float radius) {
	this->location.x = location.x;
	this->location.y = location.y;
	this->radius = radius;
}

//�����蔻��
bool SphereCollider::HitSphere(SphereCollider s) {
	//�~�Ɖ~�̓����蔻��
	//�������瑊��̃x�N�g�������߂�
	T_Location location = s.GetLocation();
	float x = this->location.x - location.x;
	float y = this->location.y - location.y;

	//��Βl�ɕϊ�
	x = fabsf(x);
	y = fabsf(y);

	//�x�N�g���̑傫�����擾
	float xy = (x * x) + (y * y);
	double VectorSize = sqrt(xy); //������

	float radius = this->radius + s.GetRadius();

	//�����̔��a �{ ����̔��a�@��菬�������������Ă�
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