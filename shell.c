#include "shell.h"

int main(void)
{
	char *line;
	char **tokens;

	while (1)
	{
		print(STDOUT_FILENO, " $ ");

		line = _getline(STDIN_FILENO);
		tokens = _tokenize(line);
		execute(tokens);
	}
	return (0);
}



