/**
 * Lunar Knights
 *
 * Sachin Shah
 * February 10, 2020
 *
 * Python API to call C++ methods
 */

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#define Phoenix_No_WPI
#include "ctre/Phoenix.h"
#include "ctre/phoenix/platform/Platform.h"
#include "LK/robot.h"
#include <stdio.h>

static PyObject *lkpy_get_current(PyObject *self, PyObject *args)
{
	int id;
	if (!PyArg_ParseTuple(args, "i", &id))
		return NULL;
	double amps = get_current(id);
	//printf("Amps of %d: %f\n", id, amps);

	return PyFloat_FromDouble(amps);
	//Py_INCREF(Py_None);
	//return Py_None;
}

static PyObject *lkpy_init(PyObject *self, PyObject *args)
{
	init();

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *lkpy_start(PyObject *self, PyObject *args)
{
	start();

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *lkpy_stop(PyObject *self, PyObject *args)
{
	stop();

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *lkpy_teleop(PyObject *self, PyObject *args)
{
	int key;
	double value;

	if (!PyArg_ParseTuple(args, "id", &key, &value))
		return NULL;

	printf("Teleop: %d, %f\n", key, value);

	teleop(key, value);

	Py_INCREF(Py_None);
	return Py_None;
}

static PyMethodDef LKPYMethods[] = {
	{"teleop",  lkpy_teleop, METH_VARARGS, "Execute a teleop command."},
	{"init",  lkpy_init, METH_NOARGS, "Initalize the robot."},
	{"start",  lkpy_start, METH_NOARGS, "Start the robot."},
	{"stop",  lkpy_stop, METH_NOARGS, "Stop the robot."},
	{"get_current", lkpy_get_current, METH_VARARGS, "Get motor current."},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef lkpymodule = {
	PyModuleDef_HEAD_INIT,
	"lkpy",
	NULL,
	-1,
	LKPYMethods
};

PyMODINIT_FUNC PyInit_lkpy(void)
{
    return PyModule_Create(&lkpymodule);
}
