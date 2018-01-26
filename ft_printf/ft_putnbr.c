/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:09:51 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 14:57:04 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putnbrllu(long long unsigned nbr)
{
	int	ret;

	ret = 0;
	if (nbr >= 10)
	{
		ret = ret + ft_putnbrllu(nbr / 10);
		ret = ret + ft_putnbrllu(nbr % 10);
	}
	else
		ret = ret + ft_putchar(nbr + '0');
	return (ret);
}

int			ft_which_putnbr(t_env *env)
{
	if (ITOK == 8 || ITOK == 9)
	{
		if (FNDFLAGS[6] == 1)
			return (ft_putnbrllu((long unsigned int)ARG));
		else if (FNDFLAGS[6] == 2)
			return (ft_putnbrllu((long long unsigned int)ARG));
		else if (FNDFLAGS[7] == 1)
			return (ft_putnbrllu((uintmax_t)ARG));
		else if (FNDFLAGS[5] == 1 || ITOK == 9)
			return (ft_putnbrllu((uintmax_t)ARG));
		else if (FNDFLAGS[5] == 2)
			return (ft_putnbrllu((unsigned char)ARG));
		else if (FNDFLAGS[8] == 1)
			return (ft_putnbrllu((size_t)ARG));
		else
			return (ft_putnbrllu((unsigned int)ARG));
	}
	return (0);
}

int			ft_putnbr2(long long unsigned int nbr)
{
	int	ret;

	ret = 0;
	if (nbr >= 10)
	{
		ret = ret + ft_putnbr2(nbr / 10);
		ret = ret + ft_putnbr2(nbr % 10);
	}
	else
		ret = ret + ft_putchar(nbr + '0');
	return (ret);
}

int			ft_putnbr(long long int nbr)
{
	int	ret;

	ret = 0;
	if (nbr == LLONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return (20);
	}
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = (-1) * nbr;
			ret++;
		}
		if (nbr >= 10)
		{
			ret = ret + ft_putnbr(nbr / 10);
			ret = ret + ft_putnbr(nbr % 10);
		}
		else
			ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}
