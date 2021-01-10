#pragma once

#include <string>
#include <stdexcept>
#include "windows.h"
#include "imgui.h"

#include "Input.h"
#include "Vector.h"

#define Clamp(val, lo, hi) (val < lo) ? lo : (hi < val) ? hi : val

class WinApiException : public std::runtime_error {

public:
	WinApiException(const char* message)
		:std::runtime_error(message){

		errorCode = GetLastError();
		this->message = message;
	}

	std::string GetErrorMessage() {
		std::string msg = std::string(message);

		if (errorCode > 0) {
			char winapiError[255];
			FormatMessageA(
				FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL,
				errorCode,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				winapiError,
				(sizeof(winapiError) / sizeof(wchar_t)),
				NULL);

			msg.append("(");
			msg.append(winapiError);
			msg.append(")");
		}

		return msg;
	}

private:
	const char*    message = nullptr;
	int            errorCode = 0;
};

/// Utilities used for realing process memory
namespace Mem {

	/// Reads a DWORD at the specified memory location
	DWORD          ReadDWORD(HANDLE hProcess, DWORD addr);

	/// Reads an arbitrary struct at the specified memory location
	void           Read(HANDLE hProcess, DWORD addr, void* structure, int size);

	/// Reads a DWORD at the specified location in a given buffer
	DWORD          ReadDWORDFromBuffer(void* buff, int position);
};

/// WINAPI process utilities
namespace Process {
	BOOL           IsProcessRunning(DWORD pid);
};

/// League related algorithms
namespace League {
	float          EffectiveHP(float health, float armour);
	float          EffectiveDamage(float damage, float armour);
}

/// String related algorithms
namespace Character {
	bool        ContainsOnlyASCII(const char* buff, int maxSize);
	std::string ToLower(std::string str);
	std::string RandomString(const int len);
	std::string Format(const char* c, const char* args...);
}

/// Some basic colors
namespace Colors {
	static const ImVec4 BLACK       = ImVec4(0.06f, 0.06f, 0.06f, 1.f);
	static const ImVec4 WHITE       = ImVec4(1.f,   1.f,   1.f,   1.f);
	static const ImVec4 RED         = ImVec4(1.f,   0.f,   0.f,   1.f);
	static const ImVec4 DARK_RED    = ImVec4(0.6f,  0.f,   0.f,   1.f);
	static const ImVec4 GREEN       = ImVec4(0.f,   1.f,   0.f,   1.f);
	static const ImVec4 DARK_GREEN  = ImVec4(0.f,   0.6f,  0.f,   1.f);
	static const ImVec4 YELLOW      = ImVec4(1.f,   1.f,   0.f,   1.f);
	static const ImVec4 DARK_YELLOW = ImVec4(0.6f,  0.6f,  0.f,   1.f);
	static const ImVec4 CYAN        = ImVec4(0.f,   1.f,   1.f,   1.f);
	static const ImVec4 PURPLE      = ImVec4(1.f,   0.f,   1.f,   1.f);
	static const ImVec4 GRAY        = ImVec4(0.5f,  0.5f,  0.5f,  1.f);
	static const ImVec4 ORANGE      = ImVec4(1.f,   0.54f, 0.f,   1.f);
	static const ImVec4 BLUE        = ImVec4(0.f,   0.f,   1.f,   1.f);
	static const ImVec4 BROWN       = ImVec4(0.54f, 0.27f, 0.06f, 1.f);
}