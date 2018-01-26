/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 10:54:56 by daniel            #+#    #+#             */
/*   Updated: 2016/03/02 13:24:10 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#define MINE ft_printf
#define ORIG printf

int main ()
{
setlocale(LC_ALL, "en_US.UTF-8");
  int mr;
  int or;

	printf("======== %%c ========\n");
	mr = ft_printf("MINE>\t[%C]\n", 945);
	or = printf("ORIG>\t[%C]\n", 945);
	printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>2c\t[%2c]\n", 'r');
	or = printf("ORIG>2c\t[%2c]\n", 'r');
	printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>+3c\t[%+3c]\n", 'r');
	or = printf("ORIG>+3c\t[%+3c]\n", 'r');
	printf("mr:%d or:%d\n",mr, or);

//	printf("mr:>>%-3.+4d<<or:\n",42);
	mr = ft_printf("MINE>-3c\t[%-3c]\n", 'r');
	or = printf("ORIG>-3c\t[%-3c]\n", 'r');
	printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>-10c\t[%-10c]\n", 'r');
	or = printf("ORIG>-10c\t[%-10c]\n", 'r');
printf("mr:%d or:%d\n",mr, or);
// mine 000r ORIG     r ???
	mr = ft_printf("MINE>010c\t[%010c]\n", 'r');
	or = printf("ORIG>010c\t[%010c]\n", 'r');
	printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>+-10c\t[%+-10c]\n", 'r');
	or = printf("ORIG>+-10c\t[%+-10c]\n", 'r');
	printf("mr:%d or:%d\n",mr, or);
// mine 000r ORIG     r ???

	mr = ft_printf("MINE>0+10c\t[%0+10c]\n", 'r');
	or = printf("ORIG>0+10c\t[%0+10c]\n", 'r');
	printf("mr:%d or:%d\n",mr, or);

/* 	========c AVEC * ============
	mr = ft_printf("MINE>\t[%*c]\n", 8, 'c');
	or = printf(   "ORIG>\t[%*c]\n", 8, 'c');
	printf("mr:%d or:%d\n",mr, or);


	mr = ft_printf("MINE>\t[%-*c]\n", 8, 'k');
	or = printf(   "ORIG>\t[%-*c]\n", 8, 'k');
	printf("mr:%d or:%d\n",mr, or);
*/
	mr = ft_printf("MINE>5.4c\t[%5.2c]\n", 'k');
	or = printf(   "ORIG>5.4c\t[%5.2c]\n", 'k');
	printf("mr:%d or:%d\n",mr, or);

	mr = ft_printf("MINE>-5.4c\t[%-5.4c]\n", 'k');
	or = printf(   "ORIG>-5.4c\t[%-5.4c]\n", 'k');
	printf("mr:%d or:%d\n",mr, or);
//		lc == C
	ft_printf("MINE>lc>>%lc, %lc", L'暖', L'ح');
	printf("ORIG>lc>>%lc, %lc", L'暖', L'ح');
	printf("mr:%d or:%d\n",mr, or);

/*
	ft_printf("MINE>#c>\t[%#c]\n", 0);
	printf("ORIG>#c>\t[%#c]\n", 0);
//	printf("mr:%d or:%d\n",mr, or);
*/
	ft_printf("MINE>+c\t[%+c]\n", 0);
	printf("ORIG>+c\t[%+c]\n", 0);
//	printf("mr:%d or:%d\n",mr, or);

	ft_printf("MINE>.c\t[%.c]\n", 0);
	printf("ORIG>.c\t[%.c]\n", 0);
//	printf("mr:%d or:%d\n",mr, or);

	ft_printf("MINE>.5c\t[%.5c]\n", 0);
	printf("ORIG>.5c\t[%.5c]\n", 0);
//	printf("mr:%d or:%d\n",mr, or);

	ft_printf("MINE>.5c\t[%.5c]\n", 42);
	printf("ORIG>.5c\t[%.5c]\n", 42);
	printf("mr:%d or:%d\n",mr, or);

	ft_printf("MINE>c\t[%c]\n", 200);
	printf("ORIG>c\t[%c]\n", 200);

//	printf("======== end %%c =====\n\n");
/*
	//printf("abc")
	printf("|%d|\n",12345);
	ft_printf("|%d|\n",12345);
	printf("|%+d|\n",12345);
	ft_printf("|%+d|\n",12345);
	printf("|%8d|\n",12345);
	ft_printf("|%8d|\n",12345);
	printf("|%x|\n",255);
	ft_printf("|%x|\n",255);
	printf("|%X|\n",255);
	ft_printf("|%X|\n",255);
	printf("|%#x|\n",255);
	ft_printf("|%#x|\n",255);
    printf("|%f|\n",1.213456789102345);
    ft_printf("|%f|\n",1.213456789102345);
    printf("|%10.4f|\n",1.213456789);
    ft_printf("|%10.4f|\n",1.213456789);

    printf("printf:|%4d|%2d|\n",123,123);
	ft_printf("ft_printf:|%d|%d|\n",123,123);
    ft_printf("|abc|%%|%d|%c|\n",0,'1');
*/


	  /* PLUS PLUS Memes tests avec les %c */

	  ft_printf("%d\n", ft_printf("1caractere 1 %c caractere 2 %c\n", 'a', 'c'));
	  printf("%d\n\n", printf("1caractere 1 %c caractere 2 %c\n", 'a', 'c'));

	  ft_printf("%d\n", ft_printf("2caractere 1 %   c caractere 2 % c\n", 'a', 'c'));
	  printf("%d\n\n", printf("2caractere 1 %   c caractere 2 % c\n", 'a', 'c'));

	  printf("%d\n", ft_printf("3caractere 1 %12c caractere 2 %12c\n", 'a', 'c'));
	  printf("%d\n\n", printf("3caractere 1 %12c caractere 2 %12c\n", 'a', 'c'));

	  ft_printf("%d\n", ft_printf("4caractere 1 %-12c caractere 2 %-12c\n", 'a', 'c'));
	  printf("%d\n\n", printf("4caractere 1 %-12c caractere 2 %-12c\n", 'a', 'c'));

	  ft_printf("%d\n", ft_printf("5caractere 1 %0c caractere 2 %0c\n", 'a', 'c'));
	  printf("%d\n\n", printf("5caractere 1 %0c caractere 2 %0c\n", 'a', 'c'));

	  ft_printf("%d\n", ft_printf("6caractere 1 %012c caractere 2 %012c\n", 'a', 'c'));
	  printf("%d\n\n", printf("6caractere 1 %012c caractere 2 %012c\n", 'a', 'c'));

	  ft_printf("%d\n", ft_printf("7caractere 1 %-012c caractere 2 %012c\n", 'a', 'c'));
	  printf("%d\n\n", printf("7caractere 1 %-012c caractere 2 %012c\n", 'a', 'c'));

//	  ft_printf("%d\n", ft_printf("8caractere 1 %*c caractere 2 %*c\n", 'a', 6, 6, 6));
//	  printf("%d\n\n", printf("8caractere 1 %*c caractere 2 %*c\n", 'a', 6, 6, 6));

	  ft_printf("%d\n", ft_printf("9caractere 1 %+c caractere 2 %+c\n", 'a', 6, 'c', 6));
	  printf("%d\n\n", printf("9caractere 1 %+c caractere 2 %+c\n", 'a', 6, 'c', 6));

	  ft_printf("%d\n", ft_printf("10caractere 1 %+12c caractere 2 %+12c\n", 'a', 6, 'c', 6));
	  printf("%d\n\n", printf("10caractere 1 %+12c caractere 2 %+12c\n", 'a', 6, 'c', 6));

//	  ft_printf("%d\n", ft_printf("11caractere 1 %*12c caractere 2 %*12c\n", 'a', -6, 'a', 6));
//	  printf("%d\n\n", printf("11caractere 1 %*12c caractere 2 %*12c\n", 'a', -6, 'a', 6));

	  ft_printf("%d\n", ft_printf("12caractere 1 %-+5c caractere 2 %-+5c\n", 'a', 'c'));
	  printf("%d\n\n", printf("12caractere 1 %-+5c caractere 2 %-+5c\n", 'a', 'c'));

	  ft_printf("%d\n", ft_printf("13caractere 1 %-+05c caractere 2 %-+05c\n", 'a', 'c'));
	  printf("%d\n\n", printf("13caractere 1 %-+05c caractere 2 %-+05c\n", 'a', 'c'));

	  ft_printf("%d\n", ft_printf("14caractere 1 %+-5c caractere 2 %+-5c\n", 'a', 'c'));
	  printf("%d\n\n", printf("14caractere 1 %+-5c caractere 2 %+-5c\n", 'a', 'c'));

	  ft_printf("%d\n", ft_printf("15caractere 1 %.c caractere 2 %.c\n", 'a', 'c'));
	  printf("%d\n\n", printf("15caractere 1 %.c caractere 2 %.c\n", 'a', 'c'));

	  ft_printf("%d\n", ft_printf("16caractere 1 %.6c caractere 2 %.6c\n", 'a', 'c'));
	  printf("%d\n\n", printf("16caractere 1 %.6c caractere 2 %.6c\n", 'a', 'c'));


    return (0);
}
