#include "shell.h"

/**
 * tokenize_bydelim_end - the end of tokenize by delim
 * @tokens: the tokens
 * @k: the index of the last token
 * @a: index of last char in last token
 * Return: the list of tokens
 */
char **tokenize_bydelim_end(char **tokens, int k, int a)
{
	tokens[k][a] = '\0';
	tokens[k + 1] = NULL;
	return (tokens);
}
