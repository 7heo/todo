#include <stdio.h>
#include <stdlib.h>

#include "operations.h"
#include "defaultFunctions.h"

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		printUsage();
	}
	else
	{
		errNum = SUCCESS;
		char** operationArgs = NULL;
		int opArgsCount = 0; // The compiler would remove this allocation, it's here only as a dumb-proof feature.
		for(opArgsCount = 0; opArgsCount < (argc - 2); opArgsCount++)
		{
			operationArgs = realloc(operationArgs, (opArgsCount + 1) * sizeof(char*));
			operationArgs[opArgsCount] = argv[opArgsCount + 2];
		}
		if(!doOperation(argv[1], opArgsCount, operationArgs))
		{
			printErr(NULL);
			printUsage();
		}
		free(operationArgs);
	}
	return 0;
}
