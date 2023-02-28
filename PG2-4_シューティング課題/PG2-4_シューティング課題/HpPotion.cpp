#include "DxLib.h"
#include "HpPotion.h"

HpPotion::HpPotion(T_Location location)
	:ItemBase(location, 5.0f, E_ITEM_TYPE::Hp_Potion, T_Location{ 0.5f, 0 }), HealPower(2)
{

}

void HpPotion::Update() {
	T_Location Location = GetLocation();
	Location.x -= speed.x;
	SetLocation(Location);
}

void HpPotion::Draw() {
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), 0xff00ff, TRUE);
}

int HpPotion::GetHealPower() {
	return HealPower;
}