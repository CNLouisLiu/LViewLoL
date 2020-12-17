#pragma once
#include <string>
#include "Script.h"

class ScriptManager {

public:
	void LoadAll(std::string scriptsLocation, ConfigSet& configs);
	void ReloadScript(Script& script, ConfigSet& configs);
	void CollectAllScriptConfigs(ConfigSet& configs);


	void CollectScriptConfigs(Script& script, ConfigSet& configs);
	void ProvideScriptWithConfigs(Script& script, ConfigSet& configs);

public:
	std::vector<Script> scripts;
};