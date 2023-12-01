#include "get_next_line.h"
#include <fcntl.h>

void file_test(void);

int main(void)
{
	file_test();
}

void file_test(void)
{
	int fd = open("text.txt", O_RDONLY);
	char* line;

	printf("Read from file:\n");
	printf("call 1: %s", line = get_next_line(fd));
	free(line);
	// printf("\n_____________________________________");
	printf("call 2: %s", line = get_next_line(fd));
	free(line);
	// printf("\n_____________________________________");
	printf("call 3: %s", line = get_next_line(fd));
	free(line);
	// printf("\n_____________________________________");
	printf("call 4: %s", line = get_next_line(fd));
	free(line);
}