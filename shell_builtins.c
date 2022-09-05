#include "shell.h"

/**
 * _printenv - prints the environment using environ
 *
 * Return: Always 0.
 */
void _printenv(void)
{
    unsigned int i;

    i = 0;
    while (environ[i] != NULL)
    {
        print(STDOUT_FILENO, environ[i]);
	print(STDOUT_FILENO, "\n");
        i++;
    }

}

