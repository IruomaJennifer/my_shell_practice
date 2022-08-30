#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define DELIM " \t"
#define buffsize 1024

char *_getline(int);
int _strlen(char *);
void print(int, char *);
int isDelimiter(char);
char **tokenize(char *);
char *split_string(char *, const char*);
void *_realloc(void *, size_t, size_t);

#endif

