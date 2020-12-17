#include "ConfigSet.h"
#include <fstream>

ConfigSet* ConfigSet::instance = nullptr;

void ConfigSet::LoadFromFile() {
	std::string line;
	size_t delimiterIdx;

	std::ifstream file("config.ini");
	if (file.is_open()) {
		while (std::getline(file, line)) {
			delimiterIdx = line.find("=");
			if (delimiterIdx == std::string::npos)
				throw std::runtime_error(std::string("Config file line does not contain delimiter `=`: ").append(line));

			rawValues[line.substr(0, delimiterIdx)] = line.substr(delimiterIdx + 1, line.length());
		}

		file.close();
	}
}

void ConfigSet::SetPrefixKey(std::string prefix) {
	prefixKey = prefix;
}

std::string ConfigSet::GetPrefixKey() {
	return prefixKey;
}

void ConfigSet::SaveToFile() {

	std::ofstream file("config.ini");
	if (!file.is_open())
		throw std::runtime_error("Couldn't open file to save config set");

	for (auto it = rawValues.begin(); it != rawValues.end(); ++it) {
		file << it->first << "=" << it->second << "\n";
	}

	file.close();
}

int ConfigSet::GetInt(const char* key, int defaultVal) {
	auto it = rawValues.find(prefixKey + "::" + key);
	if (it == rawValues.end())
		return defaultVal;

	std::string& val = it->second;

	if (val.substr(0, 2).compare("0x") == 0)
		return std::stoi(val, nullptr, 16);
	return std::stoi(val);
}

float ConfigSet::GetFloat(const char* key, float defaultVal) {
	auto it = rawValues.find(prefixKey + "::" + key);
	if (it == rawValues.end())
		return defaultVal;

	std::string& val = it->second;

	return std::stof(val);
}

bool ConfigSet::GetBool(const char* key, bool defaultVal) {
	auto it = rawValues.find(prefixKey + "::" + key);
	if (it == rawValues.end())
		return defaultVal;

	std::string& val = it->second;

	return std::stod(val);
}

std::string ConfigSet::GetStr(const char* key, const char* defaultVal) {
	auto it = rawValues.find(prefixKey + "::" + key);
	if (it == rawValues.end())
		return defaultVal;

	return it->second;
}

void ConfigSet::SetInt(const char* key, int value) {
	rawValues[(prefixKey + "::" + key)] = std::to_string(value);
}

void ConfigSet::SetFloat(const char* key, float value) {
	rawValues[(prefixKey + "::" + key)] = std::to_string(value);
}

void ConfigSet::SetBool(const char* key, bool value) {
	rawValues[(prefixKey + "::" + key)] = std::to_string(value);
}

void ConfigSet::SetStr(const char* key, const char* value) {
	rawValues[(prefixKey + "::" + key)] = value;
}
