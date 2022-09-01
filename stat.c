#include "shell.h"

int main(int ac, char **av)
{
	int i;
	struct stat st;

	if (ac < 2)
	{
		print(STDOUT_FILENO, "Usage: ");
		print(STDOUT_FILENO, av[0]);
		print(STDOUT_FILENO, "path to file\n");
		return (1);
	}
	i = 1;
	while (av[i])
	{
		print(STDOUT_FILENO, av[i]);
		if (stat(av[i], &st) == 0)
		{
			print(STDOUT_FILENO, ": Found");
			print(STDOUT_FILENO, "\n");
		}
		else
		{
			print(STDOUT_FILENO, ": Not Found");
			print(STDOUT_FILENO, "\n");
		}
		i++;
	}
	return (0);
}

