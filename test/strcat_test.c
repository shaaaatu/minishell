#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char	*str;
	str = (char *)malloc(sizeof(char) * 4);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';
	str = strcat(str, argv[1]);
	printf("%s\n", str);
}
