#pragma once
#include <string>
#include "Script.h"

class ScriptManager {

public:
	void LoadAll(std::string scriptsLocation);
	void ReloadScript(Script& script);
	void CollectAllScriptConfigs();


	void CollectScriptConfigs(Script& script);
	void ProvideScriptWithConfigs(Script& script);

public:
	std::vector<Script> scripts;
};