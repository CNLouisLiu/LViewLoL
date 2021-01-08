#pragma once
#include "PyGame.h"
#include "PyImguiInterface.h"
#include "Python.h"
#include "ConfigSet.h"
#include <chrono>

using namespace std::chrono;

/// Represents a python gameplay script
class Script {

public:
	void Load(const char* file);
	void ExecUpdate(const PyGame& state, const PyImguiInterface& ui);
	void ExecDrawSettings(const PyGame& state, const PyImguiInterface& ui);
	void ExecLoadCfg();
	void ExecSaveCfg();

	~Script();

private:
	bool LoadFunc(PyObject** loadInto, const char* funcName);
	bool LoadInfo();

public:
	std::string                  description;
	std::string                  author;
	std::string                  name;
	std::string                  targetChampion;

	std::string                  loadError;
	std::string                  execError; 

	duration<float, std::milli>  updateTimeMs;

	bool                         enabled;

private:
	PyObject* moduleObj;
	PyObject* updateFunc;
	PyObject* drawSettingsFunc;
	PyObject* loadCfgFunc;
	PyObject* saveCfgFunc;
};