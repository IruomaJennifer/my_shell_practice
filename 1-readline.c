#include "shell.h"
/**
 * _getline - function to get a line of text
 * @lineptr: pointer to char pointer holding stream of text
 * @n: size in bytes of the stream lineptr is pointing to
 *
 * Return: number of bytes read or -1 on failure
 */

char *_getline(int fd)
{
	ssize_t cnt; size_t i = 0;
	char c;

	char *lineptr = malloc(buffsize);
	if(lineptr == NULL)
		exit(EXIT_FAILURE);

	while (1)
	{
		cnt = read(fd, &c, 1);
		if (cnt == 0 || c == '\n')
		{
			lineptr[i] = '\0';
			return (lineptr);
		}
		else if (cnt == -1)
		{
			perror("Unable to read");
			exit(EXIT_FAILURE);
		}

		lineptr[i++] = c;
		
		if (i == buffsize)
		{
			lineptr = _realloc(lineptr, buffsize, 2 * (buffsize));
		}

	}
}
int _strlen(char *str)
{ 
	int count = 0;
	while (str[count])
		count++;
	return(count);
}

void print(int fd, char *str)
{
	write(fd, str, _strlen(str));
}
/*
int main(void)
{
	char **tokens;
	int i;

	print(STDOUT_FILENO, "$ ");
	char *str = _getline(STDIN_FILENO);
	print(STDOUT_FILENO, str);
	print(STDOUT_FILENO, "\n");

	tokens = _tokenize(str);
	print(STDOUT_FILENO, "tokenization took place");
	print(STDOUT_FILENO, "\n");

	for (i = 0; tokens[i]; i++)
	{
		print(STDOUT_FILENO, tokens[i]);
		print(STDOUT_FILENO, "\n");
	}

	return (0);
}
*/
