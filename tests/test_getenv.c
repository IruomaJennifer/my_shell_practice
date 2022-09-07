#include "shell.h"

int main(void)
{
	char **tokens;
	
	list_dir *directory_list, *current_dir;

	char *path = _getenv("PATH");
	tokens = tokenize_path(path);
	directory_list = link_dir(tokens);
	current_dir = directory_list;
	while(current_dir != NULL)
	{
		printf("%s\n", current_dir->dir);
		current_dir = current_dir->next;
	}
	return (0);
}

