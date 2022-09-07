#include "shell.h"

int main(__attribute__((unused))int argc, char **argv)
{
	int i = 0;

	char *builtins[] = {"env"};
	void (*handler[])(void) = {_printenv};

	if (_strcmp(argv[1], builtins[i]) == 0)
	{
		handler[i]();
	}
	return (0);
}

