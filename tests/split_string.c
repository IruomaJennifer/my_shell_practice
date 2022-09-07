#include "shell.h"

int isDelimiter(char c)
{
	char *delim = DELIM;
	int i = 0;
	while (delim[i])
	{
		if (c == delim[i])
			return (1);
		i++;
	}
	return (0);
}

char **tokenize(char *str)
{
	char *delim = DELIM;
	char **tokens = NULL, *token;
	int count, i, word = 0, oldsize, newsize;

	printf("inside tokenize\n");
	token = split_string(str, delim);
	while (token)
	{
		count = _strlen(token);
		oldsize = word * sizeof(char *);
		newsize = (word + 2) * sizeof(char *);
		tokens = _realloc(tokens, oldsize, newsize);
		word++;
		tokens[word - 1] = malloc(count);
		for (i = 0; token[i]; i++)
			tokens[word - 1][i] = token[i];
		token = split_string(NULL, delim);
	}
	tokens[word + 1] = NULL;
	return (tokens);
}


char *split_string(char *str, char *delim)
{ 
	static char *savptr;
	int i, j;

	if (str == NULL && savptr != NULL)
	{
		str = savptr;
		for (i = 0; savptr[i]; i++)
		{
			if (isDelimiter(savptr[i]))
				continue;
			else
			{
				savptr = savptr + i;
				str = savptr;
				break;
			}
		}
		for (i = 0; savptr[i]; i++)
		{
			for (j = 0; delim[j]; j++)
			{
				if (savptr[i] == delim[j])
				{
					savptr[i] = '\0';
					savptr = (savptr + i + 1);
					return (str);
				}
			}
			j = 0;
		}
		savptr[i] = '\0';
		savptr = NULL;
		return (str);
	}
	else if (str != NULL)
	{
		savptr = first_time(str, delim);
		/*
		for (i = 0; str[i]; i++)
		{
			if (isDelimiter(str[i]))
				continue;
			else
			{
				str = str + i;
				break;
			}
		}
		for(i = 0; str[i]; i++)
		{
			for (j = 0; delim[j]; j++)
			{	
				if (str[i] == delim[j])
				{
					str[i] = '\0';
					savptr = (str + i + 1);
					return (str);
				}
			}
			j = 0;
		}
		str[i] = '\0';
		return (str);
		*/
	}
	else
	{
		str = NULL;
		return (str);
	}
}

char *first_time(char *str, const char *delim)
{
	int i, j;
	char *savptr = NULL;

	for (i = 0; str[i]; i++)
	{
		if (isDelimiter(str[i]))
			continue;
		else
		{
			str = str + i;
			break;
		}
	}
	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				str[i] = '\0';
				savptr = (str + i + 1);
				
			}
		}
		j = 0;
	}
	str[i] = '\0';
	return (savptr);
}

