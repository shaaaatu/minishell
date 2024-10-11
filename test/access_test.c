#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	printf("access: %d\n", access(argv[1], X_OK));
}
