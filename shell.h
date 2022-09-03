#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define DELIM " \t"
#define buffsize 1024

extern char **environ;
typedef struct list{
	char *dir;
	struct list *next;
}list_dir;

char *_strcpy(char *, char *);
char **set_environ(void);
int _unsetenv(const char *);
int overwrite_function(int, int, const char *, int *);
int environ_cmp(const char *, int *, int *);
int _setenv(const char *, const char *, int);
int lengthAfterEqual(char *, int);
list_dir *link_dir(char **);
char **tokenize_path(char *);
int lengthTillEqual(char *);
char *_getenv(const char *);
void execute(char **);
char *_getline(int);
int _strlen(char *);
int _strlen2(const char *);
void print(int, char *);
int isDelimiter(char);
char **_tokenize(char *);
char **tokenize(char *);
char *split_string(char *, const char*);
void *_realloc(void *, size_t, size_t);

#endif

