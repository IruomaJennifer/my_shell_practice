#include "shell.h"
/*
int main(void)
{
	char *s = _itoa(50000);
	printf("%s\n",s);
}
*/
char *_itoa(int i)
{
	int k = i, h = 0, cnt = 0, start = 1;
	int pow_ten = getpower_ten(i);
	
	char *str = malloc(pow_ten + 1);
	while (pow_ten > 1)
	{
		start *= 10;
		pow_ten--;
	}
	while (start)
	{
		h = k / start;
		k = k % start;
		str[cnt] = h + '0';
		start /= 10;
		cnt++;
	}
	str[cnt] = '\0';
	return (str);
}


int getpower_ten(int num)
{
	int pow_ten = 0;
	while (num)
	{
		num /= 10;
		pow_ten++;
	}
	return (pow_ten);
}
	
