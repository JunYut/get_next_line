#include "get_next_line_bonus.h"
#include <fcntl.h>

void file_test(void);
void stdin_test(void);

int main(void)
{
	int fd = open("../gnlTester/files/multiple_line_no_nl", O_RDONLY);
	printf("From multiple_line_no_nl: %s", get_next_line(fd));
	fd  = open("../gnlTester/files/43_with_nl", O_RDONLY);
	printf("From 43_with_nl: %s", get_next_line(fd));
	fd = open("../gnlTester/files/multiple_line_no_nl", O_RDONLY);
	printf("From multiple_line_no_nl again: %s", get_next_line(fd));
	fd  = open("../gnlTester/files/43_with_nl", O_RDONLY);
	printf("From 43_with_nl again: %s", get_next_line(fd));
	fd = open("../gnlTester/files/multiple_line_no_nl", O_RDONLY);
	printf("From multiple_line_no_nl again: %s", get_next_line(fd));
	printf("From multiple_line_no_nl again: %s", get_next_line(fd));
}

void file_test(void)
{
	int fd = open("../gnlTester/files/43_with_nl", O_RDONLY);
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
