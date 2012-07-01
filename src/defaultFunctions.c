/***************************************************************************\
 *
 *
 *
\***************************************************************************/

// Including needed standard headers
#include <stdio.h>	// For basic IO operations
#include <stdarg.h>	// For variadic function printErr
#include <string.h>	// For string management (strlen)

// Including needed custom headers
#include "operations.h"			// The header for available operations implementations
#include "defaultFunctions.h"	// The header for this file

/***************************************************************************
 * const string table, to define error messages. Indexes are implicit.
 ***/
const char* ERR_TAB[] =
{
	"Success",
	"This operation is not implemented.",
	"The first argument corresponds to more than one operation.",
};

/***************************************************************************
 * substring comparison function. Returns 1 if substrings are identical,
 * 0 else.
 ***/
int subStrCmp(const char* strA, const char* strB, int subStrLen)
{
	int minLen = MIN(strlen(strA), strlen(strB));
	int c = 0; // Do not remove the = 0, dumb proof feature. c is for counter.
	// If provided subString length is greater than any of the string's length,
	// abort the comparison and return false.
	if(subStrLen > minLen)
	{
		return 0;
	}
	// increments c up to the subString length as long as characters match.
	for(c = 0; c < subStrLen && strA[c] == strB[c]; c++)
	{
		;
	}
	// if c equals subString length, then they are identical.
	if(c == subStrLen)
	{
		return 1;
	}
	// else they're not.
	return 0;
}

/***************************************************************************
 * Error printing function. Prints default message (based on internal errNum
 * value when called without arguments.
 ***/
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

/***************************************************************************
 * Defines the list of available operations as an extern datagram.
 ***/
extern operation availableOperations[];

/***************************************************************************
 * prints default usage.
 ***/
void printUsage(void)
{
	int i = 0;
	printErr("Usage : todo <operation> [arguments]\n");
	printErr("Available operations:\n");
	for(i = 0; availableOperations[i].name != NULL; i++)
		printErr("\t%s\n", availableOperations[i].name);
}

/***************************************************************************
 * This function loads the configuration from an XML file and store it into
 * a structure in RAM.
 ***/
int loadConfig(configStruct* cfg)
{
	return 0;
}
