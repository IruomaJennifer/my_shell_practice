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

/**
 * _strlen - get length of a string
 * @str: string
 * Return: the length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
 * _strlen2 - get length of a constant string
 * @str: a constant str
 * Return: the length
 */
int _strlen2(const char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination string
 * @src: the source string
 * Return: the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest);
	char *p;
	int i = 0;

	p = dest + len;
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: a number != 0 if they ar not equal or 0 if they are
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	while (s1[j] != '\0')
	{
		i = i + (s1[j] - s2[j]);
		if (i < 0 || i > 0)
			return (i);
		j++;
	}
	return (i);
}

