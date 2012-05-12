#include <stdio.h>
#include "operations.h"

#define declareAsOperation(name) int name(int argc, char* argv[])

declareAsOperation(add)
{
	printf("Add function called.\n");
	return 0;
}

const char* availableOperations[] = {"add","remove","delete"};

int (*selectOperation(const char* name))(int, char**)
{
	int res;
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
