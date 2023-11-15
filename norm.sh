BONUS=$1

if [ "$BONUS" = "b" ]; then
	norminette -R CheckDefine *.h | grep "_bonus"
	norminette *.c | grep "_bonus"
else
	norminette -R CheckDefine *.h | grep -v "_bonus"
	norminette *.c | grep -v "_bonus" | grep -v "main"
fi