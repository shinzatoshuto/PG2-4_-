#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
#define Bullets 200
#define EnemyMAX 2

struct T_MoveInformation {
	int pattern;   //�s���p�^�[��
	T_Location destination;  //�ړI�n
	int nextArrayNum;   //���̔z��ԍ�
	int waitFrameTime;  //�҂�����
	int attackType;     //�U���̎��
};

class Enemy:public CharaBase,public SphereCollider
{
private:
	int hp;
	int point;
	int BulletsCount;
	int interval;
	float Move;
	short angle;
	int shotNum;

	float dx;
	float dy;
	float Angle;

	T_MoveInformation moveInfo[5] = {};
	int current = 0;
	int waitTime = 0;

public:
	static int AcType;

public:
	Enemy(T_Location location, float rudius);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit()override;
	void HitPlayer(int bulletcount);
	void Hit(int damage);
	bool HpCheck();
	int GetPoint();
	void EnemyMove(float PlayerY, float PlayerX);
	void EMove();
	void inputCSV();
};