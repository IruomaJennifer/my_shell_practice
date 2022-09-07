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
#define BUFSIZE 100
char **tokenize(char *str)
{
	char *delim = DELIM;
	int bufsize = BUFSIZE, pos = 0, oldsize;
	char *token;
	char **tokens = malloc(bufsize *sizeof(char *));

	token = split_string(str, delim);
	printf("%s\n", token);
	while (token)
	{
		tokens[pos++] = token;
		if (pos >= bufsize)
		{
			oldsize = bufsize;
			bufsize += BUFSIZE;
			tokens = _realloc(tokens, oldsize, bufsize);
		}
		token = split_string(NULL, delim);
	}
	tokens[pos] = NULL;
	return (tokens);
}


char *split_string(char *str, char *delim)
{ 
	static char *input = NULL;
	char *res;
	int i = 0;

	if (str)
		input = str;
	if (!input)
		return (NULL);
	while (input[i])
	{
		if (isDelimiter(input[i]))
			break;
		i++;
	}
	res = malloc((i + 1) * sizeof(char));
	for (i = 0; input[i]; i++)
	{
		if (isDelimiter(input[i]) == 0)
			res[i] = input[i];
		else
		{
			res[i] = '\0';
			input += (i + 1);
			return (res);
		}
	}
	res[i] = '\0';
	input = NULL;
	return (res);

}


