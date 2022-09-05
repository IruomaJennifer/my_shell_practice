#include "shell.h"

int main(void)
{
	char *line;
	char **tokens;
	char *cmd;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 0)
		{
			non_interactive();
			break;
		}

		print(STDOUT_FILENO, " ($) ");

		line = _getline(STDIN_FILENO);
		tokens = _tokenize(line);
		cmd = cmd_check(tokens[0]);
		if (cmd == NULL)
		{
			perror("./hsh : no such file or directory");
			exit(EXIT_FAILURE);
		}
		if (cmd[0] == ' ')
			continue;
		execute(cmd, tokens);
	}
	return (0);
}

void non_interactive(void)
{
	char *line;
	char **tokens;
	char *cmd;
	
	line = _getline(STDIN_FILENO);
	tokens = _tokenize(line);
	cmd = cmd_check(tokens[0]);
	if (cmd == NULL)
	{
		perror("./hsh : no such file or directory");
		exit(EXIT_FAILURE);
	}
	execute(cmd, tokens);
}

