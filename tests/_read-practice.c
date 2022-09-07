#include "shell.h"

int main(void)
{
	char buffer[1024];

	int cnt = read(STDIN_FILENO, &buffer, buffsize);

	printf("%d bytes - %s\n", cnt, buffer);
	return (0);
}

char *_getline(int fd)
{
	
