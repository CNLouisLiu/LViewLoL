#include "ConfigSet.h"
#include <fstream>

void ConfigSet::LoadFromFile(std::string filePath) {
	std::string line;
	size_t delimiterIdx;

	std::ifstream file(filePath);
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
	prefixKey = prefix + ".";
}

void ConfigSet::SaveToFile(std::string filePath) {

	std::ofstream file(filePath);
	if (!file.is_open())
		throw std::runtime_error("Couldn't open file to save config set");

	for (auto it = rawValues.begin(); it != rawValues.end(); ++it) {
		file << it->first << "=" << it->second << "\n";
	}

	file.close();
}
