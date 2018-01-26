/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 10:03:08 by djoly             #+#    #+#             */
/*   Updated: 2016/03/09 20:36:30 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flag_prec(t_env *env)
{
	FNDFLAGS[1] = -1;
	if ((int)ARG == 0 && NBR == -1 && NBRPREC == -1)
		return ;
	before_nbrd_prec(env);
	if ((int)ARG == 0 && NBRPREC == -1)
	{
	}
	else if (env->putneg == 1)
		ft_which_putnbrnegd(env);
	else
		ft_which_putnbrd(env);
	if (NBR != -1 && FNDFLAGS[2] == 1)
	{
		if (FNDFLAGS[3] == 1)
			NBR = NBR - 1;
		RET = RET + ft_putspace(NBR - NBRPREC);
	}
}

static void		before_nbr(t_env *env)
{
	if (FNDFLAGS[1] == -1 && NBR != -1 && NBR > ft_nbrlen((int)ARG))
	{
		if (FNDFLAGS[3] == 1 && (int)ARG > 0)
			NBR = NBR - 1;
		NBR = NBR - ft_nbrlen((int)ARG);
		RET = RET + ft_putspace(NBR);
	}
	else if (FNDFLAGS[4] == 1 && FNDFLAGS[3] == -1 && ((int)ARG >= 0))
	{
		RET = RET + ft_putchar(' ');
		NBR = NBR - 1;
	}
	if ((FNDFLAGS[3] == 1) && ((int)ARG >= 0))
	{
		if (env->putneg != 1)
		{
			RET = RET + ft_putchar('+');
			NBR = NBR - 1;
		}
	}
	if (NBR != -1 && NBR > ft_nbrlen((int)ARG))
	{
		if (FNDFLAGS[1] == 1 && FNDFLAGS[2] != 1)
			ft_putzero(env);
	}
}

static void		after_nbr(t_env *env)
{
	if ((FNDFLAGS[4] == 1 && NBR == -1))
		if ((int)ARG > 0)
			RET = RET + ft_putchar(' ');
	if (NBR != -1 && NBR > ft_nbrlen((int)ARG))
	{
		if (FNDFLAGS[2] == -1 && (FNDFLAGS[3] == 1) && ((int)ARG > 0))
			NBR = NBR - 1;
		if (FNDFLAGS[1] == 1 && FNDFLAGS[2] != 1)
			ft_putzero(env);
		else
			RET = RET + ft_putspace(NBR - ARGLEN);
	}
}

int				fonct_d(t_env *env)
{
	ARGLEN = ft_nbrlen((int)ARG);
	if (FNDFLAGS[2] == 1)
		FNDFLAGS[1] = -1;
	if (FNDFLAGS[9] == 1)
		ft_flag_prec(env);
	else
	{
		if (FNDFLAGS[2] != 1)
			before_nbr(env);
		if ((int)ARG >= 0 && FNDFLAGS[3] == 1 && FNDFLAGS[2] == 1)
		{
			ARGLEN = ARGLEN + 1;
			RET = RET + ft_putchar('+');
		}
		if (env->putneg == 1)
			ft_which_putnbrnegd(env);
		else
			ft_which_putnbrd(env);
		if (FNDFLAGS[2] == 1)
			after_nbr(env);
	}
	return (1);
}
