MANDATORY=$(find . -maxdepth 1 -type f -not -name "*_bonus.c" -name "*.c")
BONUS=$(find . -maxdepth 1 -type f \( -name "*_bonus.c" -o -name "main.c" \))

# echo "Mandatory:\n$MANDATORY"
# echo "Bonus:\n$BONUS"

if [ $1 = "m1" ]; then
	cc -g -Wall -Wextra -Werror -D BUFFER_SIZE="$3" $MANDATORY
elif [ $1 = "m0" ]; then
	cc -g -Wall -Wextra -Werror $MANDATORY
elif [ $1 = "b1" ]; then
	cc -g -Wall -Wextra -Werror -D BUFFER_SIZE="$3" $BONUS
elif [ $1 = "b0" ]; then
	cc -g -Wall -Wextra $BONUS
fi

if [ $2 -eq 1 ]; then
	leaks -atExit -- ./a.out
elif [ $2 -eq 0 ]; then
	./a.out
fi
