#ifndef __DEFAULT_FUNCTIONS_H__
#define __DEFAULT_FUNCTIONS_H__
typedef enum {SUCCESS, NOT_IMPLEMENTED, NOT_DETERMINATIVE} ERROR_NUM;

#define MIN(a,b) ((a) < (b) ? (a) : (b))
int  subStrCmp(const char*, const char*, int);
ERROR_NUM errNum;
void printUsage(void);
void printErr(const char*, ...);
#endif
