#include "shell.h"

int main(void)
{
	char *line;
	char **tokens;
	int rstatus;

	shell_calls = 0;

	while (1)
	{
		shell_calls++;

		if (isatty(STDIN_FILENO) == 0)
		{
			rstatus = non_interactive();
			return (rstatus);
		}

		print(STDOUT_FILENO, " ($) ");

		line = _getline(STDIN_FILENO);
		tokens = tokenize(line);
		rstatus = shell_execute(tokens);
		printf("%d\n", shell_calls);
		if (rstatus)
			return(exit_status);
	}
	return (0);
}
