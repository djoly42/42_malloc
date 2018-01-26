/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maind.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 17:04:56 by djoly             #+#    #+#             */
/*   Updated: 2016/03/03 18:09:56 by djoly            ###   ########.fr       */
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
	printf("\033[1;37m======== %%d ========\033[0m\n");

	mr = ft_printf("MINE>\t[%d]\n", 650);
	or = printf("ORIG>\t[%d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%d]\n", -650);
	or = printf("ORIG>\t[%d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+d]\n", 650);
	or = printf("ORIG>\t[%+d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+1d]\n", 2048);
	or = printf("ORIG>\t[%+1d]\n", 2048);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+10d]\n", 650);
	or = printf("ORIG>\t[%+10d]\n", 650);
	ft_print_result(mr, or, __LINE__);
//5
	mr = ft_printf("MINE>\t[%+10d]\n", -650);
	or = printf("ORIG>\t[%+10d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%10d]\n", 650);
	or = printf("ORIG>\t[%10d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-10d]\n", 650);
	or = printf("ORIG>\t[%-10d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5d]\n", 650);
	or = printf("ORIG>\t[%-5d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% d]\n", 650);
	or = printf("ORIG>\t[% d]\n", 650);
	ft_print_result(mr, or, __LINE__);
//10
	mr = ft_printf("MINE>\t[% 5d]\n", 650);
	or = printf("ORIG>\t[% 5d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% d]\n", -650);
	or = printf("ORIG>\t[% d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% 5d]\n", -650);
	or = printf("ORIG>\t[% 5d]\n", -650);
	ft_print_result(mr, or, __LINE__);
//13
	mr = ft_printf("MINE>\t[%08d]\n", -650);
	or = printf("ORIG>\t[%08d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+06d]\n", -650);
	or = printf("ORIG>\t[%+06d]\n", -650);
	ft_print_result(mr, or, __LINE__);
//15
	mr = ft_printf("MINE>\t[%-05d]\n", -650);
	or = printf("ORIG>\t[%-05d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-05d]\n", -650);
	or = printf("ORIG>\t[%+-05d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-09d]\n", -650);
	or = printf("ORIG>\t[%+-09d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+09d]\n", -650);
	or = printf("ORIG>\t[%+09d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-1d]\n", -650);
	or = printf("ORIG>\t[%+-1d]\n", -650);
	ft_print_result(mr, or, __LINE__);
//20
	mr = ft_printf("MINE>\t[%+01d]\n", -650);
	or = printf("ORIG>\t[%+01d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%'d]\n", 65000);
	or = printf("ORIG>\t[%'d]\n", 65000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%'d]\n", 6500000);
	or = printf("ORIG>\t[%'d]\n", 6500000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+'d]\n", 65000);
	or = printf("ORIG>\t[%+'d]\n", 65000);
	ft_print_result(mr, or, __LINE__);


	mr = ft_printf("MINE>\t[%lld]\n", 9223372036854775807);
	or = printf(   "ORIG>\t[%lld]\n", 9223372036854775807);
	ft_print_result(mr, or, __LINE__);

//25
	mr = ft_printf("MINE>\t[%*d]\n", 10, 999);
	or = printf(   "ORIG>\t[%*d]\n", 10, 999);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%*d]\n", -10, 999);
	or = printf(   "ORIG>\t[%*d]\n", -10, 999);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%*d]\n", 999);
	or = printf(   "ORIG>\t[%*d]\n", 999);
	ft_print_result(mr, or, __LINE__);


	mr = ft_printf("MINE>\t[%*2$d]\n", 10, 40);
	or = printf(   "ORIG>\t[%*2$d]\n", 10, 40);
	ft_print_result(mr, or, __LINE__);

//Crashtest
	printf("\033[1;37m====  CRASH TEST ===\033[0m\n");
//29
	mr = ft_printf("MINE>\t[%d]\n");
	or = printf("ORIG>\t[%d]\n");
	ft_print_result(mr, or, __LINE__);


	mr = ft_printf("MINE>\t[-10+d s : {%+-10d} {%s}]\n", 12345, "argl");
	or = printf(   "ORIG>\t[-10+d s : {%+-10d} {%s}]\n", 12345, "argl");
	ft_print_result(mr, or, __LINE__);



	printf("\033[1;37m==== %%d + modifiers ===\033[0m\n");
//31
	mr = ft_printf("MINE>\t[%hhd]\n", 123456789);
	or = printf(   "ORIG>\t[%hhd]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%hd]\n", 123456789);
	or = printf(   "ORIG>\t[%hd]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%lld]\n", 123456789);
	or = printf(   "ORIG>\t[%lld]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%ld]\n", 123456789);
	or = printf(   "ORIG>\t[%ld]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%jd]\n", 123456789);
	or = printf(   "ORIG>\t[%jd]\n", 123456789);
	ft_print_result(mr, or, __LINE__);
//36
	mr = ft_printf("MINE>\t[%td]\n", 123456789);
	or = printf(   "ORIG>\t[%td]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%zd]\n", 123456789);
	or = printf(   "ORIG>\t[%zd]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	printf("\033[1;37m== End %%d + modifiers ==\033[0m\n\n");












	printf("\033[1;37m==== precision modifiers ===\033[0m\n");

//38
	mr = ft_printf("MINE>\t[%.4d]\n", 10);
	or = printf(   "ORIG>\t[%.4d]\n", 10);
	ft_print_result(mr, or, __LINE__);
//39
	mr = ft_printf("MINE>\t[%-.4d]\n", 10000);
	or = printf(   "ORIG>\t[%-.4d]\n", 10000);
	ft_print_result(mr, or, __LINE__);
//40
	mr = ft_printf("MINE>\t[%.1d]\n", 10000);
	or = printf(   "ORIG>\t[%.1d]\n", 10000);
	ft_print_result(mr, or, __LINE__);
//41
	mr = ft_printf("MINE>\t[%-.0d]\n", 10000);
	or = printf(   "ORIG>\t[%-.0d]\n", 10000);
	ft_print_result(mr, or, __LINE__);

//42
	mr = ft_printf("MINE>\t[%5.4d]\n", 10);
	or = printf(   "ORIG>\t[%5.4d]\n", 10);
	ft_print_result(mr, or, __LINE__);
//43
	mr = ft_printf("MINE>\t[%-8.4d]\n", 10);
	or = printf(   "ORIG>\t[%-8.4d]\n", 10);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5.4d]\n", 10);
	or = printf(   "ORIG>\t[%-5.4d]\n", 10);
	ft_print_result(mr, or, __LINE__);
//45
	mr = ft_printf("MINE>\t[%-+8.4d]\n", 10);
	or = printf(   "ORIG>\t[%-+8.4d]\n", 10);
	ft_print_result(mr, or, __LINE__);
//46
	mr = ft_printf("MINE>\t[%2.4d]\n", 10000);
	or = printf(   "ORIG>\t[%2.4d]\n", 10000);
	ft_print_result(mr, or, __LINE__);
//47
	mr = ft_printf("MINE>\t[%10.1d]\n", 10000);
	or = printf(   "ORIG>\t[%10.1d]\n", 10000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%4.0d]\n", 10000);
	or = printf(   "ORIG>\t[%4.0d]\n", 10000);
	ft_print_result(mr, or, __LINE__);

	printf("\033[1;37m======== end %%d =====\033[0m\n\n");





	ft_printf("%d\n", 42);
	printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	printf("%lld\n", 9223372036854775807);

	ft_printf("%20.15d\n", 54321);
	printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	printf("%zd\n", 4294967295);
	ft_printf("%\n");
	printf("%\n");




	/* Pourquoi les ft_printf de ft_printf ? Parce que printf renvoie le nombre de caractere qu'il a affiche. Ainsi, on peut verifier si on renvoie bien le bon nombre.
	   Attention ! Il doit y avoir un caractere de moins sur le ft_printf puisqu'il n'a qu'un \n, pour plus de lisibilite */

//	printf("%d\n\n", ft_printf("%d\n\n", printf("%d\n", 2147483647)));

	/* Verifiez bien les bornes ! Elles ont tendance a boucler infini ... */

	ft_printf("%d\n", ft_printf("Les bornes :  %d, %d\n", -2147483648, 2147483647));
/*	ft_printf("%d\n", ft_printf("Les bornes :  %u, %u\n", 0, 4294967295));
	ft_printf("%d\n", ft_printf("Les bornes :  %o, %o\n", 0, 4294967295));
	ft_printf("%d\n", ft_printf("Les bornes :  %x, %x\n", 0, 4294967295));
*/
	/* Verification des decimals, %i et %d */

	ft_printf("%d\n", ft_printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));
	printf("%d\n\n", printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));

	ft_printf("%d\n", ft_printf("2chiffre 1 %   d chiffre 2 % d\n", 42, -42));
	printf("%d\n\n", printf("2chiffre 1 %   d chiffre 2 % d\n", 42, -42));

	ft_printf("%d\n", ft_printf("3chiffre 1 %12d chiffre 2 %12d\n", 42, -42));
	printf("%d\n\n", printf("3chiffre 1 %12d chiffre 2 %12d\n", 42, -42));

	ft_printf("%d\n", ft_printf("4chiffre 1 %-12d chiffre 2 %-12d\n", 42, -42));
	printf("%d\n\n", printf("4chiffre 1 %-12d chiffre 2 %-12d\n", 42, -42));

	ft_printf("%d\n", ft_printf("5chiffre 1 %0d chiffre 2 %0d\n", 42, -42));
	printf("%d\n\n", printf("5chiffre 1 %0d chiffre 2 %0d\n", 42, -42));

	ft_printf("%d\n", ft_printf("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42));
	printf("%d\n\n", printf("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42));

	ft_printf("%d\n", ft_printf("7chiffre 1 %-012d chiffre 2 %012d\n", 42, -42));
	printf("%d\n\n", printf("7chiffre 1 %-012d chiffre 2 %012d\n", 42, -42));

	ft_printf("%d\n", ft_printf("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6));
	printf("%d\n\n", printf("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6));

	ft_printf("%d\n", ft_printf("9chiffre 1 %+d chiffre 2 %+d\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("9chiffre 1 %+d chiffre 2 %+d\n", 42, 6, -42, 6));

	ft_printf("%d\n", ft_printf("10chiffre 1 %+12d chiffre 2 %+12d\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("10chiffre 1 %+12d chiffre 2 %+12d\n", 42, 6, -42, 6));

	ft_printf("%d\n", ft_printf("11chiffre 1 %*12d chiffre 2 %*12d\n", 42, -6, 42, 6));
	printf("%d\n\n", printf("11chiffre 1 %*12d chiffre 2 %*12d\n", 42, -6, 42, 6));

	ft_printf("%d\n", ft_printf("12chiffre 1 |%-+5d| chiffre 2 |%-+5d|\n", 42, -42));
	printf("%d\n\n", printf("12chiffre 1 |%-+5d| chiffre 2 |%-+5d|\n", 42, -42));

	ft_printf("%d\n", ft_printf("13chiffre 1 |%-+05d| chiffre 2 |%-+05d|\n", 42, -42));
	printf("%d\n\n", printf("13chiffre 1 |%-+05d| chiffre 2 |%-+05d|\n", 42, -42));

	ft_printf("%d\n", ft_printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n", 42, -42));
	printf("%d\n\n", printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n", 42, -42));

	ft_printf("%d\n", ft_printf("15chiffre 1 %.d chiffre 2 %.d\n", 42, -42));
	printf("%d\n\n", printf("15chiffre 1 %.d chiffre 2 %.d\n", 42, -42));

	ft_printf("%d\n", ft_printf("16chiffre 1 %.6d chiffre 2 %.6d\n", 42, -42));
	printf("%d\n\n", printf("16chiffre 1 %.6d chiffre 2 %.6d\n", 42, -42));



	/* Test du %% . Attention, les justifications aussi doivent etre gerees ! */

	ft_printf("%d\n", ft_printf("%%\n"));
	printf("%d\n\n", printf("%%\n"));




	/* Ces modificateurs ne sont pas obigatoires (h et l) */

	ft_printf("Test de chiffre sans h : %d, et %d\n", 432767, -432767);
	printf("Test de chiffre sans h : %d, et %d\n", 432767, -432767);
	printf("Test de chiffre avec h : %hd, et %hd\n", 432767, -432767);
	ft_printf("Test de chiffre avec h : %hd, et %hd\n", 432767, -432767);

	ft_printf("Test de cliffre sans l : %d, et %d\n", 32147483647, -32147483647);
	printf("Test de cliffre sans l : %d, et %d\n", 32147483647, -32147483647);
	printf("Test de cliffre avec l : %ld, et %ld\n", 32147483647, -32147483647);
	ft_printf("Test de cliffre avec l : %ld, et %ld\n\n", 32147483647, -32147483647);

	mr = ft_printf("MINE>\t[%+d]\t[% +d]\t[%+ d]\t[%   +d]\t[%  ++d]\n", 0, 0, 42, 42, 42);
	or = printf("ORIG>\t[%+d]\t[% +d]\t[%+ d]\t[%   +d]\t[%  ++d]\n", 0, 0, 42, 42, 42);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%0+5d]\t[%lld]\n", 42, -9223372036854775808);
	or = printf("ORIG>\t[%0+5d]\t[%lld]\n", 42, -9223372036854775808);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%4.15d]\n", 42);
	or = printf("ORIG>\t[%4.15d]\n", 42);
	ft_print_result(mr, or, __LINE__);
//52
	mr = ft_printf("MINE>\t[%+10.5d]\n", 4242);
	or = printf("ORIG>\t[%+10.5d]\n", 4242);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%03.2d]\n", -1);
	or = printf("ORIG>\t[%03.2d]\n", -1);
	ft_print_result(mr, or, __LINE__);
//54
    mr = ft_printf("MINE>\t[%06.2d]\n", -1);
	or = printf("ORIG>\t[%06.2d]\n", -1);
	ft_print_result(mr, or, __LINE__);

    mr = ft_printf("MINE>\t[%.d], [%.0d]\n", 0, 0);
	or = printf("ORIG>\t[%.d], [%.0d]\n", 0, 0);
	ft_print_result(mr, or, __LINE__);
//56
	mr = ft_printf("MINE>\t[%5.d], [%5.0d]\n", 1, 1);
	or = printf("ORIG>\t[%5.d], [%5.0d]\n", 1, 1);
	ft_print_result(mr, or, __LINE__);
//test zone
	mr = ft_printf("MINE>\t[%zhd]\n", 4294967296);
	or = printf("ORIG>\t[%zhd]\n", 4294967296);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%hzd]\n", 4294967296);
	or = printf("ORIG>\t[%hzd]\n", 4294967296);
	ft_print_result(mr, or, __LINE__);
//59
		mr = ft_printf("MINE>\t[%jhd]\n", 9223372036854775807);
		or = printf("ORIG>\t[%jhd]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);
//60
		mr = ft_printf("MINE>\t[%hjd]\n", 9223372036854775807);
		or = printf("ORIG>\t[%hjd]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);
//41 61
	mr = ft_printf("MINE>\t[%-.0d]\n", 10000);
	or = printf(   "ORIG>\t[%-.0d]\n", 10000);
	ft_print_result(mr, or, __LINE__);
//41 62
	mr = ft_printf("MINE>\t[%.d]\n", 10000);
	or = printf(   "ORIG>\t[%.d]\n", 10000);
	ft_print_result(mr, or, __LINE__);
//45 63
	mr = ft_printf("MINE>\t[%-+8.4d]\n", 10);
	or = printf(   "ORIG>\t[%-+8.4d]\n", 10);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>03.2d 0\t[%03.2d]\n", 0);
		or = printf("ORIG>03.2d 0\t[%03.2d]\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>03.2d 1\t[%03.2d]\n", 1);
			or = printf("ORIG>03.2d 1\t[%03.2d]\n", 1);
			ft_print_result(mr, or, __LINE__);



	mr = ft_printf("MINE>.10d -42\t[%.10d]\n", -42);
		or = printf("ORIG>.10d -42\t[%.10d]\n", -42);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>d 2147483648\t[%d]\n", 2147483648);
		or = printf("ORIG>d 2147483648\t[%d]\n", 2147483648);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>5.d 5.0d 0 0\t[%5.d], [%5.0d]\n", 0, 0);
		or = printf("ORIG>5.d 5.0d 0 0\t[%5.d], [%5.0d]\n", 0, 0);
		ft_print_result(mr, or, __LINE__);
//69
		mr = ft_printf("MINE>5.d 5.0d 1 1\t[%5.d], [%5.0d]\n", 1, 1);
		or = printf("ORIG>5.d 5.0d 1 1\t[%5.d], [%5.0d]\n", 1, 1);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>-5+d 42\t[%-5+d]\n", 42);
		or = printf("ORIG>-5+d 42\t[%-5+d]\n", 42);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>-0+5d 42\t[%-0+5D]\n", LONG_MAX);
		or = printf("ORIG>-0+5d 42\t[%-0+5D]\n", LONG_MAX);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>-0+5d 42\t[%D]\n", LONG_MAX);
		or = printf("ORIG>-0+5d 42\t[%D]\n", LONG_MAX);
		ft_print_result(mr, or, __LINE__);

mr = ft_printf("MINE>03.2 42\t[%03.2d]\n", -1);
or = printf("ORIG>03.2 42\t[%03.2d]\n", -1);
ft_print_result(mr, or, __LINE__);

//10 "% d"
	mr = ft_printf("MINE>\t[% 5d]\n", 650);
	or = printf("ORIG>\t[% 5d]\n", 650);
	ft_print_result(mr, or, __LINE__);
		/*
		mr = ft_printf("MINE>###-#0000 33...12..#0+0d 256\t[%###-#0000 33...12#0+0d]\n", 256);
		or = printf("ORIG>###-#0000 33...12..#0+0d 256\t[%###-#0000 33...12#0+0d]\n", 256);
		ft_print_result(mr, or, __LINE__);
*/
    return(0);
}
