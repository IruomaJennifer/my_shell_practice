#include "shell.h"

void execute(char *cmd, char **args)
{
	pid_t cpid;
	int status;
	
	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			print(STDERR_FILENO,"./hsh: ");
			print(STDERR_FILENO, _itoa(shell_calls));
			print(STDERR_FILENO, ": ");
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}

