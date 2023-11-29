#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

void file_test(void);

int main()
{
	file_test();
}

void file_test(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *line;

	printf("line 1: %s", line = get_next_line(fd));
	free(line);
	printf("line 2: %s", line = get_next_line(fd));
	free(line);
	printf("line 3: %s", line = get_next_line(fd));
	free(line);
	printf("line 4: %s", line = get_next_line(fd));
	free(line);
}
