/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maini.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 09:13:26 by djoly             #+#    #+#             */
/*   Updated: 2016/02/24 09:43:48 by djoly            ###   ########.fr       */
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
mr = ft_printf("MINE>\t[%lli]\n", 9223372036854775807);
	or = printf(   "ORIG>\t[%lli]\n", 9223372036854775807);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5.4i]\n", 10);
	or = printf(   "ORIG>\t[%-5.4i]\n", 10);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%8.4i]\n", 10);
	or = printf(   "ORIG>\t[%8.4i]\n", 10);
	ft_print_result(mr, or, __LINE__);


return (0);
}


