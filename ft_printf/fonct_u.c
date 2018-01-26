/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:03:36 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 15:07:00 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_arglen(t_env *env)
{
	if (FNDFLAGS[6] == 1)
		return (ft_nbrlenll((long unsigned int)ARG));
	else if (FNDFLAGS[6] == 2)
		return (ft_nbrlenll((long long unsigned int)ARG));
	else if (FNDFLAGS[7] == 1)
		return (ft_nbrlenll((uintmax_t)ARG));
	else if (FNDFLAGS[5] == 1)
		return (ft_nbrlenll((uintmax_t)ARG));
	else
		return (ft_nbrlenll((unsigned int)ARG));
}

static void			x_prec(t_env *env)
{
	if (NBRPREC != -1)
	{
		if (FNDFLAGS[2] != 1 && NBR > ARGLEN && NBRPREC < ARGLEN)
			RET = RET + ft_putspace(NBR - ARGLEN);
		else if (FNDFLAGS[2] != 1 && NBR > ARGLEN && NBRPREC < NBR)
			RET = RET + ft_putspace(NBR - NBRPREC);
		if (NBRPREC != -1 && NBRPREC > ARGLEN)
			RET = RET + ft_putzero2(NBRPREC - ARGLEN);
		RET = RET + ft_which_putnbr(env);
		if (FNDFLAGS[2] == 1 && NBRPREC != -1 && NBR != -1)
			RET = RET + ft_putspace(NBR - NBRPREC);
	}
}

int					fonct_u(t_env *env)
{
	env->arglen = ft_arglen(env);
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{
		if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR > ARGLEN)
			RET = RET + ft_putspace(NBR - env->arglen);
		if (FNDFLAGS[2] != 1 && FNDFLAGS[1] == 1 && NBR != -1)
			RET = RET + ft_putzero2(NBR - env->arglen);
		RET = RET + ft_which_putnbr(env);
		if (FNDFLAGS[2] == 1 && NBR != -1 &&
		NBR > env->arglen && FNDFLAGS[9] == -1)
			RET = RET + ft_putspace(NBR - env->arglen);
	}
	return (1);
}
