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

	printf("\033[1;37m======== %%x and %%X ========\033[0m\n");

	mr = ft_printf("MINE>\t[%x]\n", 16);
	or = printf("ORIG>\t[%x]\n", 16);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%x]\n", 2048);
	or = printf("ORIG>\t[%x]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%x]\n", 16777215);
	or = printf("ORIG>\t[%x]\n", 16777215);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%X]\n", 6777215);
	or = printf("ORIG>\t[%X]\n", 6777215);
	ft_print_result(mr, or, __LINE__);
//4
	mr = ft_printf("MINE>\t[%#x]\n", 1677215);
	or = printf("ORIG>\t[%#x]\n", 1677215);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#X]\n", 1677725);
	or = printf("ORIG>\t[%#X]\n", 1677725);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#+x]\n", 1777215);
	or = printf("ORIG>\t[%#+x]\n", 1777215);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#-X]\n", 16215);
	or = printf("ORIG>\t[%#-X]\n", 16215);
	ft_print_result(mr, or, __LINE__);

	printf("\n\033[1;37m=[HARD]= %%x and %%X ========\033[0m\n\n");
//8
	mr = ft_printf("MINE>\t[%#+9x]\n", 177215);
	or = printf("ORIG>\t[%#+9x]\n", 177215);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#-15X]\n", 167715);
	or = printf(   "ORIG>\t[%#-15X]\n", 167715);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%# +9x]\n", 17215);
	or = printf(   "ORIG>\t[%# +9x]\n", 17215);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#'-15X]\n", 167715);
	or = printf(   "ORIG>\t[%#'-15X]\n", 167715);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%020x]\n", 1254789652);
	or = printf(   "ORIG>\t[%020x]\n", 1254789652);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#020x]\n", 1254789652);
	or = printf(   "ORIG>\t[%#020x]\n", 1254789652);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#+020x]\n", 1254789652);
	or = printf(   "ORIG>\t[%#+020x]\n", 1254789652);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#+20x]\n", 1254789652);
	or = printf(   "ORIG>\t[%#+20x]\n", 1254789652);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#+20x]\n", 0xffffff);
	or = printf(   "ORIG>\t[%#+20x]\n", 0xffffff);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#+20x]\n", 0xffffff);
	or = printf(   "ORIG>\t[%#+20x]\n", 0xffffff);
	ft_print_result(mr, or, __LINE__);

	printf("\033[1;37m======== end %%x and %%X ====\033[0m\n\n");
mr = ft_printf("MINE>\t[%#'-*X]\n", 18, 167715);
	or = printf(   "ORIG>\t[%#'-*X]\n", 18, 167715);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#+*x]\n", 25, 1777215);
	or = printf("ORIG>\t[%#+*x]\n", 25, 1777215);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#-*X]\n", 25, 16215);
	or = printf("ORIG>\t[%#-*X]\n", 25, 16215);
	ft_print_result(mr, or, __LINE__);
mr = ft_printf("MINE>\t[%5.4x]\n", 0xfaf);
	or = printf(   "ORIG>\t[%5.4x]\n", 0xfaf);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%5.4X]\n", 0xfaf);
	or = printf(   "ORIG>\t[%5.4X]\n", 0xfaf);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5.4X]\n", 0xfaf);
	or = printf(   "ORIG>\t[%-5.4X]\n", 0xfaf);
	ft_print_result(mr, or, __LINE__);
  /* Memes tests avec les %x */

  ft_printf("%d\n", ft_printf("1hexa 1 %x hexa 2 %x\n", 42, -42));
  printf("%d\n\n", printf("1hexa 1 %x hexa 2 %x\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("2hexa 1 %   x hexa 2 % x\n", 42, -42));
  printf("%d\n\n", printf("3hexa 1 %   x hexa 2 % x\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("4hexa 1 %12x hexa 2 %12x\n", 42, -42));
  printf("%d\n\n", printf("4hexa 1 %12x hexa 2 %12x\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("4hexa 1 %-12x hexa 2 %-12x\n", 42, -42));
  printf("%d\n\n", printf("4hexa 1 %-12x hexa 2 %-12x\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("5hexa 1 %0x hexa 2 %0x\n", 42, -42));
  printf("%d\n\n", printf("5hexa 1 %0x hexa 2 %0x\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("6hexa 1 %012x hexa 2 %012x\n", 42, -42));
  printf("%d\n\n", printf("6hexa 1 %012x hexa 2 %012x\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("7hexa 1 %-012x hexa 2 %012x\n", 42, -42));
  printf("%d\n\n", printf("7hexa 1 %-012x hexa 2 %012x\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("8hexa 1 %*x hexa 2 %*x\n", 42, 6, 6, 6));
  printf("%d\n\n", printf("8hexa 1 %*x hexa 2 %*x\n\n", 42, 6, 6, 6));

  ft_printf("%d\n", ft_printf("9hexa 1 %+x hexa 2 %+x\n", 42, 6, -42, 6));
  printf("%d\n\n", printf("9hexa 1 %+x hexa 2 %+x\n\n", 42, 6, -42, 6));

  ft_printf("%d\n", ft_printf("10hexa 1 %+12x hexa 2 %+12x\n", 42, 6, -42, 6));
  printf("%d\n\n", printf("10hexa 1 %+12x hexa 2 %+12x\n\n", 42, 6, -42, 6));

  ft_printf("%d\n", ft_printf("11hexa 1 %*12x hexa 2 %*12x\n", 42, -6, -42, 6));
  printf("%d\n\n", printf("11hexa 1 %*12x hexa 2 %*12x\n\n", 42, -6, -42, 6));

  ft_printf("%d\n", ft_printf("12hexa 1 %-+5x hexa 2 %-+5x\n", 42, -42));
  printf("%d\n\n", printf("12hexa 1 %-+5x hexa 2 %-+5x\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("13hexa 1 %-+05x hexa 2 %-+05x\n", 42, -42));
  printf("%d\n\n", printf("13hexa 1 %-+05x hexa 2 %-+05x\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("14hexa 1 %+-5x hexa 2 %+-5x\n", 42, -42));
  printf("%d\n\n", printf("14hexa 1 %+-5x hexa 2 %+-5x\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("15hexa 1 %.x hexa 2 %.x\n", 42, -42));
  printf("%d\n\n", printf("15hexa 1 %.x hexa 2 %.x\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("16hexa 1 %.6x hexa 2 %.6x\n", 42, -42));
  printf("%d\n\n", printf("16hexa 1 %.6x hexa 2 %.6x\n\n", 42, -42));

  /* Memes tests avec les %X */

  ft_printf("%d\n", ft_printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42));
  printf("%d\n\n", printf("1hexa-maj 1 %X hexa-maj 2 %X\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("2hexa-maj 1 %   X hexa-maj 2 % X\n", 42, -42));
  printf("%d\n\n", printf("3hexa-maj 1 %   X hexa-maj 2 % X\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n", 42, -42));
  printf("%d\n\n", printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42));
  printf("%d\n\n", printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42));
  printf("%d\n\n", printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42));
  printf("%d\n\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("7hexa-maj 1 %-012X hexa-maj 2 %012X\n", 42, -42));
  printf("%d\n\n", printf("7hexa-maj 1 %-012X hexa-maj 2 %012X\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n", 42, 6, 6, 6));
  printf("%d\n\n", printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n\n", 42, 6, 6, 6));

  ft_printf("%d\n", ft_printf("9hexa-maj 1 %+X hexa-maj 2 %+X\n", 42, 6, -42, 6));
  printf("%d\n\n", printf("9hexa-maj 1 %+X hexa-maj 2 %+X\n\n", 42, 6, -42, 6));

  ft_printf("%d\n", ft_printf("10hexa-maj 1 %+12X hexa-maj 2 %+12X\n", 42, 6, -42, 6));
  printf("%d\n\n", printf("10hexa-maj 1 %+12X hexa-maj 2 %+12X\n\n", 42, 6, -42, 6));

  ft_printf("%d\n", ft_printf("11hexa-maj 1 %*12X hexa-maj 2 %*12X\n", 42, -6, -42, 6));
  printf("%d\n\n", printf("11hexa-maj 1 %*12X hexa-maj 2 %*12X\n\n", 42, -6, -42, 6));

  ft_printf("%d\n", ft_printf("12hexa-maj 1 %-+5X hexa-maj 2 %-+5X\n", 42, -42));
  printf("%d\n\n", printf("12hexa-maj 1 %-+5X hexa-maj 2 %-+5X\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("13hexa-maj 1 %-+05X hexa-maj 2 %-+05X\n", 42, -42));
  printf("%d\n\n", printf("13hexa-maj 1 %-+05X hexa-maj 2 %-+05X\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("14hexa-maj 1 %+-5X hexa-maj 2 %+-5X\n", 42, -42));
  printf("%d\n\n", printf("14hexa-maj 1 %+-5X hexa-maj 2 %+-5X\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n", 42, -42));
  printf("%d\n\n", printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n\n", 42, -42));

  ft_printf("%d\n", ft_printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n", 42, -42));
  printf("%d\n\n", printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n\n", 42, -42));
  ft_printf("%d\n", ft_printf("%#5x\n", 42));
  printf("%d\n\n", printf("%#5x\n", 42));

mr = ft_printf("MINE>\t[%x]\n", 4294967296 );
	or = printf("ORIG>\t[%x]\n", 4294967296);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%lx]\n", 4294967296);
	or = printf("ORIG>\t[%lx]\n", 4294967296);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%llx]\n", 4294967296);
	or = printf("ORIG>\t[%llx]\n", 4294967296);
	ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>\t[%x]\n", 0 );
	or = printf("ORIG>\t[%x]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#.x], [%#.0x]\n", 1, 1);
	or = printf("ORIG>\t[%#.x], [%#.0x]\n", 1, 1);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#.x], [%#.0x]\n", 0, 0);
	or = printf("ORIG>\t[%#.x], [%#.0x]\n", 0, 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#5.2x], [%#5.0x]\n", 1, 1);
	or = printf("ORIG>\t[%#5.2x], [%#5.0x]\n", 1, 1);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#5.2x], [%#5.0x]\n", 0, 0);
	or = printf("ORIG>\t[%#5.2x], [%#5.0x]\n", 0, 0);
	ft_print_result(mr, or, __LINE__);
  return (0);
}
