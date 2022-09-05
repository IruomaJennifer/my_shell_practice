#include "shell.h"

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
			return(buffer);
		}
		index++;
	}
	return (NULL);
}

char *cmd_check(char *cmd)
{
	int i = 0;
	char *cmd_buf;
	char *builtins[] = {"env"};
	void (*handler[])(void) = {_printenv};


	if (cmd[0] == '/')
	{
		cmd_buf = cmd;
		return (cmd_buf);
	}
	while (i < 1)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
		{
			handler[i]();
			cmd_buf = " ";
			return (cmd_buf);
		}
		i++;
	}

	cmd_buf = get_pathcmd(cmd);
	return (cmd_buf);
}
