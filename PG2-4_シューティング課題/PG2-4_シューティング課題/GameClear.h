#pragma once
#include "DxLib.h"
#include "AbstractScene.h"
#include "Key.h"

class GameClear :public AbstractScene
{
private:

public:
	GameClear();
	virtual ~GameClear() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() override;
};

