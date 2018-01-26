rm ./a.out
make fclean
make aclean
gcc mains.c libftprintf.a
./a.out # | cat -e
