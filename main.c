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

	printf("Read from file:\n");
	printf("call 1: %s", get_next_line(fd));
	printf("call 2: %s", get_next_line(fd));
	printf("call 3: %s", get_next_line(fd));
	//printf("call 4: %s", get_next_line(fd));	need to handle EOF
}