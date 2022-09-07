#include "shell.h"

/**
 * _printenv - prints the current environment to the terminal
 * @cmd: an unused variable
 *
 * Return: void
 */
void _printenv(char **cmd)
{
	unsigned int i;
	(void)cmd;

	i = 0;
	while (environ[i] != NULL)
	{
		print(STDOUT_FILENO, environ[i]);
		print(STDOUT_FILENO, "\n");
		i++;
	}
}
/**
 * end - sets the exit status of the shell and exits the shell program
 * @cmd: an array of strings that gives the exit status entered by a user
 *
 * Return: void
 */
void end(char **cmd)
{
	int len = 0;

	while (cmd[len])
		len++;
	if (len > 2)
	{
		print(STDOUT_FILENO, "./hsh : wrong no of parameters");
		print(STDOUT_FILENO, "\n");
		return;
	}
	if (len < 2)
	{
		exit_status = 0;
		return;
	}
	if (_atoi(cmd[1]))
	{
		exit_status = _atoi(cmd[1]);
		return;
	}
}
/**
 * _setenv - sets the value of any environment variable
 * @name: name of variable to set
 * @value: the value to set it to
 * @overwrite: value to tell whether to overwrite existing value
 * Description: the fuction will either overwrite an existing one or
 * create a new variable if it doesn't exist
 * Return: 0 on success and -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int len_name, i = 0, k = 0, val_len = 0, valp_len = 0;
	int oldsize, newsize, a = 0, env_len = 0;

	if (name == NULL || value == NULL)
		return (-1);
	len_name = _strlen2(name);
	valp_len = _strlen2(value);
	isname = environvar_cmp(name, &i, &k);
	if (isname)
	{
		a = overwrite_function(overwrite, k, value, &i);
		return (a);
	}
	else
	{
		i = 0;
		while (_environ[i])
		{
			env_len++;
			i++;
		}
		oldsize = (env_len + 1) * sizeof(char *);
		newsize = (env_len + 2) * sizeof(char *);
		_environ = _realloc(_environ, oldsize, newsize);
		if (_environ == NULL)
			return (-1);
		_environ[env_len] = malloc(len_name + valp_len + 2);
		if (_environ[env_len] == NULL)
			return (-1);
		i = 0;
		while (i < len_name)
		{
			_environ[env_len][i] = name[i];
			i++;
		}
		_environ[env_len][i] = '=';
		i++;
		while (a < valp_len)
		{
			_environ[env_len][i] = value[a];
			a++;
			i++;
		}
		_environ[env_len][i] = '\0';
		_environ[env_len + 1] = NULL;
		return (0);
	}
}

/**
 * _unsetenv - removes a variable from the environment variables
 * @name: variable name
 *
 * Return: 0 on success and -1 on failure
 */
int _unsetenv(const char *name)
{
	int i = 0, position = 0, j = 0, k = 0, isname;
	char **tmp;

	if (!name)
		return (-1);
	isname = environvar_cmp(name, &i, &k);
	while (_environ[position])
		position++;
	if (isname)
	{
		tmp = malloc(position * sizeof(char *));
		if (tmp == NULL)
			return (-1);
		for (position = 0; _environ[position]; position++, j++)
		{
			if (position == i)
			{
				free(_environ[i]);
				j--;
				continue;
			}
			tmp[j] == malloc(_strlen(_environ[position]) + 1);
			_strcpy(tmp[j], _environ[position]);
			free(_environ[position]);
		}
		tmp[j] = NULL;
		_environ = tmp;
		return (0);
	}
	else
		return (0);
}
