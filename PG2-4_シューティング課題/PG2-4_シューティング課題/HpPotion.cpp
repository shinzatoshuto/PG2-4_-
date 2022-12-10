#include "DxLib.h"
#include "HpPotion.h"

HpPotion::HpPotion(T_Location location)
	:ItemBase(location, 5.0f, E_ITEM_TYPE::Hp_Potion, T_Location{ 0,0.5f }), HealPower(2)
{

}

void HpPotion::Update() {
	T_Location Location = GetLocation();
	Location.y += speed.y;
	SetLocation(Location);
}

void HpPotion::Draw() {
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), 0xff00ff, TRUE);
}

int HpPotion::GetHealPower() {
	return HealPower;
}