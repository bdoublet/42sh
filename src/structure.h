#ifndef STRUCTURE_H
#define STRUCTURE_H
	#define _GNU_SOURCE
	#define SH_VERSION 0.5
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>
    #include <sys/stat.h>
    #include <pwd.h>
#endif

struct VarEnv
{
	int ast_printer;
	int norc;
};

void FreeMal(void* ptr1, void* ptr2, void* ptr3);
void ShLoop(void);
char* ReadLine(void);
char** lexeur(char* command);