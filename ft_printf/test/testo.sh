rm ./a.out
make fclean
make aclean
gcc maino.c libftprintf.a
./a.out # | cat -e
