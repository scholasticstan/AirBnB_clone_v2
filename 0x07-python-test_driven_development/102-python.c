#include <Python.h>
#include <stdio.h>

void print_python_string(PyObject *p)
{
    if (!PyUnicode_Check(p))
    {
        fprintf(stderr, "Error: p is not a valid string\n");
        return;
    }

    Py_ssize_t size = PyUnicode_GET_SIZE(p);
    const char *data = PyUnicode_DATA(p);

    printf("'%.*s'\n", (int)size, data);
}

