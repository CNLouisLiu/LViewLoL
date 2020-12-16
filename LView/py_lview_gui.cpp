#include "py_lview_gui.h"

PyObject* gui_button(PyObject* self, PyObject* args) {
	PyObject* btnTxt;
	PyArg_UnpackTuple(args, "", 1, 1, &btnTxt);

	const char* txt = PyUnicode_AsUTF8(btnTxt);
	return PyBool_FromLong(ImGui::Button(txt));
}

PyObject* gui_checkbox(PyObject* self, PyObject* args) {
	
	PyObject* txt;
	PyObject* ticked;

	PyArg_UnpackTuple(args, "", 1, 2, &txt, &ticked);

	bool isTicked = ticked == Py_True;
	ImGui::Checkbox(PyUnicode_AsUTF8(txt), &isTicked);

	return PyBool_FromLong(isTicked);
}