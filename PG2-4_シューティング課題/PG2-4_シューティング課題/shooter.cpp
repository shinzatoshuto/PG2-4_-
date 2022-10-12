#include "DxLib.h"
#include "shooter.h"
#include "Title.h"
#include "AbstractScene.h"
#define WIDTH 1280
#define HEIGHT 720

Title title;
Shooter shooter;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	SetMainWindowText("É]ÉìÉrÉQÅ[ÉÄ");
	ChangeWindowMode(TRUE);
	SetGraphMode(WIDTH, HEIGHT, 32);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager sceneManager(new Title());

	while(ProcessMessage() == 0 && sceneManager.Update()!=nullptr && !(title.KeyFlg & PAD_INPUT_7)){
		title.OldKey = title.NowKey;
		title.NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		title.KeyFlg = title.NowKey & ~title.OldKey;

		ClearDrawScreen();

		sceneManager.Draw();

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}