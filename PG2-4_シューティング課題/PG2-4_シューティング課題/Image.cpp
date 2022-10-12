#include "DxLib.h"
#include "Image.h"
#include "Title.h"

extern Title title;

int Image::LoadImage() {
	if ((title.TitleImage = LoadGraph("Image/TestTitle.png")) == -1)return -1;

	return 0;
}