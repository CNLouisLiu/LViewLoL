#pragma once
#include <string>
#include "Script.h"

class ScriptManager {

public:
	void LoadAll(std::string scriptsLocation, ConfigSet& configs);
	void ReloadScript(Script& script, ConfigSet& configs);
	void SaveScriptConfigs(ConfigSet& configs);

private:
	void SaveScriptConfig(Script& script, ConfigSet& configs);
	void LoadScriptConfig(Script& script, ConfigSet& configs);

public:
	std::vector<Script> scripts;
};