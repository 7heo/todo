#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__
typedef struct op
{
  char *name;
  int (*function)(int, char**);
} operation;


int add(int, char**);
int (*selectOperation(const char*))(int, char**);
int doOperation(const char*, int, char**);
#endif
