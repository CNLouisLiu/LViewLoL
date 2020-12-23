#include "AntiCrack.h"
#include "Windows.h"
#include <array>
#include <unordered_map>
#include <sstream>

std::string exec(const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}

std::string HashHardwareComponents(std::string components) { 
	std::stringstream in(components);
	std::stringstream out;
	std::string buff;
	std::hash<std::string> hasher;

	while (std::getline(in, buff, '\n')) {
		size_t hash = hasher(buff);
		out << std::hex << hash;
	}

	return out.str();
}

std::string AntiCrack::GetHardwareID() {

	std::string hwComponents = exec(
		"wmic PATH Win32_VideoController GET PNPDeviceID    | more +1  | findstr /R \"[^\\n]\" &"
		"wmic PATH Win32_PhysicalMemory GET SerialNumber    | more +1  | findstr /R \"[^\\n]\" &"
		"wmic PATH Win32_LogicalDisk GET VolumeSerialNumber | more +1  | findstr /R \"[^\\n]\" &" 
		"wmic PATH Win32_Processor GET ProcessorId          | more +1  | findstr /R \"[^\\n]\" &"
		"wmic PATH win32_computersystem GET name            | more +1  | findstr /R \"[^\\n]\"");
	

	return HashHardwareComponents(hwComponents);
}