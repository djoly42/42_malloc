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
  ft_printf("%d\n", ft_printf("This is a float : %f\n", 45.236));
  ft_printf("%d\n", printf("This is a float : %f\n\n", 45.236));

  ft_printf("%d\n", ft_printf("This is a float : %.3f\n", 45.236));
  ft_printf("%d\n", printf("This is a float : %.3f\n\n", 45.236));

  ft_printf("%d\n", ft_printf("This is a float : %3f\n", 45.236));
  ft_printf("%d\n",   printf("This is a float : %3f\n\n", 45.236));

  ft_printf("%d\n", ft_printf("This is a float : %f\n", -45.236));
  ft_printf("%d\n", printf("This is a float : %f\n\n", -45.236));

  ft_printf("%d\n", ft_printf("This is a float : %.3f\n", -45.236));
  ft_printf("%d\n", printf("This is a float : %.3f\n\n", -45.236));

  ft_printf("%d\n", ft_printf("This is a float : %3f\n", -45.236));
  ft_printf("%d\n", printf("This is a float : %3f\n\n", -45.236));

  ft_printf("This is a float : %f\n", 0.00025);
  printf("This is a float : %f\n\n", 0.00025);

  ft_printf("This is a float : %.3f\n", 0.00025);
  printf("This is a float : %.3f\n\n", 0.00025);

  ft_printf("This is a float : %3f\n", 0.00025);
  printf("This is a float : %3f\n\n", 0.00025);

  ft_printf("This is a float : %f\n", -0.00025);
  printf("This is a float : %f\n\n", -0.00025);

  ft_printf("This is a float : %.3f\n", -0.00025);
  printf("This is a float : %.3f\n\n", -0.00025);

  ft_printf("This is a float : %3f\n", -0.00025);
  printf("This is a float : %3f\n\n", -0.00025);
return (0);
}

