#pragma once
#include "PyGame.h"
#include "PyImguiInterface.h"
#include "Python.h"
#include "ConfigSet.h"

class Script {

public:
	void Load(const char* file);
	void ExecUpdate(const PyGame& state, const PyImguiInterface& ui);
	void ExecDrawSettings(const PyGame& state, const PyImguiInterface& ui);
	void ExecLoadCfg(const ConfigSet& cfg);
	void ExecSaveCfg(const ConfigSet& cfg);

private:
	void LoadFunc(PyObject** loadInto, const char* funcName);
	void LoadInfo();

public:
	std::string description;
	std::string author;
	std::string name;

	std::string loadError;
	std::string execError; 

	bool enabled;

private:
	PyObject* moduleObj;
	PyObject* updateFunc;
	PyObject* drawSettingsFunc;
	PyObject* loadCfgFunc;
	PyObject* saveCfgFunc;
};