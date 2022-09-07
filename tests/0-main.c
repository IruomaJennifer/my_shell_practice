#include <stdio.h>
#include "shell.h"
int main(void)
{
	char *num = "12345";
	int i = 0;

	num = _realloc(num, 5, 3);

	while (num[i])
		printf("%c\n", num[i++]);
	return (0);
}



