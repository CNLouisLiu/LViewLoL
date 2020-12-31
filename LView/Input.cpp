#include "Input.h"
#include "windows.h"
#include <chrono>
#include "Vector.h"

using namespace std::chrono;

void Input::PressKey(HKey key) {
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = key;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;
	input.ki.wVk = 0;
	input.ki.dwFlags = KEYEVENTF_SCANCODE;
	SendInput(1, &input, sizeof(INPUT));

	Sleep(8);
	input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
}

bool Input::WasKeyPressed(HKey key) {

	static high_resolution_clock::time_point nowTime;
	static high_resolution_clock::time_point lastTimePressed[300] = {high_resolution_clock::now()};
	static duration<float, std::milli> timeDiff;

	int virtualKey = MapVirtualKeyA(key, MAPVK_VSC_TO_VK);
	if (virtualKey == 0)
		return false;

	if (!GetAsyncKeyState(virtualKey))
		return false;

	nowTime = high_resolution_clock::now();
	timeDiff = nowTime - lastTimePressed[virtualKey];
	
	if (timeDiff.count() < 200) {
		return false;
	} 
		
	lastTimePressed[virtualKey] = nowTime;
	return true;
}

bool Input::IsKeyDown(HKey key) {
	int virtualKey = MapVirtualKeyA(key, MAPVK_VSC_TO_VK);
	if (virtualKey == 0)
		return false;

	return GetAsyncKeyState(virtualKey);
}

Vector2 Input::GetCursorPosition()
{
	POINT pos;
	GetCursorPos(&pos);
	return { (float)pos.x, (float)pos.y };
}

void Input::PressLeftClick()
{

	INPUT input = {0};
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(INPUT));

	Sleep(8);

	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(INPUT));
}

void Input::PressRightClick()
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &input, sizeof(INPUT));

	Sleep(8);

	input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &input, sizeof(INPUT));
}

void Input::ClickAt(bool leftClick, float x, float y)
{
	static float fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
	static float fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;


	POINT oldPos;
	GetCursorPos(&oldPos);

	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	input.mi.dx = x * (65535.0f / fScreenWidth);
	input.mi.dy = y * (65535.0f / fScreenHeight);
	SendInput(1, &input, sizeof(INPUT));

	input.mi.dwFlags = (leftClick ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_RIGHTDOWN);
	SendInput(1, &input, sizeof(INPUT));

	Sleep(8);

	input.mi.dwFlags = (leftClick ? MOUSEEVENTF_LEFTUP: MOUSEEVENTF_RIGHTUP);
	SendInput(1, &input, sizeof(INPUT));

	input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	input.mi.dx = oldPos.x * (65535.0f / fScreenWidth);
	input.mi.dy = oldPos.y * (65535.0f / fScreenHeight);
	SendInput(1, &input, sizeof(INPUT));

}
