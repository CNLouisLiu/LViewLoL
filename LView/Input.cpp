#include "Input.h"
#include "windows.h"

void Input::PressKey(HKey key) {
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = key;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;
	input.ki.wVk = 0;
	input.ki.dwFlags = KEYEVENTF_SCANCODE;
	SendInput(1, &input, sizeof(INPUT));

	Sleep(13);
	input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
}

bool Input::WasKeyPressed(HKey key) {

	static bool wasPressedLastCall[300];

	int virtualKey = MapVirtualKeyA(key, MAPVK_VSC_TO_VK);
	if (virtualKey == 0)
		return false;

	bool pressed = GetAsyncKeyState(virtualKey);
	bool returnVal = !wasPressedLastCall[virtualKey] && pressed;
	wasPressedLastCall[virtualKey] = pressed;

	return returnVal;
}

bool Input::IsKeyDown(HKey key) {
	int virtualKey = MapVirtualKeyA(key, MAPVK_VSC_TO_VK);
	if (virtualKey == 0)
		return false;

	return GetAsyncKeyState(virtualKey);
}