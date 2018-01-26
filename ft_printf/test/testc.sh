rm ./a.out
make fclean
make aclean
gcc main.c libftprintf.a
./a.out # | cat -e
