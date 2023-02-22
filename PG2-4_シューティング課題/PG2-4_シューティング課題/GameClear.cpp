#include "GameClear.h"
#include "Title.h"

extern Key key;

GameClear::GameClear() 
{

}

AbstractScene* GameClear::Update()
{
	if (key.KeyOnClick(KEY_INPUT_SPACE) || key.Pad_KeyFlg & key.PadOnClick(PAD_INPUT_A)) {
		return new Title;
	}
	return this;
}

void GameClear::Draw()
{
	DrawString(500, 200, "GameClear!!", 0xffffff);

	DrawString(500, 500, "PushSpace!!", 0xffffff);
}