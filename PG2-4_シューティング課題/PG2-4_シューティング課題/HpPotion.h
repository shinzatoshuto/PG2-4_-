#pragma once
#include "ItemBase.h"

class HpPotion:public ItemBase
{
	int HealPower;

public:
	HpPotion(T_Location);

public:
	virtual void Update();
	virtual void Draw();
	int GetHealPower();
};

