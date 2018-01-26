/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:45:27 by djoly             #+#    #+#             */
/*   Updated: 2016/02/24 16:53:33 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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



		printf("\033[1;37m======== %%u ========\033[0m\n");

		mr = ft_printf("MINE>\t[%+u]\n", 650);
		or = printf("ORIG>\t[%+u]\n", 650);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%u]\n", 4000000000);
		or = printf("ORIG>\t[%u]\n", 4000000000);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%u]\n", -650);
		or = printf("ORIG>\t[%u]\n", -650);
		ft_print_result(mr, or, __LINE__);
//3
		mr = ft_printf("MINE>\t[%10u]\n", 12345);
		or = printf(   "ORIG>\t[%10u]\n", 12345);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-10u]\n", 12345);
		or = printf(   "ORIG>\t[%+-10u]\n", 12345);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+10u]\n", 12345);
		or = printf(   "ORIG>\t[%+10u]\n", 12345);
		ft_print_result(mr, or, __LINE__);

//6
			mr = ft_printf("MINE>\t[%5.4u]\n", 10);
			or = printf(   "ORIG>\t[%5.4u]\n", 10);
			ft_print_result(mr, or, __LINE__);

			mr = ft_printf("MINE>\t[%-8.4u]\n", 10);
			or = printf(   "ORIG>\t[%-8.4u]\n", 10);
			ft_print_result(mr, or, __LINE__);


		printf("\033[1;37m======== end %%u =====\033[0m\n\n");


		  /* Memes tests avec les %u */

		  ft_printf("%d\n", ft_printf("1unsigned 1 %u unsigned 2 %u\n", 42, -42));
		  printf("%d\n\n", printf("1unsigned 1 %u unsigned 2 %u\n", 42, -42));

		  ft_printf("%d\n", ft_printf("2unsigned 1 %   u unsigned 2 % u\n", 42, -42));
		  printf("%d\n\n", printf("3unsigned 1 %   u unsigned 2 % u\n", 42, -42));

		  ft_printf("%d\n", ft_printf("4unsigned 1 %12u unsigned 2 %12u\n", 42, -42));
		  printf("%d\n\n", printf("4unsigned 1 %12u unsigned 2 %12u\n", 42, -42));

		  ft_printf("%d\n", ft_printf("4unsigned 1 %-12u unsigned 2 %-12u\n", 42, -42));
		  printf("%d\n\n", printf("4unsigned 1 %-12u unsigned 2 %-12u\n", 42, -42));

		  ft_printf("%d\n", ft_printf("5unsigned 1 %0u unsigned 2 %0u\n", 42, -42));
		  printf("%d\n\n", printf("5unsigned 1 %0u unsigned 2 %0u\n", 42, -42));
//6
		  ft_printf("%d\n", ft_printf("6unsigned 1 %012u unsigned 2 %012u\n", 42, -42));
		  printf("%d\n\n", printf("6unsigned 1 %012u unsigned 2 %012u\n", 42, -42));

		  ft_printf("%d\n", ft_printf("7unsigned 1 %-012u unsigned 2 %012u\n", 42, -42));
		  printf("%d\n\n", printf("7unsigned 1 %-012u unsigned 2 %012u\n", 42, -42));

		  ft_printf("%d\n", ft_printf("8unsigned 1 %*u unsigned 2 %*u\n", 42, 6, 6, 6));
		  printf("%d\n\n", printf("8unsigned 1 %*u unsigned 2 %*u\n", 42, 6, 6, 6));

		  ft_printf("%d\n", ft_printf("9unsigned 1 %+u unsigned 2 %+u\n", 42, 6, -42, 6));
		  printf("%d\n\n", printf("9unsigned 1 %+u unsigned 2 %+u\n", 42, 6, -42, 6));

		  ft_printf("%d\n", ft_printf("10unsigned 1 %+12u unsigned 2 %+12u\n", 42, 6, -42, 6));
		  printf("%d\n\n", printf("10unsigned 1 %+12u unsigned 2 %+12u\n", 42, 6, -42, 6));

		  ft_printf("%d\n", ft_printf("11unsigned 1 %*12u unsigned 2 %*12u\n", 42, -6, -42, 6));
		  printf("%d\n\n", printf("11unsigned 1 %*12u unsigned 2 %*12u\n", 42, -6, -42, 6));
//12
		  ft_printf("%d\n", ft_printf("12unsigned 1 |%-+5u| unsigned 2 |%-+5u|\n", 42, -42));
		  printf("%d\n\n", printf("12unsigned 1 |%-+5u| unsigned 2 |%-+5u|\n", 42, -42));

		  ft_printf("%d\n", ft_printf("13unsigned 1 |%-+05u| unsigned 2 |%-+05u|\n", 42, -42));
		  printf("%d\n\n", printf("13unsigned 1 |%-+05u| unsigned 2 |%-+05u|\n", 42, -42));

		  ft_printf("%d\n", ft_printf("14unsigned 1 %+-5u unsigned 2 %+-5u\n", 42, -42));
		  printf("%d\n\n", printf("14unsigned 1 %+-5u unsigned 2 %+-5u\n", 42, -42));

		  ft_printf("%d\n", ft_printf("15unsigned 1 %.u unsigned 2 %.u\n", 42, -42));
		  printf("%d\n\n", printf("15unsigned 1 %.u unsigned 2 %.u\n", 42, -42));
//16
		  ft_printf("%d\n", ft_printf("16unsigned 1 %.6u unsigned 2 %.6u\n", 42, -42));
		  printf("%d\n\n", printf("16unsigned 1 %.6u unsigned 2 %.6u\n", 42, -42));


		    ft_printf("%d\n", ft_printf("11unsigned 1 %*12u unsigned 2 %*12u unsigned 3 %*12u\n", 42, -6, -42, 6, 12, 6));
		    printf("%d\n\n", printf("11unsigned 1 %*12u unsigned 2 %*12u unsigned 3 %*12u\n", 42, -6, -42, 6, 12, 6));

			mr = ft_printf("MINE>\t[%5u]\n", 4294967295);
			or = printf(   "ORIG>\t[%5u]\n", 4294967295);
			ft_print_result(mr, or, __LINE__);

			mr = ft_printf("MINE>\t[%lu]\n", 4294967295);
			or = printf(   "ORIG>\t[%lu]\n", 4294967295);
			ft_print_result(mr, or, __LINE__);

			mr = ft_printf("MINE>\t[%lu]\n", -42);
			or = printf(   "ORIG>\t[%lu]\n", -42);
			ft_print_result(mr, or, __LINE__);
//11
			mr = ft_printf("MINE>\t[%llu]\n", 4999999999);
			or = printf(   "ORIG>\t[%llu]\n", 4999999999);
			ft_print_result(mr, or, __LINE__);

			mr = ft_printf("MINE>\t[%ju]\n", 4999999999);
			or = printf(   "ORIG>\t[%ju]\n", 4999999999);
			ft_print_result(mr, or, __LINE__);

			mr = ft_printf("MINE>\t[%hU]\n", 4294967296);
			or = printf(   "ORIG>\t[%hU]\n", 4294967296);
			ft_print_result(mr, or, __LINE__);

			mr = ft_printf("MINE>\t[%U]\n", 4294967296);
			or = printf(   "ORIG>\t[%U]\n", 4294967296);
			ft_print_result(mr, or, __LINE__);


			mr = ft_printf("MINE>\t[%Z]\n");
			or = printf(   "ORIG>\t[%Z]\n");
			ft_print_result(mr, or, __LINE__);




			return (0);
		}
