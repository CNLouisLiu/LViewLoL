#pragma once
#include <string>
#include <map>

/* This class is used to store key value pairs for cheat configurations */
class ConfigSet {

public:
	template <class T>
	T    Get(std::string key, T defaultVal);
	
	template <class T>
	void Set(std::string key, T value);

	void LoadFromFile(std::string filePath);
	void SaveToFile(std::string filePath);

	/* Sets a prefix to the keys provided to Set() Get() functions.
       This is done in order to avoid configuration conflicts between
	   different cheats.
	*/
	void SetPrefixKey(std::string prefixKey);

private:
	std::string                        prefixKey;
	std::map<std::string, std::string> rawValues;
};

template <class T>
T ConfigSet::Get(std::string key, T defaultVal) {
	auto it = rawValues.find(prefixKey + key);
	if (it == rawValues.end())
		return defaultVal;

	std::string& val = it->second;
	if (std::is_same<T, int>::value)
		return std::stoi(val);
	else if (std::is_same<T, float>::value)
		return std::stof(val);
	else if (std::is_same<T, bool>::value) {
		return std::stod(val);
	}
	
	throw new std::runtime_error("Unsupported config value type");
}

template <class T>
void ConfigSet::Set(std::string key, T value) {
	rawValues[(prefixKey + key)] = std::to_string(value);
}