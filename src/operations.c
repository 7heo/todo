#include <stdio.h>
#include "operations.h"

#define ADD_OPERATION(NAME)  { #NAME, &NAME}

int add(int argc, char* argv[])
{
	return 1;
}

typedef struct op
{
  char *name;
  int (*function)(int, char**);
} operation;

operation availableOperations[] =
{
  ADD_OPERATION(add),
};

int (*selectOperation(const char* name))(int, char**)
{
	if(!strcmp(name, "add"))
		return &add;
	return NULL;
}

int doOperation(const char* opName, int argc, char* argv[])
{
	int (*funcPtr)(int, char**);

	funcPtr = selectOperation(opName);
	if(!funcPtr)
	{
		printErr("Error: Operation %s isn't implemented.\n", opName);
		return 0;
	}
	return (*funcPtr)(argc, argv);
}
