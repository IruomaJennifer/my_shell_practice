/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: a +ve int number, -ve int number, or 0
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*s1 != '\0')
	{
		i = i + (*s1 - *s2);
		if (i < 0)
			return (i);
		else if (i > 0)
			return (i);
		s1++;
		s2++;
	}
	return (i);
}

