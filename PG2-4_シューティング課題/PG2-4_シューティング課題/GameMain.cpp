#include "DxLib.h"
#include "GameMain.h"

//bool GameMain::HitCheck() {
//
//}

AbstractScene* GameMain::Update() {
	player->Update();

	return this;
}

void GameMain::Draw() {
	player->Draw();
}