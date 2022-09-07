#include "shell.h"
/**
 * _strcat - concatenates two strings
 * @dest: the destnation string
 * @src: the source string
 * Return: a pointer to a char type
 */

char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest);
	char *p;

	p = dest + len;
	while (*src != '\0')
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}

