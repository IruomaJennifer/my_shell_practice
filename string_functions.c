#include "shell.h"

/**
 * _strcpy - copies a string from one memory location to another
 * @dest: destination string pointer
 * @src: source string pointer
 * Return: nada
 */
char *_strcpy(char *dest, char *src)
{
int len = _strlen(src);
int i;

for (i = 0; i < len; i++)
{
	dest[i] = src[i];

}
dest[len] = '\0';
return (dest);
}

int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
