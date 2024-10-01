#include <stdio.h>

int get_len(char *str)
{
	int i;
	i = 0;
	printf("*str: %s\n", *str);
	while (*str)
	{
		*str++;
		i++;
	}
	return (i);
}
int main()
{
	char *str;
	int len;
	str = NULL;
	len = get_len(str);
	printf("len:%d\n", len);
}
