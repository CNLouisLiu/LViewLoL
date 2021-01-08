#pragma once
#include "Vector.h"

/* Took from https://www.millisecond.com/support/docs/v6/html/language/scancodes.htm */
enum HKey {
	NO_KEY = 0, ESC, N_1, N_2, N_3, N_4, N_5, N_6, N_7, N_8, N_9, N_0, MINUS, EQUAL, BS, Tab, Q, W, E, R, T, Y, U, I, O, P, LBRACKET, RBRACKET, ENTER, CTRL, A, S, D, F, G,
	H, J, K, L, SEMICOLON, SINGLE_QUOTE, TILDE, LSHIFT, BACKSLASH, Z, X, C, V, B, N, M, COMMA, DOT, FRONTSLASH, RSHIFT, PRINT_SCREEN, ALT, SPACE,	CAPS, F1, F2,
	F3, F4, F5, F6, F7, F8, F9, F10, NUM, SCROLL, HOME, UP, PAGE_UP, NUM_MINUS, LEFT, CENTER, RIGHT, PLUS, END, DOWN, PAGE_DOWN, INSERT, DEL
};

static const char* HKeyNames[] = {
	"None", "Esc", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Backspace", "Tab", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "Enter", "Ctrl", "A", "S", "D", "F", "G",
	"H", "J", "K", "L", ";", "'", "`", "LShift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "RShift", "PrtScrn", "Alt", "Space", "Caps", "F1", "F2",
	"F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "Num", "Scrl", "Home", "Num8", "PgUp", "NumMinus", "Num4", "Num5", "Num6", "NumPlus", "End", "NumDown", "PgDown", "Insert", "Del"
};

/// Keyboard/Mouse input related utilities. For keyboards the hardware key codes are used instead of the virtual ones.
namespace Input {
	/// Presses the specified hardware key
	void     PressKey(HKey key);

	/// Checks if a key was pressed recently. Only one caller can use this function for a given key.
	bool     WasKeyPressed(HKey key);

	/// Checks if the key is held down.
	bool     IsKeyDown(HKey key);

	/// Gets the cursor position in window coordinates
	Vector2  GetCursorPosition();

	/// Sends a left click input
	void     PressLeftClick();

	/// Sends a right click input
	void     PressRightClick();

	/// Moves the cursor at the specified location, clicks and then moves the cursor back at the initial location
	void     ClickAt(bool leftClick, float x, float y);

	/// Moves the cursor to the specified window coordinates.
	void     MoveCursorTo(float x, float y);
}