#include <stdio.h>
#include <string.h>

#include "operations.h"
#include "defaultFunctions.h"

// Don't forget to also ADD the operations in the next table.
#define ADD_OPERATION(NAME)  {#NAME, &NAME}
const operation availableOperations[] =
{
  ADD_OPERATION(add),
  { NULL, NULL }	// End marker.
};
// End of operations table.

int add(int argc, char* argv[])
{
	printf("Add function called.\n");
	return 1;
}

int (*selectOperation(const char* name))(int, char**)
{
	// find the unique operation based on user input. If none ore multiple operations correspond, return NULL.
	int currentIndex = 0;
	int subStrLen = strlen(name);
	int foundIndexCounter = 0;
	int foundIndex = 0;
	for(currentIndex = 0; availableOperations [ currentIndex ].name != NULL; currentIndex++)
	{
		if(subStrCmp(availableOperations [ currentIndex ].name, name, subStrLen))
		{
			foundIndex = currentIndex;
			foundIndexCounter++;
		}
	}
	switch(foundIndexCounter)
	{
	case 0:
		// Noting found. No need to try with more characters.
		errNum = NOT_IMPLEMENTED;
		return NULL;
		break;
	case 1:
		return availableOperations[foundIndex].function;
		break;
	default:
		// Multiple operations found. Set error number and fail.
		errNum = NOT_DETERMINATIVE;
		return NULL;
	}
}

int doOperation(const char* opName, int argc, char* argv[])
{
	int (*funcPtr)(int, char**);

	funcPtr = selectOperation(opName);
	if(!funcPtr)
	{
		return 0;
	}
	return (*funcPtr)(argc, argv);
}
