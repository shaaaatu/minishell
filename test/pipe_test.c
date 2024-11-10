#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int	pipefd[2];
	int	pid;

	if (argc != 2)
	{
		printf("検索キーワードを入れてください\n");
		exit (1);
	}
	pipe(pipefd);
	pid = fork();
	if (pid > 0)
	{
		close(1);
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		char *ls_args[] = {"ls", "-l", NULL};
		execvp("ls", ls_args);
		perror("execvp");
		exit(1);
	}
	else
	{
		close(0);
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		char *grep_args[] = {"grep", argv[1], NULL};
		execvp("grep", grep_args);
		perror("execvp");
		exit(1);
	}
	return (0);
}
