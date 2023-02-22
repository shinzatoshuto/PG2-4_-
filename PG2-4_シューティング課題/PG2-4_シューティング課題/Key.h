#pragma once

class Key {
	static int Key_OldKey[256];
	static int Key_NowKey[256];
	static int Pad_OldKey;

public:
	static int Pad_KeyFlg;
	static int Pad_NowKey;

public:
	Key();
	static void Update();
	static bool KeyOnClick(int InputKey);
	static bool KeyPresse(int InputKey);
	static bool KeyRelese(int InputKey);
	static int PadOnClick(int PadFlg);
	static int PadPresse(int PadFlg);
	static int PadRelese(int PadFlg);
};