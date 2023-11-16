COMPILE=$1
MEMCHECK=$2
BUFFER=$3

if [ "$COMPILE" -eq 1 ]; then
	cc -g -Wall -Wextra -Werror -D BUFFER_SIZE=$BUFFER *.c -o executable
elif [ "$COMPILE" -eq 0 ]; then
	cc -g -Wall -Wextra -Werror *.c -o executable
elif [ "$COMPILE" -eq -1 ]; then
	rm -f executable
fi

if [ "$MEMCHECK" = "1" ]; then
	leaks -atExit -- ./executable
elif [ "$MEMCHECK" = 0 ]; then
	./executable
fi