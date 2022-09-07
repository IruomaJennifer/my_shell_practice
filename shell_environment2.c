#include "shell.h"

/**
 * lengthAfterEqual - gets the length of the value of an
 * environment variable
 * @str: the environment variable
 * @k: the position just after equal to
 * Return: the length
 */
int lengthAfterEqual(char *str, int k)
{
	int i = 0;

	while (str[k++])
		i++;
	return (i);
}
