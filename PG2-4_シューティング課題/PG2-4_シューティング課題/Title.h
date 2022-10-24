#pragma once
#include "AbstractScene.h"

class Title :public AbstractScene {
public:
	Title* ti;
	virtual ~Title() {
		delete ti;
	};
	virtual AbstractScene* Update() override;
	virtual void Draw() override;

public:

private:
	int MenuNumber = 0;
};