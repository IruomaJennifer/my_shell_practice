#include "shell.h"

int main(void)
{
	int i = 0;
	
	_environ = set_environ();
	_setenv("USERP", "Jenny", 1);
	
	while (_environ[i])
	{
		printf("%s\n", _environ[i]);
		i++;
	}
	
	i = 0;
	_unsetenv("USERP");
	//_setenv("USER", "gwenyfar", 1);
	while (_environ[i])
	{
		printf("%s\n", _environ[i]);
		i++;
	}
	
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
		i++;
	}
	env[i] = NULL;
	return (env);
}
