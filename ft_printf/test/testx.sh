rm ./a.out
make fclean
make aclean
gcc mainx.c libftprintf.a
./a.out # | cat -e
