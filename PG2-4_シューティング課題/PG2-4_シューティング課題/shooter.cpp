#include "DxLib.h"
#include "shooter.h"
#include "AbstractScene.h"
#define WIDTH 1280
#define HEIGHT 720

int KeyFlg = 0;
int NowKey = 0;
int OldKey = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	SetMainWindowText("É]ÉìÉrÉQÅ[ÉÄ");
	ChangeWindowMode(TRUE);
	SetGraphMode(WIDTH, HEIGHT, 32);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager sceneManager();

	while(ProcessMessage() == 0 && sceneManager.UpDate()!=nullptr && !(KeyFlg & PAD_INPUT_7)){
		OldKey = NowKey;
		NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		KeyFlg = NowKey & ~OldKey;
		ClearDrawScreen();

		sceneManager.Draw();

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}