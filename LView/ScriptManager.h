#pragma once
#include <string>
#include "Script.h"

/// Manages gameplay scripts executed in Python
class ScriptManager {

public:
	void LoadAll(std::string scriptsLocation, std::string& champion);
	void ReloadScript(std::shared_ptr<Script>& script);
	void SaveAllScriptsConfigs();


	void SaveScriptConfigs(std::shared_ptr<Script>& script);
	void ReloadScriptConfigs(std::shared_ptr<Script>& script);

public:
	std::vector<std::shared_ptr<Script>> activeScripts;
	std::vector<std::shared_ptr<Script>> inactiveScripts;

	std::map<std::string, std::shared_ptr<Script>> allScripts;
};