#pragma once
#include <string>
#include <map>

/* This class is used to store key value pairs for cheat configurations */
class ConfigSet {

public:
	// Only made public for C++ to python bindings. Use ConfigSet::Get()
	ConfigSet() {};

	int            GetInt(const char* key, int defaultVal);
	bool           GetBool(const char* key, bool defaultVal);
	float          GetFloat(const char* key, float defaultVal);
	std::string    GetStr(const char*, const char* defaultVal);
	
	void           SetInt(const char*, int val);
	void           SetBool(const char*, bool val);
	void           SetFloat(const char*, float val);
	void           SetStr(const char*, const char* val);

	void           LoadFromFile();
	void           SaveToFile();

	/* Sets a prefix to the keys provided to Set() Get() functions.
       This is done in order to avoid configuration conflicts between
	   different cheats.
	*/
	void SetPrefixKey(std::string prefixKey);

	std::string GetPrefixKey();

	static ConfigSet* Get() {
		if (instance == nullptr) {
			instance = new ConfigSet();
			instance->LoadFromFile();
		}
		return instance;
	}

private:
	static ConfigSet*                  instance;

	std::string                        prefixKey;
	std::map<std::string, std::string> rawValues;
};
