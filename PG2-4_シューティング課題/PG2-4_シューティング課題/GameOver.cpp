#include "GameOver.h"
#include "Title.h"
#include "Key.h"

extern Key key;

GameOver::GameOver()
{

}

AbstractScene* GameOver::Update()
{
	if (key.KeyOnClick(KEY_INPUT_SPACE) || key.Pad_KeyFlg & key.PadOnClick(PAD_INPUT_A)) {
		return new Title;
	}
	return this;
}

void GameOver::Draw()
{
	DrawString(500, 200, "GameOver", 0xffffff);

	DrawString(500, 500, "PushSpace!!", 0xffffff);
}