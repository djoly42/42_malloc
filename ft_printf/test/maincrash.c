#include "ft_printf.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

#include <stdio.h> /* !!! */

typedef unsigned long long		ull;
typedef long long				ll;
typedef unsigned long			ul;

typedef enum		e_modifier
{
	NONE,
	HH,
	H,
	L,
	LL,
	J,
	T,
	Z
}
;
void	ft_print_result(int mr, int or, int line)
{
	static int c = 0;
	printf("\033[33m[%d]\033[0m MINE = %i - ORIG = %i", c, mr, or);
	if (mr == or)
		printf("\t\033[32m✔\033[0m");
	else
		printf("\t\033[31m✘ - (failed between lines %i and %i)\033[0m",
			   line - 3, line);
	printf("\n---------------\n");
	c++;
}

int	main(void)
{
	int	or, mr;
	char	**test;

	test = malloc(sizeof(char*));
	or = 0;
	mr = 0;

/*
mr = ft_printf("MINE>d 2147483648\t[%d]\n", 2147483648);
	or = printf("ORIG>d 2147483648\t[%d]\n", 2147483648);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>5.d 5.0d 0 0\t[%5.d], [%5.0d]\n", 0, 0);
	or = printf("ORIG>5.d 5.0d 0 0\t[%5.d], [%5.0d]\n", 0, 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>5.d 5.0d 1 1\t[%5.d], [%5.0d]\n", 1, 1);
		or = printf("ORIG>5.d 5.0d 1 1\t[%5.d], [%5.0d]\n", 1, 1);
		ft_print_result(mr, or, __LINE__);


mr = ft_printf("MINE>u -1\t[%u]\n", -1);
	or = printf("ORIG>u -1\t[%u]\n", -1);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>u 4294967296\t[%u]\n", 4294967296);
	or = printf("ORIG>u 4294967296\t[%u]\n", 4294967296);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>.10d -42\t[%.10d]\n", -42);
	or = printf("ORIG>.10d -42\t[%.10d]\n", -42);
	ft_print_result(mr, or, __LINE__);
*/
/*
	ft_printf("MINE>\t");
	ft_printf("% Z%s", "test");
	ft_printf("\n");

	printf("ORIG>\t");
	printf("% Z%s", "test");
	printf("\n");

mr = ft_printf("MINE>\t[% Z%s]\n", "test");
	or = printf("ORIG>\t[% Z%s]\n", "test");
	ft_print_result(mr, or, __LINE__);
*/
/*
mr = ft_printf("MINE>03.2d 0\t[%-03.2d]\n", 0);
or = printf("ORIG>03.2d 0\t[%-03.2d]\n", 0);
ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>03.2d 1\t[%-03.2d]\n", 1);
or = printf("ORIG>03.2d 1\t[%-03.2d]\n", 1);
ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%-03.2d]\n", -1);
or = printf("ORIG>\t[%-03.2d]\n", -1);
ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%-06.2d]\n", -1);
or = printf("ORIG>\t[%-06.2d]\n", -1);
ft_print_result(mr, or, __LINE__);

//45 63
	mr = ft_printf("MINE>\t[%0-+8.4d]\n", 10);
	or = printf(   "ORIG>\t[%0-+8.4d]\n", 10);
	ft_print_result(mr, or, __LINE__);

ft_print_result(mr, or, __LINE__);
mr = ft_printf("MINE>###-#0000 33...12..#0+0d 256\t[%###-#0000 33...12..#0+0d]\n", 256);
or = printf("ORIG>###-#0000 33...12..#0+0d 256\t[%###-#0000 33...12.#0+0d]\n", 256);
ft_print_result(mr, or, __LINE__);
*/
/*
mr = ft_printf("MINE>\t[%p]\n", &mr);
or = printf(   "ORIG>\t[%p]\n", &mr);
ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%p]\n", &or);
or = printf(   "ORIG>\t[%p]\n", &or);
ft_print_result(mr, or, __LINE__);
int m;
mr = ft_printf("MINE>\t[%10p]\n", &m);
or = printf(   "ORIG>\t[%10p]\n", &m);
ft_print_result(mr, or, __LINE__);
int r;
mr = ft_printf("MINE>\t[%+10p]\n", test);
or = printf(   "ORIG>\t[%+10p]\n", test);
ft_print_result(mr, or, __LINE__);
*/



//10 "% d"
mr = ft_printf("MINE> 5d 650\t[% 5d]\n", 650);
or = printf("ORIG> 5d 650\t[% 5d]\n", 650);
ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE> d 9999\t[% d]\n", 9999);
or = printf("ORIG> d 9999\t[% d]\n", 9999);
ft_print_result(mr, or, __LINE__);

//10 "% d"
mr = ft_printf("MINE> 03d 0\t[% 03d]\n", 0);
or = printf("ORIG> 03d 0\t[% 03d]\n", 0);
ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>03.2 -1\t[%03.2d]\n", -1);
or = printf("ORIG>03.2 -1\t[%03.2d]\n", -1);
ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>3.2 -1\t[%3.2d]\n", -1);
or = printf("ORIG>3.2 -1\t[%3.2d]\n", -1);
ft_print_result(mr, or, __LINE__);

//54
mr = ft_printf("MINE>06.2d -1\t[%06.2d]\n", -1);
or = printf("ORIG>06.2d -1\t[%06.2d]\n", -1);
ft_print_result(mr, or, __LINE__);

//56
mr = ft_printf("MINE>5.d 1\t[%5.d], [%5.0d]\n", 1, 1);
or = printf("ORIG>5.d 1\t[%5.d], [%5.0d]\n", 1, 1);
ft_print_result(mr, or, __LINE__);

//69
	mr = ft_printf("MINE>5.d 5.0d 1 1\t[%5.d], [%5.0d]\n", 1, 1);
	or = printf("ORIG>5.d 5.0d 1 1\t[%5.d], [%5.0d]\n", 1, 1);
	ft_print_result(mr, or, __LINE__);

    return (0);
}
