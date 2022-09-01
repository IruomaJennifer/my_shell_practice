#include "shell.h"

int main(int ac, char **av, char **env)
{
	printf("%ld\n", (long unsigned)&env);
	printf("%ld\n", (long unsigned)&environ);
	return (0);
}

