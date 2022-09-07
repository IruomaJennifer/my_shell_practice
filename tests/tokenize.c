#include "shell.h"
#define TOK_BUFF 10
char **_tokenize(char *str)
{
	char **tokens;
	char *token;
	const char *delim = DELIM;
	int i = 0, tok_buff = TOK_BUFF, oldsize, newsize;

	tokens = malloc(tok_buff * sizeof(char *));
	token = strtok(str, delim);
	while (token)
	{
		tokens[i] = token;

		token = strtok(NULL, delim);
		i++;
		if (i >= tok_buff)
		{
			oldsize = tok_buff * sizeof(char *);
			tok_buff += tok_buff;
			newsize = tok_buff * sizeof(char *);
			tokens = _realloc(tokens, oldsize, newsize);
		}
	}
	tokens[i] = NULL;
	return (tokens);
}

