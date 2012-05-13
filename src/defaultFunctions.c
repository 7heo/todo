#include <stdio.h>
#include <stdarg.h>

void printErr(const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
}

void printUsage(void)
{
	printErr("Usage : not computed yet. Sorry.\n");
}
