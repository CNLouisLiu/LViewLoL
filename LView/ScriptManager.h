#pragma once
#include <string>
#include "Script.h"

class ScriptManager {

public:
	void LoadAll(std::string scriptsLocation, std::string& champion);
	void ReloadScript(std::shared_ptr<Script>& script);
	void CollectAllScriptConfigs();


	void CollectScriptConfigs(std::shared_ptr<Script>& script);
	void ProvideScriptWithConfigs(std::shared_ptr<Script>& script);

public:
	std::vector<std::shared_ptr<Script>> activeScripts;
	std::vector<std::shared_ptr<Script>> inactiveScripts;

	std::map<std::string, std::shared_ptr<Script>> allScripts;
};