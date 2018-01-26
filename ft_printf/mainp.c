
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

	printf("\033[1;37m======== %%p ========\033[0m\n");

	mr = ft_printf("MINE>\t[%p]\n", &mr);
	or = printf(   "ORIG>\t[%p]\n", &mr);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%p]\n", &or);
	or = printf(   "ORIG>\t[%p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%10p]\n", &mr);
	or = printf(   "ORIG>\t[%10p]\n", &mr);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+10p]\n", &or);
	or = printf(   "ORIG>\t[%+10p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-10p]\n", &mr);
	or = printf(   "ORIG>\t[%-10p]\n", &mr);
	ft_print_result(mr, or, __LINE__);
//5
	mr = ft_printf("MINE>\t[%+14p]\n", &or);
	or = printf(   "ORIG>\t[%+14p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+017p]\n", &or);
	or = printf(   "ORIG>\t[%+017p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-017p]\n", &or);
	or = printf(   "ORIG>\t[%+-017p]\n", &or);
	ft_print_result(mr, or, __LINE__);
//8
	mr = ft_printf("MINE>\t[%+#-017p]\n", &or);
	or = printf(   "ORIG>\t[%+#-017p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-20p]\n", &or);
	or = printf(   "ORIG>\t[%+-20p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#+-020p]\n", &or);
	or = printf(   "ORIG>\t[%#+-020p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% #+-020p]\n", &or);
	or = printf(   "ORIG>\t[% #+-020p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#+-020p]\n", &or);
	or = printf(   "ORIG>\t[% '#+-020p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#+020p]\n", &or);
	or = printf(   "ORIG>\t[%#+020p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#+020p]\n", &or);
	or = printf(   "ORIG>\t[% '#+020p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#+20p]\n", &or);
	or = printf(   "ORIG>\t[% '#+20p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#20p]\n", &or);
	or = printf(   "ORIG>\t[% '#20p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#p]\n", &or);
	or = printf(   "ORIG>\t[% '#p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#p]\n", NULL);
	or = printf(   "ORIG>\t[% '#p]\n", NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#p]\n", 140734573365944);
	or = printf(   "ORIG>\t[% '#p]\n", 140734573365944);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#p]\n", (void *)ft_printf);
	or = printf(   "ORIG>\t[% '#p]\n", (void *)ft_printf);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#p %p]\n", (void *)ft_printf, NULL);
	or = printf(   "ORIG>\t[% '#p %p]\n", (void *)ft_printf, NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#10p %-5p]\n", test, NULL);
	or = printf(   "ORIG>\t[% '#10p %-5p]\n", test, NULL);
	ft_print_result(mr, or, __LINE__);

	free(test);
	test = 4587;
	mr = ft_printf("MINE>\t[% '#10p %-5p]\n", test, NULL);
	or = printf(   "ORIG>\t[% '#10p %-5p]\n", test, NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#p %p]\n", NULL);
	or = printf(   "ORIG>\t[% '#p %p]\n", NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% '#p %p]\n", 0234234, 'b');
	or = printf(   "ORIG>\t[% '#p %p]\n", 0234234, 'b');
	ft_print_result(mr, or, __LINE__);

	printf("\033[1;37m==== %%p + modifiers ===\033[0m\n");

	mr = ft_printf("MINE>\t[%hhp]\n", (void *)ft_printf, NULL);
	or = printf(   "ORIG>\t[%hhp]\n", (void *)ft_printf, NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%hp]\n", (void *)ft_printf, NULL);
	or = printf(   "ORIG>\t[%hp]\n", (void *)ft_printf, NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%lp]\n", (void *)ft_printf, NULL);
	or = printf(   "ORIG>\t[%lp]\n", (void *)ft_printf, NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%llp]\n", (void *)ft_printf, NULL);
	or = printf(   "ORIG>\t[%llp]\n", (void *)ft_printf, NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%jp]\n", (void *)ft_printf, NULL);
	or = printf(   "ORIG>\t[%jp]\n", (void *)ft_printf, NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%tp]\n", (void *)ft_printf, NULL);
	or = printf(   "ORIG>\t[%tp]\n", (void *)ft_printf, NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%zp]\n", (void *)ft_printf, NULL);
	or = printf(   "ORIG>\t[%zp]\n", (void *)ft_printf, NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%lld]\n", 9223372036854775807);
	or = printf(   "ORIG>\t[%lld]\n", 9223372036854775807);
	ft_print_result(mr, or, __LINE__);
//
	mr = ft_printf("MINE>\t[%lli]\n", 9223372036854775807);
	or = printf(   "ORIG>\t[%lli]\n", 9223372036854775807);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%llu]\n", 18446744073709551615);
	or = printf(   "ORIG>\t[%llu]\n", 18446744073709551615);
	ft_print_result(mr, or, __LINE__);

	printf("\033[1;37m==== %%p + double attr ===\033[0m\n");

	mr = ft_printf("MINE>\t[%-20+p]\n", &or);
	or = printf(   "ORIG>\t[%-20+p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-20+lp]\n", &or);
	or = printf(   "ORIG>\t[%-20+lp]\n", &or);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-20+-p]\n", &or);
	or = printf(   "ORIG>\t[%-20+-p]\n", &or);
	ft_print_result(mr, or, __LINE__);

	printf("\033[1;37m======== end %%p ====\033[0m\n\n");




		mr = ft_printf("MINE>\t[%5.4p]\n", 0xfaf);
		or = printf(   "ORIG>\t[%5.4p]\n", 0xfaf);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%8.4p]\n", NULL);
		or = printf(   "ORIG>\t[%8.4p]\n", NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-5.4p]\n", 0xfaf);
		or = printf(   "ORIG>\t[%-5.4p]\n", 0xfaf);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-8.4p]\n", NULL);
		or = printf(   "ORIG>\t[%-8.4p]\n", NULL);
		ft_print_result(mr, or, __LINE__);
		return (0);
}
