#include "shell.h"

/**
 * add_environvar - adds a variable to the environment
 * @len_name: the length of the name string
 * @valp_len: the length of the value
 * @name: name of variable
 * @value: value of variable
 * Return: 0 always
 */
int add_environvar(int len_name, int valp_len, const char *name,
		const char *value)
{
	int i = 0, env_len = 0, a = 0, oldsize, newsize;

	while (environ[i])
	{
		env_len++;
		i++;
	}
	oldsize = (env_len + 1) * sizeof(char *);
	newsize = (env_len + 2) * sizeof(char *);
	environ = _realloc(environ, oldsize, newsize);
	if (environ == NULL)
		return (-1);
	environ[env_len] = malloc(len_name + valp_len + 2);
	if (environ[env_len] == NULL)
		return (-1);
	i = 0;
	while (i < len_name)
	{
		environ[env_len][i] = name[i];
		i++;
	}
	environ[env_len][i] = '=';
	i++;
	while (a < valp_len)
	{
		environ[env_len][i] = value[a];
		a++;
		i++;
	}
	environ[env_len][i] = '\0';
	environ[env_len + 1] = NULL;
	return (0);
}
