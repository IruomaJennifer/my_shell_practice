#include "shell.h"

/**
 * _itoa - function to change a number to a character
 * @i: the number
 * Return: the number string
 */
char *_itoa(int i)
{
	int k = i, h = 0, cnt = 0, start = 1;
	int pow_ten = getpower_ten(i);

	char *str = malloc(pow_ten + 1);

	while (pow_ten > 1)
	{
		start *= 10;
		pow_ten--;
	}
	while (start)
	{
		h = k / start;
		k = k % start;
		str[cnt] = h + '0';
		start /= 10;
		cnt++;
	}
	str[cnt] = '\0';
	return (str);
}

/**
 * getpower_ten - gets how many tens are in a number
 * @num: the number
 * Return: the number of tens
 */
int getpower_ten(int num)
{
	int pow_ten = 0;

	while (num)
	{
		num /= 10;
		pow_ten++;
	}
	return (pow_ten);
}

/**
 * _atoi - converts a string to int
 * @s: string to convert
 * Return: an integer number
 */
int _atoi(char *s)
{
	int i = 0, negatives = 0, n = 0, len = 0, f = 0, digit = 0;

	while (s[len] != '\0')
		len++;
	while (i < len && f == 0)
	{
		if (s[i] == '-')
			negatives++;
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (negatives % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}
	if (f == 0)
		return (0);
	return (n);
}

/**
 * isDelimiter - checks if a character is a delimiter
 * @c: character to check
 * Return: 1 if true, and 0 if false
 */
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

/**
 * print - function to write to any file descriptor
 * @fd: file descriptor
 * @str: string to print
 * Return: void
 */
void print(int fd, char *str)
{
	write(fd, str, _strlen(str));
}
