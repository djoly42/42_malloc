/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:45:09 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 15:03:05 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_putoctal_llo(unsigned long long int nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 7)
	{
		ret = ret + ft_putoctal_llo(nbr / 8);
		ret = ret + ft_putoctal_llo(nbr % 8);
	}
	else
		ret = ret + ft_putchar(nbr + '0');
	return (ret);
}

int				ft_which_putoctal(t_env *env)
{
	if (FNDFLAGS[7] == 1)
		return (ft_putoctal_llo((uintmax_t)ARG));
	else if (FNDFLAGS[5] == 1)
		return (ft_putoctal_llo((unsigned short int)ARG));
	else if (FNDFLAGS[5] == 2)
		return (ft_putoctal_llo((unsigned char)ARG));
	else if (FNDFLAGS[6] == 1)
		return (ft_putoctal_llo((unsigned long int)ARG));
	else if (FNDFLAGS[6] == 2)
		return (ft_putoctal_llo((unsigned long long int)ARG));
	else if (FNDFLAGS[8] == 1)
		return (ft_putoctal_llo((size_t)ARG));
	else
		return (ft_putoctal_llo((unsigned int)ARG));
}

static int		ft_nbrleno(long long int nb)
{
	int i;

	i = 1;
	while (nb /= 8)
		i++;
	return (i);
}

int				ft_argleno(t_env *env)
{
	if (FNDFLAGS[5] == 2)
		return (ft_nbrleno((unsigned char)ARG));
	else if (FNDFLAGS[6] == 2)
		return (ft_nbrleno((long long unsigned int)ARG));
	else if (FNDFLAGS[7] == 1)
		return (ft_nbrleno((uintmax_t)ARG));
	else if (FNDFLAGS[5] == 1)
		return (ft_nbrleno((uintmax_t)ARG));
	else
		return (ft_nbrleno((unsigned int)ARG));
}
