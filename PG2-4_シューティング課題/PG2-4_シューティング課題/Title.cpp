#include "DxLib.h"
#include "Title.h"
#include "shooter.h"
#include "Image.h"

extern Shooter shooter;
extern Image image;

AbstractScene* Title::Update() {
	if (shooter.KeyFlg & PAD_INPUT_DOWN & KEY_INPUT_S) {
		if (++MenuNumber > 2) MenuNumber = 0;
	}
	if (shooter.KeyFlg & PAD_INPUT_UP) {
		if (--MenuNumber < 0)MenuNumber = 2;
	}

	//if (shooter.GameState == 1) {

	//}if (shooter.GameState == 2) {

	//}if (shooter.GameState == 3) {

	//}
	return this;
}

void Title::Draw() {
	DrawGraph(0, 0, image.TitleImage, FALSE);

	//���j���[�J�[�\���i�O�p�`�j�̕\��
	int MenuY = MenuNumber * 97;
	DrawTriangle(840, 400 + MenuY, 900, 415 + MenuY, 840, 430 + MenuY, GetColor(255, 0, 0), TRUE);
}