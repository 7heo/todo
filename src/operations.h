#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__
typedef struct op
{
  char *name;
  int (*function)(int, char**);
} operation;
// Start of operations prototypes.
int add(int, char**);
// End of operations prototypes.
int (*selectOperation(const char*))(int, char**);
int doOperation(const char*, int, char**);
#endif
