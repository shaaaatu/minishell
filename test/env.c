#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *value;

	value = getenv("PATH");
	printf("%s\n", value);
}
