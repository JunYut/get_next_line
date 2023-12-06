#include "get_next_line.h"
#include <fcntl.h>

void file_test(void);
void stdin_test(void);

int main(void)
{
	file_test();
	//stdin_test();
}

void file_test(void)
{
	int fd = open("gnlTester/files/41_no_nl", O_RDONLY);
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

void stdin_test(void)
{
	char* line;

	printf("Read from stdin:\n");
	printf("call 1: %s", line = get_next_line(0));
	free(line);
}
