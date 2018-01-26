/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainD.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Djoly <Djoly@stuDent.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   CreateD: 2016/01/29 17:04:56 by Djoly             #+#    #+#             */
/*   UpDateD: 2016/02/26 18:28:05 by Djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
	printf("\033[1;37m======== %%D ========\033[0m\n");

	mr = ft_printf("MINE>\t[%D]\n", 650);
	or = printf("ORIG>\t[%D]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%D]\n", -650);
	or = printf("ORIG>\t[%D]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+D]\n", 650);
	or = printf("ORIG>\t[%+D]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+1D]\n", 2048);
	or = printf("ORIG>\t[%+1D]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+10D]\n", 650);
	or = printf("ORIG>\t[%+10D]\n", 650);
	ft_print_result(mr, or, __LINE__);
//5
	mr = ft_printf("MINE>\t[%+10D]\n", -650);
	or = printf("ORIG>\t[%+10D]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%10D]\n", 650);
	or = printf("ORIG>\t[%10D]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-10D]\n", 650);
	or = printf("ORIG>\t[%-10D]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5D]\n", 650);
	or = printf("ORIG>\t[%-5D]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% D]\n", 650);
	or = printf("ORIG>\t[% D]\n", 650);
	ft_print_result(mr, or, __LINE__);
//10
	mr = ft_printf("MINE>\t[% 5D]\n", 650);
	or = printf("ORIG>\t[% 5D]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% D]\n", -650);
	or = printf("ORIG>\t[% D]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% 5D]\n", -650);
	or = printf("ORIG>\t[% 5D]\n", -650);
	ft_print_result(mr, or, __LINE__);
//13
	mr = ft_printf("MINE>\t[%08D]\n", -650);
	or = printf("ORIG>\t[%08D]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+06D]\n", -650);
	or = printf("ORIG>\t[%+06D]\n", -650);
	ft_print_result(mr, or, __LINE__);
//15
	mr = ft_printf("MINE>\t[%-05D]\n", -650);
	or = printf("ORIG>\t[%-05D]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-05D]\n", -650);
	or = printf("ORIG>\t[%+-05D]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-09D]\n", -650);
	or = printf("ORIG>\t[%+-09D]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+09D]\n", -650);
	or = printf("ORIG>\t[%+09D]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-1D]\n", -650);
	or = printf("ORIG>\t[%+-1D]\n", -650);
	ft_print_result(mr, or, __LINE__);
//20
	mr = ft_printf("MINE>\t[%+01D]\n", -650);
	or = printf("ORIG>\t[%+01D]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%'D]\n", 65000);
	or = printf("ORIG>\t[%'D]\n", 65000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%'D]\n", 6500000);
	or = printf("ORIG>\t[%'D]\n", 6500000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+'D]\n", 65000);
	or = printf("ORIG>\t[%+'D]\n", 65000);
	ft_print_result(mr, or, __LINE__);


	mr = ft_printf("MINE>\t[%llD]\n", 9223372036854775807);
	or = printf(   "ORIG>\t[%llD]\n", 9223372036854775807);
	ft_print_result(mr, or, __LINE__);

//25
	mr = ft_printf("MINE>\t[%*D]\n", 10, 999);
	or = printf(   "ORIG>\t[%*D]\n", 10, 999);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%*D]\n", -10, 999);
	or = printf(   "ORIG>\t[%*D]\n", -10, 999);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%*D]\n", 999);
	or = printf(   "ORIG>\t[%*D]\n", 999);
	ft_print_result(mr, or, __LINE__);


	mr = ft_printf("MINE>\t[%*2$D]\n", 10, 40);
	or = printf(   "ORIG>\t[%*2$D]\n", 10, 40);
	ft_print_result(mr, or, __LINE__);

//Crashtest
	printf("\033[1;37m====  CRASH TEST ===\033[0m\n");
//29
	mr = ft_printf("MINE>\t[%D]\n");
	or = printf("ORIG>\t[%D]\n");
	ft_print_result(mr, or, __LINE__);


	mr = ft_printf("MINE>\t[-10+D s : {%+-10D} {%s}]\n", 12345, "argl");
	or = printf(   "ORIG>\t[-10+D s : {%+-10D} {%s}]\n", 12345, "argl");
	ft_print_result(mr, or, __LINE__);



	printf("\033[1;37m==== %%D + moDifiers ===\033[0m\n");
//31
	mr = ft_printf("MINE>\t[%hhD]\n", 123456789);
	or = printf(   "ORIG>\t[%hhD]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%hD]\n", 123456789);
	or = printf(   "ORIG>\t[%hD]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%llD]\n", 123456789);
	or = printf(   "ORIG>\t[%llD]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%lD]\n", 123456789);
	or = printf(   "ORIG>\t[%lD]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%jD]\n", 123456789);
	or = printf(   "ORIG>\t[%jD]\n", 123456789);
	ft_print_result(mr, or, __LINE__);
//36
	mr = ft_printf("MINE>\t[%tD]\n", 123456789);
	or = printf(   "ORIG>\t[%tD]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%zD]\n", 123456789);
	or = printf(   "ORIG>\t[%zD]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	printf("\033[1;37m== EnD %%D + moDifiers ==\033[0m\n\n");












	printf("\033[1;37m==== precision moDifiers ===\033[0m\n");

//38
	mr = ft_printf("MINE>\t[%.4D]\n", 10);
	or = printf(   "ORIG>\t[%.4D]\n", 10);
	ft_print_result(mr, or, __LINE__);
//39
	mr = ft_printf("MINE>\t[%-.4D]\n", 10000);
	or = printf(   "ORIG>\t[%-.4D]\n", 10000);
	ft_print_result(mr, or, __LINE__);
//40
	mr = ft_printf("MINE>\t[%.1D]\n", 10000);
	or = printf(   "ORIG>\t[%.1D]\n", 10000);
	ft_print_result(mr, or, __LINE__);
//41
	mr = ft_printf("MINE>\t[%-.0D]\n", 10000);
	or = printf(   "ORIG>\t[%-.0D]\n", 10000);
	ft_print_result(mr, or, __LINE__);

//42
	mr = ft_printf("MINE>\t[%5.4D]\n", 10);
	or = printf(   "ORIG>\t[%5.4D]\n", 10);
	ft_print_result(mr, or, __LINE__);
//43
	mr = ft_printf("MINE>\t[%-8.4D]\n", 10);
	or = printf(   "ORIG>\t[%-8.4D]\n", 10);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5.4D]\n", 10);
	or = printf(   "ORIG>\t[%-5.4D]\n", 10);
	ft_print_result(mr, or, __LINE__);
//45
	mr = ft_printf("MINE>\t[%-+8.4D]\n", 10);
	or = printf(   "ORIG>\t[%-+8.4D]\n", 10);
	ft_print_result(mr, or, __LINE__);
//46
	mr = ft_printf("MINE>\t[%2.4D]\n", 10000);
	or = printf(   "ORIG>\t[%2.4D]\n", 10000);
	ft_print_result(mr, or, __LINE__);
//47
	mr = ft_printf("MINE>\t[%10.1D]\n", 10000);
	or = printf(   "ORIG>\t[%10.1D]\n", 10000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%4.0D]\n", 10000);
	or = printf(   "ORIG>\t[%4.0D]\n", 10000);
	ft_print_result(mr, or, __LINE__);

	printf("\033[1;37m======== enD %%D =====\033[0m\n\n");





	ft_printf("%D\n", 42);
	printf("%D\n", 42);
	ft_printf("%D%D\n", 42, 41);
	printf("%D%D\n", 42, 41);
	ft_printf("%D%D%D\n", 42, 43, 44);
	printf("%D%D%D\n", 42, 43, 44);
	ft_printf("%lD\n", 2147483647);
	printf("%lD\n", 2147483647);
	ft_printf("%llD\n", 9223372036854775807);
	printf("%llD\n", 9223372036854775807);

	ft_printf("%20.15D\n", 54321);
	printf("%20.15D\n", 54321);
	ft_printf("%-10D\n", 3);
	printf("%-10D\n", 3);
	ft_printf("% D\n", 3);
	printf("% D\n", 3);
	ft_printf("%+D\n", 3);
	printf("%+D\n", 3);
	ft_printf("%010D\n", 1);
	printf("%010D\n", 1);
	ft_printf("%hhD\n", 0);
	printf("%hhD\n", 0);
	ft_printf("%jD\n", 9223372036854775807);
	printf("%jD\n", 9223372036854775807);
	ft_printf("%zD\n", 4294967295);
	printf("%zD\n", 4294967295);
	ft_printf("%\n");
	printf("%\n");




	/* Pourquoi les ft_printf De ft_printf ? Parce que printf renvoie le nombre De caractere qu'il a affiche. Ainsi, on peut verifier si on renvoie bien le bon nombre.
	   Attention ! Il Doit y avoir un caractere De moins sur le ft_printf puisqu'il n'a qu'un \n, pour plus De lisibilite */

//	printf("%D\n\n", ft_printf("%D\n\n", printf("%D\n", 2147483647)));

	/* Verifiez bien les bornes ! Elles ont tenDance a boucler infini ... */

	ft_printf("%D\n", ft_printf("Les bornes :  %D, %D\n", -2147483648, 2147483647));
/*	ft_printf("%D\n", ft_printf("Les bornes :  %u, %u\n", 0, 4294967295));
	ft_printf("%D\n", ft_printf("Les bornes :  %o, %o\n", 0, 4294967295));
	ft_printf("%D\n", ft_printf("Les bornes :  %x, %x\n", 0, 4294967295));
*/
	/* Verification Des Decimals, %i et %D */

	ft_printf("%D\n", ft_printf("1chiffre 1 %D chiffre 2 %D\n", 42, -42));
	printf("%D\n\n", printf("1chiffre 1 %D chiffre 2 %D\n", 42, -42));

	ft_printf("%D\n", ft_printf("2chiffre 1 %   D chiffre 2 % D\n", 42, -42));
	printf("%D\n\n", printf("2chiffre 1 %   D chiffre 2 % D\n", 42, -42));

	ft_printf("%D\n", ft_printf("3chiffre 1 %12D chiffre 2 %12D\n", 42, -42));
	printf("%D\n\n", printf("3chiffre 1 %12D chiffre 2 %12D\n", 42, -42));

	ft_printf("%D\n", ft_printf("4chiffre 1 %-12D chiffre 2 %-12D\n", 42, -42));
	printf("%D\n\n", printf("4chiffre 1 %-12D chiffre 2 %-12D\n", 42, -42));

	ft_printf("%D\n", ft_printf("5chiffre 1 %0D chiffre 2 %0D\n", 42, -42));
	printf("%D\n\n", printf("5chiffre 1 %0D chiffre 2 %0D\n", 42, -42));

	ft_printf("%D\n", ft_printf("6chiffre 1 %012D chiffre 2 %012D\n", 42, -42));
	printf("%D\n\n", printf("6chiffre 1 %012D chiffre 2 %012D\n", 42, -42));

	ft_printf("%D\n", ft_printf("7chiffre 1 %-012D chiffre 2 %012D\n", 42, -42));
	printf("%D\n\n", printf("7chiffre 1 %-012D chiffre 2 %012D\n", 42, -42));

	ft_printf("%D\n", ft_printf("8chiffre 1 %*D chiffre 2 %*D\n", 42, 6, 6, 6));
	printf("%D\n\n", printf("8chiffre 1 %*D chiffre 2 %*D\n", 42, 6, 6, 6));

	ft_printf("%D\n", ft_printf("9chiffre 1 %+D chiffre 2 %+D\n", 42, 6, -42, 6));
	printf("%D\n\n", printf("9chiffre 1 %+D chiffre 2 %+D\n", 42, 6, -42, 6));

	ft_printf("%D\n", ft_printf("10chiffre 1 %+12D chiffre 2 %+12D\n", 42, 6, -42, 6));
	printf("%D\n\n", printf("10chiffre 1 %+12D chiffre 2 %+12D\n", 42, 6, -42, 6));

	ft_printf("%D\n", ft_printf("11chiffre 1 %*12D chiffre 2 %*12D\n", 42, -6, 42, 6));
	printf("%D\n\n", printf("11chiffre 1 %*12D chiffre 2 %*12D\n", 42, -6, 42, 6));

	ft_printf("%D\n", ft_printf("12chiffre 1 |%-+5D| chiffre 2 |%-+5D|\n", 42, -42));
	printf("%D\n\n", printf("12chiffre 1 |%-+5D| chiffre 2 |%-+5D|\n", 42, -42));

	ft_printf("%D\n", ft_printf("13chiffre 1 |%-+05D| chiffre 2 |%-+05D|\n", 42, -42));
	printf("%D\n\n", printf("13chiffre 1 |%-+05D| chiffre 2 |%-+05D|\n", 42, -42));

	ft_printf("%D\n", ft_printf("14chiffre 1 %+-5D chiffre 2 %+-5D\n", 42, -42));
	printf("%D\n\n", printf("14chiffre 1 %+-5D chiffre 2 %+-5D\n", 42, -42));

	ft_printf("%D\n", ft_printf("15chiffre 1 %.D chiffre 2 %.D\n", 42, -42));
	printf("%D\n\n", printf("15chiffre 1 %.D chiffre 2 %.D\n", 42, -42));

	ft_printf("%D\n", ft_printf("16chiffre 1 %.6D chiffre 2 %.6D\n", 42, -42));
	printf("%D\n\n", printf("16chiffre 1 %.6D chiffre 2 %.6D\n", 42, -42));



	/* Test Du %% . Attention, les justifications aussi Doivent etre gerees ! */

	ft_printf("%D\n", ft_printf("%%\n"));
	printf("%D\n\n", printf("%%\n"));




	/* Ces moDificateurs ne sont pas obigatoires (h et l) */

	ft_printf("Test De chiffre sans h : %D, et %D\n", 432767, -432767);
	printf("Test De chiffre sans h : %D, et %D\n", 432767, -432767);
	printf("Test De chiffre avec h : %hD, et %hD\n", 432767, -432767);
	ft_printf("Test De chiffre avec h : %hD, et %hD\n", 432767, -432767);

	ft_printf("Test De cliffre sans l : %D, et %D\n", 32147483647, -32147483647);
	printf("Test De cliffre sans l : %D, et %D\n", 32147483647, -32147483647);
	printf("Test De cliffre avec l : %lD, et %lD\n", 32147483647, -32147483647);
	ft_printf("Test De cliffre avec l : %lD, et %lD\n\n", 32147483647, -32147483647);

	mr = ft_printf("MINE>\t[%+D]\t[% +D]\t[%+ D]\t[%   +D]\t[%  ++D]\n", 0, 0, 42, 42, 42);
	or = printf("ORIG>\t[%+D]\t[% +D]\t[%+ D]\t[%   +D]\t[%  ++D]\n", 0, 0, 42, 42, 42);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%0+5D]\t[%llD]\n", 42, -9223372036854775808);
	or = printf("ORIG>\t[%0+5D]\t[%llD]\n", 42, -9223372036854775808);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%4.15D]\n", 42);
	or = printf("ORIG>\t[%4.15D]\n", 42);
	ft_print_result(mr, or, __LINE__);
//52
	mr = ft_printf("MINE>\t[%+10.5D]\n", 4242);
	or = printf("ORIG>\t[%+10.5D]\n", 4242);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%03.2D]\n", -1);
	or = printf("ORIG>\t[%03.2D]\n", -1);
	ft_print_result(mr, or, __LINE__);

    mr = ft_printf("MINE>\t[%06.2D]\n", -1);
	or = printf("ORIG>\t[%06.2D]\n", -1);
	ft_print_result(mr, or, __LINE__);

    mr = ft_printf("MINE>\t[%.D], [%.0D]\n", 0, 0);
	or = printf("ORIG>\t[%.D], [%.0D]\n", 0, 0);
	ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%5.D], [%5.0D]\n", 1, 1);
		or = printf("ORIG>\t[%5.D], [%5.0D]\n", 1, 1);
		ft_print_result(mr, or, __LINE__);
//test zone
		mr = ft_printf("MINE>\t[%zhD]\n", 4294967296);
		or = printf("ORIG>\t[%zhD]\n", 4294967296);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%hzD]\n", 4294967296);
		or = printf("ORIG>\t[%hzD]\n", 4294967296);
		ft_print_result(mr, or, __LINE__);
//59
		mr = ft_printf("MINE>\t[%jhD]\n", 9223372036854775807);
		or = printf("ORIG>\t[%jhD]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);
//60
		mr = ft_printf("MINE>\t[%hjD]\n", 9223372036854775807);
		or = printf("ORIG>\t[%hjD]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);
//41 61
	mr = ft_printf("MINE>\t[%-.0D]\n", 10000);
	or = printf(   "ORIG>\t[%-.0D]\n", 10000);
	ft_print_result(mr, or, __LINE__);
//41 62
	mr = ft_printf("MINE>\t[%.D]\n", 10000);
	or = printf(   "ORIG>\t[%.D]\n", 10000);
	ft_print_result(mr, or, __LINE__);
//45 63
	mr = ft_printf("MINE>\t[%-+8.4D]\n", 10);
	or = printf(   "ORIG>\t[%-+8.4D]\n", 10);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>03.2D 0\t[%03.2D]\n", 0);
		or = printf("ORIG>03.2D 0\t[%03.2D]\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>03.2D 1\t[%03.2D]\n", 1);
			or = printf("ORIG>03.2D 1\t[%03.2D]\n", 1);
			ft_print_result(mr, or, __LINE__);



	mr = ft_printf("MINE>.10D -42\t[%.10D]\n", -42);
		or = printf("ORIG>.10D -42\t[%.10D]\n", -42);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>D 2147483648\t[%D]\n", 2147483648);
		or = printf("ORIG>D 2147483648\t[%D]\n", 2147483648);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>5.D 5.0D 0 0\t[%5.D], [%5.0D]\n", 0, 0);
		or = printf("ORIG>5.D 5.0D 0 0\t[%5.D], [%5.0D]\n", 0, 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>5.D 5.0D 1 1\t[%5.D], [%5.0D]\n", 1, 1);
		or = printf("ORIG>5.D 5.0D 1 1\t[%5.D], [%5.0D]\n", 1, 1);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>-5+D 42\t[%-5+D]\n", 42);
		or = printf("ORIG>-5+D 42\t[%-5+D]\n", 42);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>-0+5D 42\t[%-0+5D]\n", 42);
		or = printf("ORIG>-0+5D 42\t[%-0+5D]\n", 42);

		mr = ft_printf("MINE>-0+5d 42\t[%-0+5D]\n", LONG_MAX);
		or = printf("ORIG>-0+5d 42\t[%-0+5D]\n", LONG_MAX);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>-0+5d 42\t[%D]\n", LONG_MAX);
		or = printf("ORIG>-0+5d 42\t[%D]\n", LONG_MAX);
		ft_print_result(mr, or, __LINE__);


		mr = ft_printf("MINE>-0+5D 42\t[%-0+5D]\n", LONG_MIN);
		or = printf("ORIG>-0+5D 42\t[%-0+5D]\n", LONG_MIN);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>D \t[%D]\n", LONG_MIN);
		or = printf("ORIG>D \t[%D]\n", LONG_MIN);
		ft_print_result(mr, or, __LINE__);


		mr = ft_printf("MINE>###-#0000 33...12..#0+0D 256\t[%###-#0000 33...12#0+0D]\n", 256);
		or = printf("ORIG>###-#0000 33...12..#0+0D 256\t[%###-#0000 33...12#0+0D]\n", 256);
		ft_print_result(mr, or, __LINE__);

    return(0);
}
