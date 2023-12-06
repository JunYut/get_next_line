norminette -R CheckDefine get_next_line.h
echo ""
find . -type f -not -name "*main*" -name "*.c" | xargs norminette