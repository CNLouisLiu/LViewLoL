#include "ScriptManager.h"
#include <filesystem>

void ScriptManager::LoadAll(std::string scriptsLocation, ConfigSet& configs)
{
	try {
		scripts.clear();
		object sys = import("sys");
		sys.attr("path").attr("insert")(0, scriptsLocation.c_str());

		WIN32_FIND_DATAA findData;
		HANDLE hFind;

		hFind = FindFirstFileA((scriptsLocation + "\\*.py").c_str(), &findData);
		do {
			if (hFind != INVALID_HANDLE_VALUE) {
				std::string fileName = findData.cFileName;
				fileName.erase(fileName.find(".py"), 3);

				scripts.push_back(Script());
				scripts.back().Load(fileName.c_str());
				if (scripts.back().loadError.empty())
					LoadScriptConfig(scripts.back(), configs);
			}
		} while (FindNextFileA(hFind, &findData));
	}
	catch (...) {
		PyErr_Print();
	}
}

void ScriptManager::ReloadScript(Script& script, ConfigSet& configs)
{
	script.Load(script.name.c_str());
	if(script.loadError.empty())
		LoadScriptConfig(script, configs);
}

void ScriptManager::SaveScriptConfigs(ConfigSet& configs) {
	for (auto it = scripts.begin(); it != scripts.end(); ++it) {
		SaveScriptConfig(*it, configs);
	}
}

void ScriptManager::SaveScriptConfig(Script & script, ConfigSet & configs)
{
	configs.SetPrefixKey(script.name);
	configs.SetBool("enabled", script.enabled);
	script.ExecSaveCfg(configs);
	configs.SetPrefixKey("");
}

void ScriptManager::LoadScriptConfig(Script & script, ConfigSet & configs)
{
	configs.SetPrefixKey(script.name);
	script.enabled = configs.GetBool("enabled", true);
	script.ExecLoadCfg(configs);
	configs.SetPrefixKey("");
}
