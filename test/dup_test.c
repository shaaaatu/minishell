#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main()
{
	int	save_fd = dup(1);
	int	file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file_fd < 0)
	{
		perror("open");
		return (1);
	}
	dup2(file_fd, 1);
	close(file_fd);
	printf("This will be written to output.txt\n");
	fflush(stdout);
	dup2(save_fd, 1);
	close(save_fd);
	printf("This will be written to fd 1\n");
	return 0;
}
