rm ./a.out
make fclean
make aclean
gcc maini.c libftprintf.a
./a.out # | cat -e
