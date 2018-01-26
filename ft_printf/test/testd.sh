rm ./a.out
make fclean
make aclean
gcc maind.c libftprintf.a
./a.out # | cat -e
