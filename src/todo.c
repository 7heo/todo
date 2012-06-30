#include <stdio.h>
#include <stdlib.h>

#include "operations.h"
#include "defaultFunctions.h"

// a global structure to store config fetched by the loadConfig function.
configStruct *globalConfig;

// This is the main function; aka the program entry.
int main(int argc, char* argv[])
{
	// Local error code is initialized at program start; meant to store the error Num if an error has happened.
	int errorCode = 0;
	// check on the arguments list size.
	if(argc == 1)
	{
		printUsage();
	}
	else
	{
		// we init errNum (global) to success to avoid false positives on error detection.
		errNum = SUCCESS;
		// we init the operations Arguments table. It's the argv table without the first two values (which are the program's name and the operation to perform)
		char** operationArgs = NULL;
		// Here we copy argv[2:] to operationArgs.
		int opArgsCount = 0; // The compiler would remove this allocation, it's here only as a dumb-proof feature.
		for(opArgsCount = 0; opArgsCount < (argc - 2); opArgsCount++)
		{
			operationArgs = realloc(operationArgs, (opArgsCount + 1) * sizeof(char*));
			operationArgs[opArgsCount] = argv[opArgsCount + 2];
		}
		// Once it's done, we load the config and then execute the operations with the correct arguments for it.
		if( !(loadConfig(globalConfig) && doOperation(argv[1], opArgsCount, operationArgs)) )
		{
			// if something wrong happened, we grab the error number and print the corresponding error.
			errorCode = errNum;
			printErr(NULL);
		}
		// we free the data we used.
		free(operationArgs);
		free(globalConfig);
	}
	// we return the error code.
	return errorCode;
}
