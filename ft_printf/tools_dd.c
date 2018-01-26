/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_dd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 13:22:30 by djoly             #+#    #+#             */
/*   Updated: 2016/03/09 19:15:13 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_nbrlendd(long int nb)
{
	int i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

static int		ft_nbrlenhhdd(unsigned char nb)
{
	int i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

int				ft_arglendd(t_env *env)
{
	if (FNDFLAGS[5] == 2)
		return (ft_nbrlenhhdd((unsigned char)ARG));
	else
		return (ft_nbrlendd((long int)ARG));
}

void			ft_which_putnbrnegdd(t_env *env)
{
	if (FNDFLAGS[5] == -1 && FNDFLAGS[6] == -1 && FNDFLAGS[7] == -1
	&& FNDFLAGS[8] == -1 && (int)ARG < 0)
		RET = RET + ft_putnbr((long int)NBNEG);
	else if (FNDFLAGS[6] == 1)
		RET = RET + ft_putnbr((long int)NBNEG);
	else if (FNDFLAGS[6] == 2)
		RET = RET + ft_putnbr((long long int)NBNEG);
	else if (FNDFLAGS[8] == 1)
		RET = RET + ft_putnbr((size_t)NBNEG);
	else if (FNDFLAGS[5] == 2)
		RET = RET + ft_putnbr((int)NBNEG);
	else if (FNDFLAGS[7] == 1)
		RET = RET + ft_putnbr((intmax_t)NBNEG);
	else if (FNDFLAGS[5] == 1)
		RET = RET + ft_putnbr((int)NBNEG);
	else
		RET = RET + ft_putnbr((long int)NBNEG);
}

void			ft_which_putnbrdd(t_env *env)
{
	if (FNDFLAGS[5] == -1 && FNDFLAGS[6] == -1 && FNDFLAGS[7] == -1
	&& FNDFLAGS[8] == -1 && (int)ARG < 0)
		RET = RET + ft_putnbr((long int)ARG);
	else if (FNDFLAGS[6] == 1)
		RET = RET + ft_putnbr((long int)ARG);
	else if (FNDFLAGS[6] == 2)
		RET = RET + ft_putnbr((long long int)ARG);
	else if (FNDFLAGS[8] == 1)
		RET = RET + ft_putnbr((size_t)ARG);
	else if (FNDFLAGS[5] == 2)
		RET = RET + ft_putnbr((int)ARG);
	else if (FNDFLAGS[7] == 1)
		RET = RET + ft_putnbr((intmax_t)ARG);
	else if (FNDFLAGS[5] == 1)
		RET = RET + ft_putnbr((int)ARG);
	else
		RET = RET + ft_putnbr((long int)ARG);
}
