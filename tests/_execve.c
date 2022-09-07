#include "shell.h"

extern char **environ;
int main(void)
{
	pid_t cpid;
	int status, i = 0;
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};

	while ( i < 5)
	{
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
	i++;

	}

	return (0);
}
