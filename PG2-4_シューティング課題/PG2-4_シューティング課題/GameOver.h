#pragma once
#include "DxLib.h"
#include "AbstractScene.h"

class GameOver:public AbstractScene
{
private:

public:
	GameOver();
	virtual ~GameOver() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() override;
};

