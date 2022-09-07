#include "shell.h"

/**
 * get_pathcmd - checks the PATH for a program and gets it if
 * it exists
 * @cmd: the name of the program
 *
 * Return: the path to the file or NULL if it doesn't exist
 */
char *get_pathcmd(char *cmd)
{
	char *path;
	char **directories;
	int index = 0;
	char *buffer;

	path = _getenv("PATH");
	directories = tokenize_path(path);
	while (directories[index])
	{
		buffer = malloc(_strlen(directories[index]) + 1);
		if (!buffer)
			return (NULL);
		_strcpy(buffer, directories[index]);
		buffer = _strcat(buffer, "/");
		buffer = _strcat(buffer, cmd);
		if (access(buffer, F_OK) == 0)
		{
			return (buffer);
		}
		index++;
	}
	return (NULL);
}

/**
 * shell_execute - executes programs based on the command type
 * @cmd: the arguments of a command
 * Return: 0 or 1 if the command is exit
 */
int shell_execute(char **cmd)
{
	int cmd_type, i = 0;

	cmd_type = cmdtype_check(cmd[0]);
	if (cmd_type == INVALID)
	{
		print(STDERR_FILENO, "./hsh: ");
		print(STDERR_FILENO, _itoa(shell_calls));
		print(STDERR_FILENO, ": ");
		print(STDERR_FILENO, cmd[0]);
		print(STDERR_FILENO, "File not found");
		return (0);
	}
	else if (cmd_type == NORMAL)
	{
		execute(cmd[0], cmd);
		return (0);
	}
	else if (cmd_type == BUILTIN)
	{
		while (commands[i].name)
		{
			if (_strcmp(cmd[0], commands[i].name) == 0)
			{
				commands[i].handler(cmd);
				if (_strcmp(cmd[0], "exit") == 0)
					return (1);
				return (0);
			}
			i++;
		}
	}
	else
	{
		execute(path_cmd, cmd);
		return (0);
	}
}

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
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
	{
		if (execve(cmd, args, NULL) == -1)
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
 * non_interactive - executes the non-interactive shell
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
