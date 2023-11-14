#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

//_____________________________________________________________________________
int main(void)
{
	// Read from text file
	printf("Read from text file:\n");
	int fd = open("text.txt", O_RDONLY);
	char* str = get_next_line(fd);
	printf("line 1: %s\n", str);
	
	str = get_next_line(fd);
	printf("line 2: %s\n", str);

	str = get_next_line(fd);
	printf("line 3: %s\n", str);

	str = get_next_line(fd);
	printf("line 4: %s\n", str);

	close(fd);
}
