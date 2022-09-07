#include "shell.h"

/**
 * set_environ - function to make environ point to a different
 * memory location
 * Return: a pointer to the new environment variables
 */
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

/**
 * overwrite_function - can overwrite any environment variable
 * @overwrite: tells whether variable should be overwritten
 * @k: position of last character in environment variable name
 * @i: position of the environment variable
 * @value: name of the environment variable
 * Return: 0 on success and -1 on failure
 */
/*int overwrite_function(int overwrite, int k, const char *value, int *i)
{
	int val_len, valp_len, oldsize, newsize, a = 0;

	if (overwrite)
	{
		k++;
		val_len = lengthAfterEqual(_environ[*i], k);
		valp_len = _strlen2(value);

		if (val_len != valp_len)
		{
			oldsize = k + val_len;
			newsize = k + valp_len;
			_environ[*i] = _realloc(_environ[*i], oldsize, newsize);
			if (_environ[*i] == NULL)
				return (-1);
		}
		while (value[a])
		{
			_environ[*i][k] = value[a];
			a++;
			k++;
		}
		_environ[*i][k] = '\0';
		return (0);
	}
	else
		return (0);
}*/

/**
 * environvar_cmp - checks if a variable exists in the current environment
 * @name: name of variable
 * @i: position of an environment variable
 * @k: position a character in a variable name
 * Return: 0 if variable does not exist and 1 if it does
 */
/*int environvar_cmp(const char *name, int *i, int *k)
{
	int isname = 0, len_name = _strlen2(name);

	while (environ[*i])
	{
		if (lengthTillEqual(environ[*i]) == len_name)
		{
			for (*k = 0; *k < len_name; (*k)++)
			{
				if (environ[*i][*k] != name[*k])
				{
					isname = 0;
					break;
				}
				else
				{
					isname = 1;
					continue;
				}
			}
		}
		if (isname)
			break;
		(*i)++;
	}
	return (isname);
}*/

/**
 * _getenv - gets the value of any environment variable specified
 * @name: name of the variable
 * Return: the corresponding value if the name exists or NULL
 */
char *_getenv(const char *name)
{
	int i = 0, k, isname = 0;
	char *var = NULL;

	isname = environvar_cmp(name, &i, &k);
	if (isname)
	{
		var = environ[i] + k + 1;
		return (var);
	}
	return (var);
}

/**
 * lengthTillEqual - gets the length of an environment variable
 * till the equal to sign
 * @str: the variable
 * Return: the length
 */
int lengthTillEqual(char *str)
{
	int i = 0;

	while (str[i] != '=')
		i++;
	return (i);
}
