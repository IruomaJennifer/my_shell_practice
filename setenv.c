#include "shell.h"

int _setenv(const char *name, const char *value ,__attribute__((unused)) int overwrite)
{
	int len_name, i = 0, k, isname = 0, val_len = 0, valp_len = 0;
	int oldsize, newsize, a = 0, env_len = 0;

	char **my_environ = environ;
	if (name == NULL || value == NULL)
		return (-1);
	len_name = _strlen2(name);
	valp_len = _strlen2(value);
	while (my_environ[i])
	{
		if (lengthTillEqual(my_environ[i]) == len_name)
		{
			for (k = 0; k < len_name; k++)
			{
				if (my_environ[i][k] != name[k])
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
		i++;
	}
	if (isname)
	{
		printf("%s\n", my_environ[i]);
		return (0);
		/*
		if (overwrite)
		{
			k += 1;
			val_len = lengthAfterEqual(my_environ[i], k);
			if (val_len != valp_len)
			{
				oldsize = k + val_len;
				newsize = k + valp_len;
				my_environ[i] = _realloc(my_environ[i], oldsize, newsize);
				if (my_environ[i] == NULL)
					return (-1);
			}
			while (value[a])
			{
				my_environ[i][k] = value[a];
				a++;
				k++;
			}
			my_environ[i][k] = '\0';
			return (0);
		}
		else
			return (0);
		*/
	}
	else
	{
		i = 0;
		while (my_environ[i])
		{
			env_len++;
			i++;
		}
		oldsize = (env_len + 1) * sizeof(char *);
		newsize = (env_len + 2) * sizeof(char *);
		my_environ = _realloc(my_environ, oldsize, newsize);
		if (my_environ == NULL)
			return (-1);
		my_environ[newsize - 2] = malloc(len_name + valp_len + 2);
		if (my_environ[newsize - 2] == NULL)
			return (-1);
		i = 0;
		while (i < len_name)
		{
			my_environ[newsize - 2][i] = name[i];
			i++;
		}
		my_environ[newsize - 2][i] = '=';
		i++;
		while (a < valp_len)
		{
			my_environ[newsize - 2][i] = value[a];
			a++;
			i++;
		}
		my_environ[newsize - 2][i] = '\0';
		my_environ[newsize - 1] = NULL;
		return (0);
	}
}
