COMPILE=$1
MEMCHECK=$2

if [ "$COMPILE" -eq 1 ]; then
	cc -g -Wall -Wextra -Werror *.c -o executable
elif [ "$COMPILE" -eq -1]; then
	rm -f executable
fi

if [ "$MEMCHECK" = "M" ]; then
	valgrind --tool=memcheck ./executable
elif [ "$MEMCHECK" = "v" ]; then
	valgrind ./executable
else
	./executable
fi