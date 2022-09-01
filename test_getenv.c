#include "shell.h"

int main(void)
{
	char **tokens;
	int i = 0;

	char *path = _getenv("PATH");
	tokens = tokenize_path(path);
	while(tokens[i])
	{
		printf("%s\n", tokens[i++]);
	}
	return (0);
}

