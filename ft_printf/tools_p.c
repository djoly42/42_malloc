/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:19:24 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 15:07:18 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			hexa_lenll(unsigned long long int nb)
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

int					hexa_lenp(t_env *env)
{
	return (hexa_lenll((unsigned long long int)ARG));
}

static void			print_hexal(unsigned long int nb, t_env *env)
{
	if (nb != 0)
	{
		print_hexal(nb / 16, env);
		ft_putchar(HEXA[nb % 16]);
	}
}

void				print_hexap(t_env *env)
{
	print_hexal((long long unsigned int)ARG, env);
}
