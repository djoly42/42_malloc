rm ./a.out
make fclean
make aclean
gcc maindd.c libftprintf.a
./a.out # | cat -e
