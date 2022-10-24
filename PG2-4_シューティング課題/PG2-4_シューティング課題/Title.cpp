#include "DxLib.h"
#include "Title.h"
#include "shooter.h"
#include "Image.h"
#include "Key.h"

extern Shooter shooter;
extern Key key;
extern Image image;

AbstractScene* Title::Update() {
	if (key.Pad_KeyFlg & PAD_INPUT_DOWN & KEY_INPUT_S) {
		if (++MenuNumber > 2) MenuNumber = 0;
	}
	if (key.Pad_KeyFlg & PAD_INPUT_UP) {
		if (--MenuNumber < 0)MenuNumber = 2;
	}

	// Ｚキーでメニュー選択
	if (key.Pad_KeyFlg & PAD_INPUT_A) {
		shooter.GameState = MenuNumber + 1;
		/*gmain.g_Score = 0;
		gmain.g_Initflg = 0;
		gmain.g_Stage = 0;*/
	}

	if (shooter.GameState == 1) {

	}if (shooter.GameState == 2) {

	}if (shooter.GameState == 3) {

	}
	return this;
}

void Title::Draw() {
	DrawGraph(0, 0, image.TitleImage, FALSE);

	//メニューカーソル（三角形）の表示
	int MenuY = MenuNumber * 97;
	DrawTriangle(840, 400 + MenuY, 900, 415 + MenuY, 840, 430 + MenuY, GetColor(255, 0, 0), TRUE);
}