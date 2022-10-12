#include "DxLib.h"
#include "Image.h"

int Image::DrawImage() {
	if ((TitleImage = LoadGraph("Image/TestTitle.png")) == -1)return -1;

	return 0;
}