#include "ScriptManager.h"
#include <filesystem>

void ScriptManager::LoadAll(std::string scriptsLocation)
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
					ProvideScriptWithConfigs(scripts.back());
			}
		} while (FindNextFileA(hFind, &findData));
	}
	catch (...) {
		PyErr_Print();
	}
}

void ScriptManager::ReloadScript(Script& script)
{
	script.Load(script.name.c_str());
	if(script.loadError.empty())
		ProvideScriptWithConfigs(script);
}

void ScriptManager::CollectAllScriptConfigs() {
	for (auto it = scripts.begin(); it != scripts.end(); ++it) {
		CollectScriptConfigs(*it);
	}
}

void ScriptManager::CollectScriptConfigs(Script & script)
{
	ConfigSet& configs = *(ConfigSet::Get());

	configs.SetPrefixKey(script.name);
	configs.SetBool("enabled", script.enabled);
	script.ExecSaveCfg();
	configs.SetPrefixKey("");
}

void ScriptManager::ProvideScriptWithConfigs(Script & script)
{
	ConfigSet& configs = *(ConfigSet::Get());

	configs.SetPrefixKey(script.name);
	script.enabled = configs.GetBool("enabled", true);
	script.ExecLoadCfg();
	configs.SetPrefixKey("");
}
