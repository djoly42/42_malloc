
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
		printf("\033[1;37m======== %%s ========\033[0m\n");

	mr = ft_printf("MINE>\t[%s]\n", "ok");
	or = printf("ORIG>\t[%s]\n", "ok");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%3s]\n", "ok");
	or = printf("ORIG>\t[%3s]\n", "ok");
	ft_print_result(mr, or, __LINE__);

	or = printf("ORIG>\t[%s]\n", NULL);
	mr = ft_printf("MINE>\t[%s]\n", NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%s]\n", "Coconut");
	or = printf("ORIG>\t[%s]\n", "Coconut");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% s]\n", "Coconut");
	or = printf("ORIG>\t[% s]\n", "Coconut");
	ft_print_result(mr, or, __LINE__);
//5
	mr = ft_printf("MINE>\t[% 2s]\n", "Coconut");
	or = printf("ORIG>\t[% 2s]\n", "Coconut");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-4s]\n", "Coconut");
	or = printf("ORIG>\t[%-4s]\n", "Coconut");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+8s]\n", "Coconut");
	or = printf("ORIG>\t[%+8s]\n", "Coconut");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+15s]\n", "Coconut");
	or = printf("ORIG>\t[%+15s]\n", "Coconut");
	ft_print_result(mr, or, __LINE__);
//9
	mr = ft_printf("MINE>\t[%-15s]\n", "Coconut");
	or = printf("ORIG>\t[%-15s]\n", "Coconut");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%15s]\n", "Coconut");
	or = printf("ORIG>\t[%15s]\n", "Coconut");
	ft_print_result(mr, or, __LINE__);


	printf("\033[1;37m======== end %%s =====\033[0m\n\n");


  /* Memes tests avec les %s */

  ft_printf("%d\n", ft_printf("1string 1 %s string 2 %s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("1string 1 %s string 2 %s\n\n", "toto", "bonjour"));

  ft_printf("%d\n", ft_printf("2string 1 %   s string 2 % s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("3string 1 %   s string 2 % s\n\n", "toto", "bonjour"));

  ft_printf("%d\n", ft_printf("4string 1 %12s string 2 %12s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("4string 1 %12s string 2 %12s\n\n", "toto", "bonjour"));

  ft_printf("%d\n", ft_printf("4string 1 %-12s string 2 %-12s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("4string 1 %-12s string 2 %-12s\n\n", "toto", "bonjour"));

  ft_printf("%d\n", ft_printf("5string 1 %0s string 2 %0s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("5string 1 %0s string 2 %0s\n\n", "toto", "bonjour"));

  ft_printf("%d\n", ft_printf("6string 1 %012s string 2 %012s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("6string 1 %012s string 2 %012s\n\n", "toto", "bonjour"));

  ft_printf("%d\n", ft_printf("7string 1 %-012s string 2 %012s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("7string 1 %-012s string 2 %012s\n\n", "toto", "bonjour"));


  ft_printf("%d\n", ft_printf("12string 1 %-+5s string 2 %-+5s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("12string 1 %-+5s string 2 %-+5s\n\n", "toto", "bonjour"));

  ft_printf("%d\n", ft_printf("13string 1 %-+05s string 2 %-+05s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("13string 1 %-+05s string 2 %-+05s\n\n", "toto", "bonjour"));

  ft_printf("%d\n", ft_printf("14string 1 %+-5s string 2 %+-5s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("14string 1 %+-5s string 2 %+-5s\n\n", "toto", "bonjour"));

  ft_printf("%d\n", ft_printf("15string 1 %.s string 2 %.s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("15string 1 %.s string 2 %.s\n\n", "toto", "bonjour"));

  ft_printf("%d\n", ft_printf("16string 1 %.6s string 2 %.6s\n", "toto", "bonjour"));
  printf("%d\n\n", printf("16string 1 %.6s string 2 %.6s\n\n", "toto", "bonjour"));


  	mr = ft_printf("MINE>\t[%5.4s]\n", "ok");
  	or = printf(   "ORIG>\t[%5.4s]\n", "ok");
  	ft_print_result(mr, or, __LINE__);

  	mr = ft_printf("MINE>\t[%-5.4s]\n", "ok");
  	or = printf(   "ORIG>\t[%-5.4s]\n", "ok");
  	ft_print_result(mr, or, __LINE__);


  mr = ft_printf("MINE>\t[%5.2s] is a string\n", "");
  or = printf("ORIG>\t[%5.2s] is a string\n", "");
  ft_print_result(mr, or, __LINE__);

  mr = ft_printf("MINE>\t[%-5.2s] is a string\n", "");
  or = printf("ORIG>\t[%-5.2s] is a string\n", "");
  ft_print_result(mr, or, __LINE__);

  mr = ft_printf("MINE>\t[%5.2s] is a string\n", "this");
  or = printf("ORIG>\t[%5.2s] is a string\n", "this");
  ft_print_result(mr, or, __LINE__);

  mr = ft_printf("MINE>\t[%-5.2s] is a string\n", "this");
  or = printf("ORIG>\t[%-5.2s] is a string\n", "this");
  ft_print_result(mr, or, __LINE__);


    return (0);
}
