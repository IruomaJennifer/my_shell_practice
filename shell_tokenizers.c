#include "shell.h"
#define BUFSIZE 100

/**
 * tokenize - turns a string into an array of strings
 * based on a delimiter
 * @str: the input string
 * Return: an array of string
 */
char **tokenize(char *str)
{
	char *delim = DELIM;
	int bufsize = BUFSIZE, pos = 0, oldsize;
	char *token;
	char **tokens = malloc(bufsize *sizeof(char *));

	token = split_string(str, delim);

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

/**
 * split_string - function to split a string on at a time
 * @str: string to be split
 * @delim: delimiters
 * Return: a string token
 */
char *split_string(char *str, char *delim)
{ 
	static char *input = NULL;
	char *res;
	int i = 0, j;

	if (str)
		input = str;
	if (!input)
		return (NULL);
	for (j = 0; input[j]; j++)
	{
		if (isDelimiter(input[j]))
			continue;
		else
		{
			input += j;
			break;
		}
	}
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

/**
 * tokenize_path - tokenizes based on a delimiter
 * @str: the string to be tokenized
 * @delim: a delimiter
 * Return: an array of strings
 */
char **tokenize_bydelim(char *str, char delim)
{
	char **tokens;
	int len[1024], i = 0, j = 0, k = 0, a = 0, cnt = 0, count = 0;

	while (str[i])
	{
		cnt++;
		if (str[i] == delim)
		{
			count++;
			len[j] = cnt;
			j++;
			cnt = 0;
		}
		i++;
	}
	cnt++;
	len[j] = cnt;
	count++;
	tokens = malloc((count + 1) * sizeof(char *));
	while (k < count)
	{
		tokens[k] = malloc(len[k]);
		k++;
	}
	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == delim)
		{
			tokens[k][a] = '\0';
			k++;
			a = 0;
			i++;
			continue;
		}
		tokens[k][a] = str[i];
		i++;
		a++;
	}
	tokens[k][a] = '\0';
	tokens[k + 1] = NULL;
	return (tokens);
}

/**
 * _getline - reads a line from a file descriptor
 * @fd: the file descriptor
 * Return: the string read
 */
char *_getline(int fd)
{
	ssize_t cnt; size_t i = 0, oldsize, newsize = 0;
	char c;
	char *lineptr;

	oldsize = buffsize;
	lineptr = malloc(oldsize);

	if (lineptr == NULL)
		exit(EXIT_FAILURE);
	while (1)
	{
		cnt = read(fd, &c, 1);
		if (cnt == 0 || c == '\n')
		{
			lineptr[i] = '\0';
			return (lineptr);
		}
		else if (cnt == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		lineptr[i++] = c;
		if (i == oldsize)
		{
			newsize = oldsize + buffsize;
			lineptr = _realloc(lineptr, oldsize, newsize);
			oldsize = newsize;
		}
	}
}
