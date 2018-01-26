/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:47:51 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 13:52:56 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		hexa_lenll(unsigned long long int nb)
{
	int i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

int				hexa_lenx(t_env *env)
{
	if (FNDFLAGS[6] == 1)
		return (hexa_lenll((unsigned long int)ARG));
	else if (FNDFLAGS[6] == 2)
		return (hexa_lenll((unsigned long long int)ARG));
	else if (FNDFLAGS[5] == 1)
		return (hexa_lenll((unsigned short int)ARG));
	else if (FNDFLAGS[5] == 2)
		return (hexa_lenll((unsigned char)ARG));
	else if (FNDFLAGS[7] == 1)
		return (hexa_lenll((uintmax_t)ARG));
	else if (FNDFLAGS[8] == 1)
		return (hexa_lenll((size_t)ARG));
	return (hexa_lenll((unsigned int)ARG));
}

static void		print_hexall(long long unsigned int nb, t_env *env)
{
	if (nb != 0)
	{
		print_hexall(nb / 16, env);
		if (ITOK == 10)
			ft_putchar(HEXA[nb % 16]);
		else
			ft_putchar(HEXA2[nb % 16]);
	}
}

void			print_hexax(t_env *env)
{
	if (FNDFLAGS[6] == 1)
		print_hexall((long long unsigned int)ARG, env);
	else if (FNDFLAGS[6] == 2)
		print_hexall((long long unsigned int)ARG, env);
	else if (FNDFLAGS[7] == 1)
		print_hexall((uintmax_t)ARG, env);
	else if (FNDFLAGS[5] == 1)
		print_hexall((unsigned short int)ARG, env);
	else if (FNDFLAGS[5] == 2)
		print_hexall((unsigned char)ARG, env);
	else if (FNDFLAGS[8] == 1)
		print_hexall((size_t)ARG, env);
	else
		print_hexall((unsigned int)ARG, env);
}
