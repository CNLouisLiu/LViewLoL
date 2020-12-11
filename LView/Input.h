#pragma once

/* Took from https://www.millisecond.com/support/docs/v6/html/language/scancodes.htm */
enum HKey {
	NO_KEY = 0, ESC, _1, _2, _3, _4, _5, _6, _7, _8, _9, _0, MINUS, EQUAL, BS, Tab, Q, W, E, R, T, Y, U, I, O, P, LBRACKET, RBRACKET, ENTER, CTRL, A, S, D, F, G,
	H, J, K, L, SEMICOLON, SINGLE_QUOTE, TILDE, LSHIFT, BACKSPACE, Z, X, C, V, B, N, M, COMMA, DOT, FORWARDSPACE, RSHIFT, PRINT_SCREEN, ALT, SPACE,	CAPS, F1, F2,
	F3, F4, F5, F6, F7, F8, F9, F10, NUM, SCROLL, HOME, UP, PAGE_UP, NUM_MINUS, LEFT, CENTER, RIGHT, PLUS, END, DOWN, PAGE_DOWN, INSERT, DEL
};

namespace Input {
	void PressKey(HKey key);
	bool WasKeyPressed(HKey key);
	bool IsKeyDown(HKey key);
}