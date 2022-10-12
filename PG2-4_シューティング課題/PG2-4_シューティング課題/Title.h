#pragma once
#include "AbstractScene.h"

class Title :public AbstractScene {
public:
	virtual ~Title() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() override;

public:
	int KeyFlg = 0;
	int NowKey = 0;
	int OldKey = 0;
	int TitleImage;

private:
	int MenuNumber = 0;
};