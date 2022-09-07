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
	directories = tokenize_bydelim(path, ':');
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
	builtin commands[] = {
		{"env", _printenv}, {"exit", end},
		{NULL, NULL}};

	cmd_type = cmdtype_check(cmd[0]);
	if (cmd_type == INVALID)
	{
		print(STDERR_FILENO, "./hsh: ");
		print(STDERR_FILENO, _itoa(shell_calls));
		print(STDERR_FILENO, ": ");
		print(STDERR_FILENO, cmd[0]);
		print(STDERR_FILENO, ": File not found\n");
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
	execute(path_cmd, cmd);
	return (0);
}
