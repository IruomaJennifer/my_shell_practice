#include "shell.h"

int main(void)
{
	int i = 0;
	
	environ = set_environ();
	_setenv("USERP", "Jenny", 0);
	/*
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	*/
	/*
	_unsetenv("USERP");
	_setenv("USER", "gwenyfar", 1);
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	*/
	return (0);
}
char **set_environ(void)
{
	char **env;
	int i = 0, a = 0;

	while (environ[i])
		i++;
	
	env = malloc(i * sizeof(char *));
	
	i = 0;
	while (environ[i])
	{
		a = _strlen(environ[i]);
		env[i] = malloc(a + 1);
		_strcpy(env[i], environ[i]);
		printf("%s\n", env[i]);
		i++;
	}
	printf("After while loop\n");
	env[i] = NULL;
	return (env);
}
