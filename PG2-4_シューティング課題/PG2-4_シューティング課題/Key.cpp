#include "DxLib.h"
#include "Key.h"

Key::Key() {
	for (int i = 0; i < 256; i++) {
		Key_OldKey[i] = 0;
		Key_NowKey[i] = 0;
	}

	Pad_OldKey = 0;
	Pad_NowKey = 0;
	Pad_KeyFlg = 0;

}

void Key::Update() {

	char KeyState[256];
	GetHitKeyStateAll(KeyState);
	for (int i = 0; i < 256; i++) {
		if (KeyState[i] != 0) {
			Key_NowKey[i] = 1;
		}
		else {
			Key_NowKey[i] = 0;
		}
	}

	Pad_OldKey = Pad_NowKey;
	Pad_NowKey = GetJoypadInputState(DX_INPUT_PAD1);
}

bool Key::KeyOnClick(int InputKey) {
	bool rex = (Key_NowKey[InputKey] == 1 && Key_OldKey[InputKey] == 0);
	Key_OldKey[InputKey] = Key_NowKey[InputKey];

	return rex;
}

bool Key::KeyPresse(int InputKey) {
	Key_OldKey[InputKey] = Key_NowKey[InputKey];
	bool rex = (Key_NowKey[InputKey] == 1 && Key_OldKey[InputKey] == 1);
	return rex;
}

bool Key::KeyRelese(int InputKey) {
	bool rex = (Key_NowKey[InputKey] == 0 && Key_OldKey[InputKey] == 1);

	return rex;
}

int Key::PadOnClick(int PadFlg) {
	Pad_KeyFlg = Pad_NowKey & ~Pad_OldKey;

	return PadFlg;
}

int Key::PadPresse(int PadFlg) {
	Pad_KeyFlg = Pad_NowKey & Pad_OldKey;

	return PadFlg;
}

int Key::PadRelese(int PadFlg) {
	Pad_KeyFlg = ~Pad_NowKey & Pad_OldKey;

	return PadFlg;
}