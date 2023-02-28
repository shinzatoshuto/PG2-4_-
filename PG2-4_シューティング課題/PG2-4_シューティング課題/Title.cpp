#include "DxLib.h"
#include "Title.h"
#include "shooter.h"
#include "Image.h"
#include "Key.h"
#include "GameMain.h"

extern Shooter shooter;

Title::Title() {
	MenuNumber = 0;
	GameState = 0;
}

AbstractScene* Title::Update() {
	if (Key::PadOnClick(PAD_INPUT_DOWN) || Key::KeyOnClick(KEY_INPUT_S)) {
		if (++MenuNumber > 2) MenuNumber = 0;
	}
	if (Key::PadOnClick(PAD_INPUT_UP) || Key::KeyOnClick(KEY_INPUT_W)) {
		if (--MenuNumber < 0)MenuNumber = 2;
	}

	// Ｚキーでメニュー選択
	if (Key::PadOnClick(PAD_INPUT_A) || Key::KeyOnClick(KEY_INPUT_E)) {
		GameState = MenuNumber + 1;
		/*gmain.g_Score = 0;
		gmain.g_Initflg = 0;
		gmain.g_Stage = 0;*/
	}

	if (GameState == 1) {
		return new GameMain;
	}if (GameState == 2) {

	}if (GameState == 3) {

	} 
	return this;
}

void Title::Draw() {
	DrawGraph(0, 0, Image::TitleImage, FALSE);

	//メニューカーソル（三角形）の表示
	int MenuY = MenuNumber * 97;
	DrawTriangle(840, 400 + MenuY, 900, 415 + MenuY, 840, 430 + MenuY, GetColor(255, 0, 0), TRUE);
}