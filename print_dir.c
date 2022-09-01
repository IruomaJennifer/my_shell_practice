#include "shell.h"

char **tokenize_path(char *str)
{
	char **tokens;

	/*Get length of all tokens and number of tokens*/
	char delim = ':';
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
	/*Allocate space for all tokens*/
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
