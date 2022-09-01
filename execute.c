#include "shell.h"

void execute(char **args)
{
	pid_t cpid;
	int status;
	
	cpid = fork();
	if (cpid == -1)
	{
		perror("Failed");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}

