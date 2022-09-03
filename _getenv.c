#include "shell.h"

char *_getenv(const char *name)
{
	int i = 0, k, isname = 0;
	char *var = NULL;

	while (environ[i])
	{
		if (lengthTillEqual(environ[i]) == _strlen2(name))
		{
			for (k = 0; k < _strlen2(name); k++)
			{
				if (environ[i][k] != name[k])
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
		{
			var = environ[i] + k + 1;
			return (var);
		}
		i++;
	}
	return (var);
}

int lengthTillEqual(char *str)
{
	int i = 0;
	while (str[i] != '=')
	{
		i++;
	}
	return (i);
}

int lengthAfterEqual(char *str, int k)
{
	int i = 0;
	while (str[k++])
		i++;
	return (i);
}

int _strlen2(const char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

