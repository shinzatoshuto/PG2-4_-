#include "DxLib.h"
#include "shooter.h"
#include "Title.h"
#include "AbstractScene.h"
#include "Image.h"
#define WIDTH 1280
#define HEIGHT 720

Title title;
Shooter shooter;
Image image;

// int KeyFlg = 0;
int NowKey = 0;
int OldKey = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	SetMainWindowText("�]���r�Q�[��");
	ChangeWindowMode(TRUE);
	SetGraphMode(WIDTH, HEIGHT, 32);
	if (DxLib_Init() == -1)return -1;

	if (image.DrawImage() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager sceneManager(new Title());

	while(ProcessMessage() == 0 && sceneManager.Update() != nullptr && !(shooter.KeyFlg & PAD_INPUT_9)){
		OldKey = NowKey;
		NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		shooter.KeyFlg = NowKey & ~OldKey;

		ClearDrawScreen();

		sceneManager.Draw();

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}