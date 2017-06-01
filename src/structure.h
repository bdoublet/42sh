#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct VarEnv
{
	double version;
	int ast_printer;
	int norc;
};

void FreeMal(void* ptr1, void* ptr2, void* ptr3);
void ShLoop(void);
char* ReadLine(void);