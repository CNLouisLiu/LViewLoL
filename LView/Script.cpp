#include "Script.h"
#include <stdio.h>

std::string GetPyError()
{
	PyObject *exc, *val, *tb;
	PyErr_Fetch(&exc, &val, &tb);
	PyErr_NormalizeException(&exc, &val, &tb);

	PyObject* errValStr = PyObject_Str(val);
	PyObject* errExcLineNum = PyObject_Str(PyObject_GetAttrString(tb, "tb_lineno"));
	PyObject* errExcType = PyObject_Str(exc);

	std::string returnVal = "Exception ";
	returnVal.append(extract<std::string>(errExcType));
	returnVal.append(" occured on line: ");
	returnVal.append(extract<std::string>(errExcLineNum));
	returnVal.append("\n");
	returnVal.append(extract<std::string>(errValStr));

	return returnVal;
}

bool Script::LoadFunc(PyObject** loadInto, const char* funcName) {
	PyObject* pyFuncName = PyUnicode_FromString(funcName);
	*loadInto = PyObject_GetAttr(moduleObj, pyFuncName);
	Py_DECREF(pyFuncName);

	return *loadInto != NULL;
}

bool Script::LoadInfo() {
	PyObject* dictName = PyUnicode_FromString("lview_script_info");
	PyObject* dictAttr = PyObject_GetAttr(moduleObj, dictName);
	Py_DECREF(dictName);

	if (dictAttr == NULL) {
		loadError = std::string("No `lview_script_info` dictionary found in script");
		return false;
	}

	dict d;
	try {
		d = dict(handle<>(dictAttr));

		author = extract<std::string>(d.get("author"));
		description = extract<std::string>(d.get("description"));
		name = extract<std::string>(d.get("script"));
	}
	catch (error_already_set) {
		
		loadError = std::string("Script info dictionary contains wrong values types or missing values");
		return false;
	}

	try {
		targetChampion = extract<std::string>(d.get("target_champ"));
	}
	catch (error_already_set) {}
	
	return true;
}

void Script::Load(const char * file)
{ 
	name = std::string(file);
	printf("[+] Loading script %s\n", file);
	
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
		if (LoadInfo() &&
			LoadFunc(&updateFunc, "lview_update") &&
			LoadFunc(&drawSettingsFunc, "lview_draw_settings") &&
			LoadFunc(&loadCfgFunc, "lview_load_cfg") &&
			LoadFunc(&saveCfgFunc, "lview_save_cfg")) {

			loadError.clear();
		}
	}
}

void Script::ExecUpdate(const PyGame & state, const PyImguiInterface & ui)
{
	try {
		if (NULL != updateFunc) {
			high_resolution_clock::time_point beforeUpdate = high_resolution_clock::now();

			call<void>(updateFunc, boost::ref(state), boost::ref(ui));

			updateTimeMs = high_resolution_clock::now() - beforeUpdate;
		}
	}
	catch (error_already_set) {
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

void Script::ExecLoadCfg()
{
	try {
		if (NULL != drawSettingsFunc) {
			call<void>(loadCfgFunc, boost::ref(*ConfigSet::Get()));
		}
	}
	catch (error_already_set) {
		loadError = GetPyError();
	}
}

void Script::ExecSaveCfg()
{
	try {
		if (NULL != drawSettingsFunc) {
			call<void>(saveCfgFunc, boost::ref(*ConfigSet::Get()));
		}
	}
	catch (error_already_set) {
		loadError = GetPyError();
	}
}

Script::~Script()
{
	Py_DECREF(moduleObj);
	Py_DECREF(updateFunc);
	Py_DECREF(drawSettingsFunc);
	Py_DECREF(loadCfgFunc);
	Py_DECREF(saveCfgFunc);
}
