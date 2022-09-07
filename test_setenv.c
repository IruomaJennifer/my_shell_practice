#include "shell.h"

int main(void)
{
	int i = 0;
	
	_environ = set_environ();
	_setenv("USERP", "Jenny", 1);
	
	while (_environ[i])
	{
		printf("%s\n", _environ[i]);
		i++;
	}
	
	i = 0;
	_unsetenv("USERP");
	//_setenv("USER", "gwenyfar", 1);
	while (_environ[i])
	{
		printf("%s\n", _environ[i]);
		i++;
	}
	
	return (0);
}
