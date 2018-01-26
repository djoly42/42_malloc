#include "ft_printf.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
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
		printf("\033[1;37m======== %%o ========\033[0m\n");

mr = ft_printf("MINE>\t[%o]\n", 1);
	or = printf("ORIG>\t[%o]\n", 1);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%o]\n", 2);
	or = printf("ORIG>\t[%o]\n", 2);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%o]\n", 8);
	or = printf("ORIG>\t[%o]\n", 8);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%o]\n", 9);
	or = printf("ORIG>\t[%o]\n", 9);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%o]\n", 10);
	or = printf("ORIG>\t[%o]\n", 10);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%o]\n", 11);
	or = printf("ORIG>\t[%o]\n", 11);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%o]\n", -1);
	or = printf("ORIG>\t[%o]\n", -1);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%o]\n", -2);
	or = printf("ORIG>\t[%o]\n", -2);
	ft_print_result(mr, or, __LINE__);

    mr = ft_printf("MINE>\t[%o]\n", 2048);
	or = printf("ORIG>\t[%o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

    mr = ft_printf("MINE>\t[%o]\n", 2048);
	or = printf("ORIG>\t[%o]\n", 2048);
	ft_print_result(mr, or, __LINE__);






//10
	mr = ft_printf("MINE>\t[%o]\n", 2048);
	or = printf("ORIG>\t[%o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

    mr = ft_printf("MINE>\t[% o]\n", 777);
	or = printf("ORIG>\t[% o]\n", 777);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+o]\n", 128);
	or = printf("ORIG>\t[%+o]\n", 128);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-o]\n", 48);
	or = printf("ORIG>\t[%-o]\n", 48);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+5o]\n", 10);
	or = printf("ORIG>\t[%+5o]\n", 10);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5o]\n", 2048);
	or = printf("ORIG>\t[%-5o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+10o]\n", 2048);
	or = printf("ORIG>\t[%+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%010o]\n", 2048);
	or = printf("ORIG>\t[%010o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-+10o]\n", 2048);
	or = printf("ORIG>\t[%-+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
	or = printf("ORIG>\t[%-0+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);
//20
	mr = ft_printf("MINE>\t[%#o]\n", 48);
	or = printf("ORIG>\t[%#o]\n", 48);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#+10o]\n", 2048);
	or = printf("ORIG>\t[%#+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
	or = printf("ORIG>\t[%-0+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
	or = printf("ORIG>\t[%-0+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

//24
	mr = ft_printf("MINE>\t[%#-0+10o]\n", 2048);
	or = printf("ORIG>\t[%#-0+10o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0#+3o]\n", 2048);
	or = printf("ORIG>\t[%-0#+3o]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%o]\n", 02047);
	or = printf("ORIG>\t[%o]\n", 02047);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%o]\n", 02047);
	or = printf("ORIG>\t[%o]\n", 02047);
	ft_print_result(mr, or, __LINE__);

	printf("\033[1;37m======== end %%o =====\033[0m\n\n");


	mr = ft_printf("MINE>\t[%5.4o]\n", 10);
	or = printf(   "ORIG>\t[%5.4o]\n", 10);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-8.6o]\n", 0456);
	or = printf(   "ORIG>\t[%-8.6o]\n", 0456);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%18.12o]\n", 0777777777);
	or = printf(   "ORIG>\t[%18.12o]\n", 0777777777);
	ft_print_result(mr, or, __LINE__);


  /* Memes tests avec les %o */

  ft_printf("%d\n", ft_printf("1octal 1 %o octal 2 %o\n", 42, -42));
  printf("%d\n\n", printf("1octal 1 %o octal 2 %o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("2octal 1 %   o octal 2 % o\n", 42, -42));
  printf("%d\n\n", printf("3octal 1 %   o octal 2 % o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("4octal 1 %12o octal 2 %12o\n", 42, -42));
  printf("%d\n\n", printf("4octal 1 %12o octal 2 %12o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("4octal 1 %-12o octal 2 %-12o\n", 42, -42));
  printf("%d\n\n", printf("4octal 1 %-12o octal 2 %-12o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("5octal 1 %0o octal 2 %0o\n", 42, -42));
  printf("%d\n\n", printf("5octal 1 %0o octal 2 %0o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("6octal 1 %012o octal 2 %012o\n", 42, -42));
  printf("%d\n\n", printf("6octal 1 %012o octal 2 %012o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("7octal 1 %-012o octal 2 %012o\n", 42, -42));
  printf("%d\n\n", printf("7octal 1 %-012o octal 2 %012o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("8octal 1 %*o octal 2 %*o\n", 42, 6, 6, 6));
  printf("%d\n\n", printf("8octal 1 %*o octal 2 %*o\n\n", 42, 6, 6, 6));

  ft_printf("%d\n", ft_printf("9octal 1 %+o octal 2 %+o\n", 42, 6, -42, 6));
  printf("%d\n\n", printf("9octal 1 %+o octal 2 %+o\n\n", 42, 6, -42, 6));

  ft_printf("%d\n", ft_printf("10octal 1 %+12o octal 2 %+12o\n", 42, 6, -42, 6));
  printf("%d\n\n", printf("10octal 1 %+12o octal 2 %+12o\n\n", 42, 6, -42, 6));

  ft_printf("%d\n", ft_printf("11octal 1 %*12o octal 2 %*12o\n", 42, -6, -42, 6));
  printf("%d\n\n", printf("11octal 1 %*12o octal 2 %*12o\n\n", 42, -6, -42, 6));

  ft_printf("%d\n", ft_printf("12octal 1 %-+5o octal 2 %-+5o\n", 42, -42));
  printf("%d\n\n", printf("12octal 1 %-+5o octal 2 %-+5o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("13octal 1 %-+05o octal 2 %-+05o\n", 42, -42));
  printf("%d\n\n", printf("13octal 1 %-+05o octal 2 %-+05o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("14octal 1 %+-5o octal 2 %+-5o\n", 42, -42));
  printf("%d\n\n", printf("14octal 1 %+-5o octal 2 %+-5o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("15octal 1 %.o octal 2 %.o\n", 42, -42));
  printf("%d\n\n", printf("15octal 1 %.o octal 2 %.o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("16octal 1 %.6o octal 2 %.6o\n", 42, -42));
  printf("%d\n\n", printf("16octal 1 %.6o octal 2 %.6o\n\n", 42, -42));

  /* Memes tests avec les %o */

  ft_printf("%d\n", ft_printf("1octal 1 %o octal 2 %o\n", 42, -42));
  printf("%d\n\n", printf("1octal 1 %o octal 2 %o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("2octal 1 %   o octal 2 % o\n", 42, -42));
  printf("%d\n\n", printf("3octal 1 %   o octal 2 % o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("4octal 1 %12o octal 2 %12o\n", 42, -42));
  printf("%d\n\n", printf("4octal 1 %12o octal 2 %12o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("4octal 1 %-12o octal 2 %-12o\n", 42, -42));
  printf("%d\n\n", printf("4octal 1 %-12o octal 2 %-12o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("5octal 1 %0o octal 2 %0o\n", 42, -42));
  printf("%d\n\n", printf("5octal 1 %0o octal 2 %0o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("6octal 1 %012o octal 2 %012o\n", 42, -42));
  printf("%d\n\n", printf("6octal 1 %012o octal 2 %012o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("7octal 1 %-012o octal 2 %012o\n", 42, -42));
  printf("%d\n\n", printf("7octal 1 %-012o octal 2 %012o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("8octal 1 %*o octal 2 %*o\n", 42, 6, 6, 6));
  printf("%d\n\n", printf("8octal 1 %*o octal 2 %*o\n\n", 42, 6, 6, 6));

  ft_printf("%d\n", ft_printf("9octal 1 %+o octal 2 %+o\n", 42, 6, -42, 6));
  printf("%d\n\n", printf("9octal 1 %+o octal 2 %+o\n\n", 42, 6, -42, 6));

  ft_printf("%d\n", ft_printf("10octal 1 %+12o octal 2 %+12o\n", 42, 6, -42, 6));
  printf("%d\n\n", printf("10octal 1 %+12o octal 2 %+12o\n\n", 42, 6, -42, 6));

  ft_printf("%d\n", ft_printf("11octal 1 %*12o octal 2 %*12o\n", 42, -6, -42, 6));
  printf("%d\n\n", printf("11octal 1 %*12o octal 2 %*12o\n\n", 42, -6, -42, 6));

  ft_printf("%d\n", ft_printf("12octal 1 %-+5o octal 2 %-+5o\n", 42, -42));
  printf("%d\n\n", printf("12octal 1 %-+5o octal 2 %-+5o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("13octal 1 %-+05o octal 2 %-+05o\n", 42, -42));
  printf("%d\n\n", printf("13octal 1 %-+05o octal 2 %-+05o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("14octal 1 %+-5o octal 2 %+-5o\n", 42, -42));
  printf("%d\n\n", printf("14octal 1 %+-5o octal 2 %+-5o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("15octal 1 %.o octal 2 %.o\n", 42, -42));
  printf("%d\n\n", printf("15octal 1 %.o octal 2 %.o\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("16octal 1 %.6o octal 2 %.6o\n", 42, -42));
  printf("%d\n\n", printf("16octal 1 %.6o octal 2 %.6o\n\n", 42, -42));
//31
  mr = ft_printf("MINE>\t[%-5.10o]\n", 2500);
  	or = printf("ORIG>\t[%-5.10o]\n", 2500);
  	ft_print_result(mr, or, __LINE__);
//32
  mr = ft_printf("MINE>\t[%.o], [%.0o]\n", 0, 0);
  	or = printf("ORIG>\t[%.o], [%.0o]\n", 0, 0);
  	ft_print_result(mr, or, __LINE__);
//33
	mr = ft_printf("MINE>\t[%5.o], [%5.0o]\n", 0, 0);
    	or = printf("ORIG>\t[%5.o], [%5.0o]\n", 0, 0);
    	ft_print_result(mr, or, __LINE__);
//34
    mr = ft_printf("MINE>\t[%#.o], [%#.0o]\n", 0, 0);
    	or = printf("ORIG>\t[%#.o], [%#.0o]\n", 0, 0);
    	ft_print_result(mr, or, __LINE__);
//35
	mr = ft_printf("MINE>\t[%#.o], [%#.0o]\n", 1, 1);
	or = printf("ORIG>\t[%#.o], [%#.0o]\n", 1, 1);
	ft_print_result(mr, or, __LINE__);
//36
	mr = ft_printf("MINE>\t[%#3.o], [%#3.0o]\n", 1, 1);
	or = printf("ORIG>\t[%#3.o], [%#3.0o]\n", 1, 1);
	ft_print_result(mr, or, __LINE__);
//37
	mr = ft_printf("MINE>\t[%jo], [%jo]\n", 0, ULLONG_MAX);
	or = printf("ORIG>\t[%jo], [%jo]\n", 0, ULLONG_MAX);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%O], [%O]\n", 0, LONG_MAX);
	or = printf("ORIG>\t[%O], [%O]\n", 0, LONG_MAX);
	ft_print_result(mr, or, __LINE__);

    return (0);
}
