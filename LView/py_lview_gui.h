#pragma once
#include "Python.h"
#include "imgui.h"

extern PyObject* gui_button(PyObject* self, PyObject* args);
extern PyObject* gui_checkbox(PyObject* self, PyObject* args);

static struct PyMethodDef methodDefinitions[] = {
	{ "button", gui_button, METH_VARARGS, "Draws a button" },
	{ "checkbox", gui_checkbox, METH_VARARGS, "Draws a checkbox" },
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef moduleDefinition {
	PyModuleDef_HEAD_INIT, "lviewgui", NULL, -1, methodDefinitions,
	NULL, NULL, NULL, NULL
};

static PyObject* InitializePyLView() {
	return PyModule_Create(&moduleDefinition);
}