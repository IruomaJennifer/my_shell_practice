#include "shell.h"

/**
 * cmdtype_check - checks the command type passed to the shell
 * @cmd: the first argument passed to the shell
 * Return: an int telling the command type
 */
int cmdtype_check(char *cmd)
{
	int i = 0;
	char *builtins[] = {"env", "exit"};

	if (cmd[0] == '/')
		return (NORMAL);
	while (i < 2)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
			return (BUILTIN);
		i++;
	}
	path_cmd = get_pathcmd(cmd);
	if (path_cmd != NULL)
		return (PATH);
	return (INVALID);
}

/**
 * execute - executes a command
 * @cmd: the command name
 * @args: the arguments that come with the command
 */
void execute(char *cmd, char **args)
{
	pid_t cpid;
	int status;

	cpid = fork();
	if (cpid == -1)
	{
		print(STDERR_FILENO, "./hsh: ");
		print(STDERR_FILENO, _itoa(shell_calls));
		print(STDERR_FILENO, ": ");
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			print(STDERR_FILENO, "./hsh: ");
			print(STDERR_FILENO, _itoa(shell_calls));
			print(STDERR_FILENO, ": ");
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}

/**
 * non_interactive - executes the non_interactive shell
 * Return: 0 or 1 if an exit command was encountered
 */
int non_interactive(void)
{
	char *line;
	char **tokens;
	int rstatus;

	line = _getline(STDIN_FILENO);
	tokens = tokenize(line);
	rstatus = shell_execute(tokens);
	return (rstatus);
}


