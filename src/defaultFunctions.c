#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "operations.h"
#include "defaultFunctions.h"

const char* ERR_TAB[] =
{
	"Success",
	"This operation is not implemented.",
	"The first argument corresponds to more than one operation.",
};

int subStrCmp(const char* strA, const char* strB, int subStrLen)
{
	int minLen = MIN(strlen(strA), strlen(strB));
	int c = 0; // Do not remove the = 0, dumb proof feature. c is for counter.
	if(subStrLen > minLen)
	{
		return 0;
	}
	for(c = 0; c < subStrLen && strA[c] == strB[c]; c++)
	{
		// do nothing, the check is done in the for condition.
	}
	if(c == subStrLen)
	{
		return 1;
	}
	return 0;	// different.
}

void printErr(const char* fmt, ...)
{
	if(fmt == NULL)
	{
		fprintf(stderr, "Error: %s\n", ERR_TAB[errNum]);
	}
	else
	{
		va_list ap;
		va_start(ap, fmt);
		vfprintf(stderr, fmt, ap);
		va_end(ap);
	}
}

extern operation availableOperations[];

void printUsage(void)
{
	int i = 0;
	printErr("Usage : todo <operation> [arguments]\n");
	printErr("Available operations:\n");
	for(i = 0; availableOperations[i].name != NULL; i++)
		printErr("\t%s\n", availableOperations[i].name);
}
