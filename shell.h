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
extern char **_environ;
char *path_cmd;
int exit_status;
int shell_calls;

typedef struct built_ins{
	char *name;
	void (*handler)(char **cmd);
}builtin;

/*Command types*/
#define BUILTIN 1
#define PATH 2
#define NORMAL 3
#define INVALID 4

/*shell utilities*/
char *_itoa(int i);
int getpower_ten(int);
int _atoi(char *);
int isDelimiter(char);
void print(int, char *);

/*shell builtins*/
/*correct _environ here*/
void _printenv(char **);
void end(char **);
int _setenv(const char *, const char *, int);
int _unsetenv(const char *);

/*shell execution*/
int non_interactive(void);
int shell_execute(char **);
void execute(char *, char **);
char *get_pathcmd(char *cmd);
int cmdtype_check(char *);

/*shell environment*/
char **set_environ(void);
int overwrite_function(int, int, const char *, int *);
int environvar_cmp(const char *, int *, int *);
char *_getenv(const char *);
int add_environvar(int, int, const char *, const char *);
int lengthAfterEqual(char *, int);
int lengthTillEqual(char *);

/*list_dir *link_dir(char **);*/
/*string functions*/
int _strlen(char *);
int _strcmp(char *,char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
int _strlen2(const char *);

/*shell tokenizers*/
char *_getline(int);
char **tokenize_bydelim(char *, char);
char **tokenize_bydelim_end(char **, int, int);
char **tokenize(char *);
char *split_string(char *);

/*shell memory */
void *_realloc(void *, size_t, size_t);
	
#endif

