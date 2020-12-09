#pragma once

#include <stdexcept>
#include "windows.h"
#include <string>

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
	const char* message = nullptr;
	int errorCode = 0;
};

namespace Mem {

	DWORD_PTR ReadPointer(HANDLE hProcess, DWORD_PTR addr);
	float ReadFloat(HANDLE hProcess, DWORD_PTR addr);
	void Read(HANDLE hProcess, DWORD_PTR addr, void* structure, int size);
};

namespace Process {
	BOOL IsProcessRunning(DWORD pid);
};