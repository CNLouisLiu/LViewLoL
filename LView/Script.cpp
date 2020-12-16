#include "Script.h"
#include <stdio.h>

void Script::LoadFunc(PyObject** loadInto, const char* funcName) {
	PyObject* pyFuncName = PyUnicode_FromString(funcName);
	*loadInto = PyObject_GetAttr(moduleObj, pyFuncName);
	if (*loadInto == NULL) {
		printf("   [^] No %s function found\n", funcName);
	}
	Py_DECREF(pyFuncName);
}

void Script::Load(const char * file)
{
	name = std::string(file);
	printf("[+] Loading %s\n", file);
	
	if (NULL != moduleObj)
		moduleObj = PyImport_ReloadModule(moduleObj);
	else
		moduleObj = PyImport_ImportModule(file);

	if (NULL == moduleObj) {
		printf("   [!] Error loading %s\n", file);

		PyObject *ptype, *pvalue, *ptraceback;
		PyErr_Fetch(&ptype, &pvalue, &ptraceback);

		loadError = extract<std::string>(PyObject_Str(pvalue));
	}
	else {
		LoadFunc(&updateFunc, "lview_update");
		LoadFunc(&drawSettingsFunc, "lview_draw_settings");
		LoadFunc(&loadCfgFunc, "lview_load_cfg");
		LoadFunc(&saveCfgFunc, "lview_save_cfg");

		loadError.clear();
	}
}

std::string GetPyError()
{
	PyObject *exc, *val, *tb;
	PyErr_Fetch(&exc, &val, &tb);

	PyObject* errValStr = PyObject_Str(val);
	std::string returnVal = extract<std::string>(errValStr);
	Py_DECREF(errValStr);
	return returnVal;
}

void Script::ExecUpdate(const PyGame & state, const PyImguiInterface & ui)
{
	try {
		if (NULL != updateFunc) {
			call<void>(updateFunc, boost::ref(state), boost::ref(ui));
		}
	}
	catch (error_already_set) {
		//PyErr_Print();
		loadError = GetPyError();
	}
}

void Script::ExecDrawSettings(const PyGame & state, const PyImguiInterface & ui)
{
	try {
		if (NULL != drawSettingsFunc) {
			call<void>(drawSettingsFunc, boost::ref(state), boost::ref(ui));
		}
	}
	catch (error_already_set) {
		loadError = GetPyError();
	}
}

void Script::ExecLoadCfg(const ConfigSet & cfg)
{
	try {
		if (NULL != drawSettingsFunc) {
			call<void>(loadCfgFunc, boost::ref(cfg));
		}
	}
	catch (error_already_set) {
		loadError = GetPyError();
	}
}

void Script::ExecSaveCfg(const ConfigSet & cfg)
{
	try {
		if (NULL != drawSettingsFunc) {
			call<void>(saveCfgFunc, boost::ref(cfg));
		}
	}
	catch (error_already_set) {
		loadError = GetPyError();
	}
}
