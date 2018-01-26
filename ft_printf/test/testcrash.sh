rm ./a.out
make fclean
make aclean
gcc maincrash.c libftprintf.a
./a.out # | cat -e
