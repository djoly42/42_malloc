rm ./a.out
make fclean
make aclean
gcc mainu.c libftprintf.a
./a.out # | cat -e
