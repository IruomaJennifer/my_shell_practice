#include "shell.h"
int environvar_cmp(const char *name, int *i, int *k)
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
}

int overwrite_function(int overwrite, int k, const char *value, int *i)
{
	int val_len, valp_len, oldsize, newsize, a = 0;
	if (overwrite)
	{
		k += 1;
		val_len = lengthAfterEqual(environ[*i], k);
		valp_len = _strlen2(value);
		if (val_len != valp_len)
		{
			oldsize = k + val_len;
			newsize = k + valp_len;
			environ[*i] = _realloc(environ[*i], oldsize, newsize);
			if (environ[*i] == NULL)
				return (-1);
		}
		while (value[a])
		{
			environ[*i][k] = value[a];
			a++;k++;
		}
		environ[*i][k] = '\0';
		printf("%s\n", environ[*i]);
		return (0);
	}
	else
		return (0);
}

int _unsetenv(const char *name)
{
	int i = 0, k = 0, isname;
	if (!name)
		return (-1);
	isname = environvar_cmp(name, &i, &k);
	if (isname)
	{
		free(environ[i]);
		while (environ[i + 1])
		{
			environ[i] = environ[i + 1];
			i++;
		}
		environ[i] = NULL;
		return (0);
	}
	else
		return (0);
}

int _setenv(const char *name, const char *value ,__attribute__((unused)) int overwrite)
{
	int len_name, i = 0, k = 0, isname, val_len = 0, valp_len = 0;
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
		environ[newsize - 2] = malloc(len_name + valp_len + 2);
		if (environ[newsize - 2] == NULL)
			return (-1);
		i = 0;
		while (i < len_name)
		{
			environ[newsize - 2][i] = name[i];
			i++;
		}
		environ[newsize - 2][i] = '=';
		i++;
		while (a < valp_len)
		{
			environ[newsize - 2][i] = value[a];
			a++;
			i++;
		}
		environ[newsize - 2][i] = '\0';
		environ[newsize - 1] = NULL;
		return (0);
	}
}
