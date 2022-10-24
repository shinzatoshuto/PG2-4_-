#include "DxLib.h"
#include "shooter.h"
#include "Title.h"
#include "AbstractScene.h"
#include "Image.h"
#include "GameMain.h"
#include "Key.h"
#define WIDTH 1280
#define HEIGHT 720

Title title;
Shooter shooter;
Image image;
Key key;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	SetMainWindowText("É]ÉìÉrÉQÅ[ÉÄ");
	ChangeWindowMode(TRUE);
	SetGraphMode(WIDTH, HEIGHT, 32);
	if (DxLib_Init() == -1)return -1;

	if (image.DrawImage() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager sceneManager(new GameMain());

	while(ProcessMessage() == 0 && sceneManager.Update() != nullptr/* && !(key.PadOnClick(PAD_INPUT_9)) */&& !(key.KeyOnClick(KEY_INPUT_ESCAPE))){

		ClearDrawScreen();

		sceneManager.Draw();

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}