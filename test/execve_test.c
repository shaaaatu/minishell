#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	extern char **environ;
	char *arr[] = {"/bin/ls", "-l", NULL};
//	pid_t pid;
//	pid = fork();
//	if (pid > 0)
//		printf("parent process\n");
//	else if (pid == 0)
//	{
		printf("child process\n");
		execve("/bin/ls", arr, environ);
//		perror("execve");
//	}
	return (0);
}
