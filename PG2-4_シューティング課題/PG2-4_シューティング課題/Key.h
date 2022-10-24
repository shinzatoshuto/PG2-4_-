#pragma once

class Key {
	int Key_OldKey[256];
	int Key_NowKey[256];
	int Pad_OldKey;

public:
	int Pad_KeyFlg;
	int Pad_NowKey;

public:
	Key();
	void Update();
	bool KeyOnClick(int InputKey);
	bool KeyPresse(int InputKey);
	bool KeyRelese(int InputKey);
	int PadOnClick(int PadFlg);
	int PadPresse(int PadFlg);
	int PadRelese(int PadFlg);
};