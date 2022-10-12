#include "DxLib.h"
#include "Title.h"
#include "shooter.h"

extern Shooter shooter;

AbstractScene* Title::Update() {
	if (KeyFlg & PAD_INPUT_DOWN & KEY_INPUT_DOWN) {
		if (++MenuNumber > 2) MenuNumber = 0;
	}if (KeyFlg & PAD_INPUT_UP & KEY_INPUT_UP) {
		if (--MenuNumber < 0)MenuNumber = 2;
	}

	//if (shooter.GameState == 1) {

	//}if (shooter.GameState == 2) {

	//}if (shooter.GameState == 3) {

	//}
}

void Title::Draw() {
	DrawGraph(0, 0, TitleImage, FALSE);

	//メニューカーソル（三角形）の表示
	int g_MenuY = MenuNumber * 52;
	DrawTriangle(240, 255 + g_MenuY, 260, 270 + g_MenuY, 240, 285 + g_MenuY, GetColor(255, 0, 0), TRUE);
}