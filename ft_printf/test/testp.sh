rm ./a.out
make fclean
make aclean
gcc mainp.c libftprintf.a
./a.out # | cat -e
