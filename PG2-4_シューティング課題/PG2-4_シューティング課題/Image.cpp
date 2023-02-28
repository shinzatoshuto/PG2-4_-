#include "DxLib.h"
#include "Image.h"

int Image::TitleImage;
int Image::PlayerImg;
int Image::EnemyImg1;
int Image::EnemyImg2;
int Image::BulletsImg[3];

int Image::DrawImage() {
	if ((TitleImage = LoadGraph("Image/TestTitle.png")) == -1)return -1;
	if ((PlayerImg = LoadGraph("Image/êÌì¨ã@.png")) == -1)return -1;
	//if ((EnemyImg1 = LoadGraph("Image/Enemy1.png")) == -1)return -1;
	//if ((EnemyImg2 = LoadGraph("Image/Enemy2.png")) == -1)return -1;
	if (LoadDivGraph("Image/bullets.png", 3, 3, 1, 16, 16, BulletsImg) == -1)return -1;

	return 0;
}