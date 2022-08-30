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
	const char *delim = DELIM;
	char **tokens = NULL, *token;
	int count, i, word = 0;

	token = split_string(str, delim);
	while (token)
	{
		count = _strlen(token);
		tokens = _realloc((void *)tokens,(word * sizeof(char *)), ((word + 1) * sizeof(char *)));
		word++;
		tokens[word - 1] = malloc(count);
		for (i = 0; token[i]; i++)
			tokens[word - 1][i] = token[i];

		token = split_string(NULL, delim);
	}
	tokens = _realloc((void *)tokens, (word * sizeof(char *)), ((word + 1) * sizeof(char *)));
	tokens[word - 1] = NULL;
	return (tokens);
}


char *split_string(char *str, const char *delim)
{ 
	static char **savptr;
	int i, j;

	if (str == NULL && savptr != NULL)
	{
		str = *savptr;
		for (i = 0; *savptr[i]; i++)
		{
			if (isDelimiter(*savptr[i]))
				continue;
			else
			{
				*savptr = *savptr + i;
				str = *savptr;
				break;
			}
		}
		for (i = 0; *savptr[i]; i++)
		{
			for (j = 0; delim[j]; j++)
			{
				if (*savptr[i] == delim[j])
				{
					*savptr[i] = '\0';
					*savptr = ((*savptr) + i + 1);
					return (str);
				}
			}
			j = 0;
		}
		*savptr[i] = '\0';
		savptr = NULL;
		return (str);
	}
	else if (str != NULL)
	{
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
					*savptr = (str + i + 1);
					return (str);
				}
			}
			j = 0;
		}
		str[i] = '\0';
		savptr = NULL;
		return (str);
	}
	else
	{
		return (NULL);
	}
}

