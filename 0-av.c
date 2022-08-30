#include <stdio.h>
/**
 * main - program that prints all arguments without using ac
 */
int main(__attribute__((unused))int ac, char **av)
{
	while (*av)
	{
		printf("%s\n", *av);
		av++;
	}
	return (0);
}

