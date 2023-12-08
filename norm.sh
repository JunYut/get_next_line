MANDATORY=$(find . -type f -not -name "*_bonus*" -not -name "*main*")
BONUS=$(find . -type f -not -name "*main*")

if [ "$1" = "b" ]; then
	echo "${BONUS}" | grep "\.h" | xargs norminette -R CheckDefine
	echo "${BONUS}" | grep "\.c" | xargs norminette
else
	echo "${MANDATORY}" | grep "\.h" | xargs norminette -R CheckDefine
	echo "${MANDATORY}" | grep "\.c" | xargs norminette
fi
