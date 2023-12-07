#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char* line;
	int fd1 = open("test1", O_RDONLY);
	int fd2 = open("test2", O_RDONLY);
	
	printf("test1	:%s", line = get_next_line(fd1));
	free(line);

	printf("test2	:%s", line = get_next_line(fd2));
	free(line);
	
	printf("test1	:%s", line = get_next_line(fd1));
	free(line);

	printf("test2	:%s", line = get_next_line(fd2));
	free(line);

	printf("test1	:%s", line = get_next_line(fd1));
	free(line);

}
