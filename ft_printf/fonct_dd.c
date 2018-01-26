/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_dd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 10:30:44 by djoly             #+#    #+#             */
/*   Updated: 2016/03/09 20:52:51 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_flag_prec(t_env *env)
{
	if ((long int)ARG == 0 && NBR == -1 && NBRPREC == -1)
		return ;
	if (NBRPREC == -1 && NBRPREC < ARGLEN && (long int)ARG != 0)
		NBRPREC = ARGLEN;
	before_nbrd_prec(env);
	if (NBRPREC != -1)
		ft_which_putnbrdd(env);
	if (NBR != -1 && FNDFLAGS[2] == 1)
	{
		if (FNDFLAGS[3] == 1)
			NBR = NBR - 1;
		RET = RET + ft_putspace(NBR - NBRPREC);
	}
}

static void			add_fonct_dd(t_env *env)
{
	if (FNDFLAGS[2] != 1)
	{
		if (FNDFLAGS[4] == 1 && NBR == -1 && FNDFLAGS[3] == -1 &&
		((long int)ARG > 0))
			RET = RET + ft_putchar(' ');
		else if (FNDFLAGS[1] == -1 && NBR != -1 && NBR > ARGLEN)
		{
			if (FNDFLAGS[3] == 1 && (long int)ARG > 0)
				NBR = NBR - 1;
			NBR = NBR - ARGLEN;
			RET = RET + ft_putspace(NBR);
		}
		if ((FNDFLAGS[3] == 1) && ((long int)ARG >= 0) && env->putneg != 1)
		{
			RET = RET + ft_putchar('+');
			NBR = NBR - 1;
		}
		if (NBR != -1 && NBR > ARGLEN)
		{
			if (FNDFLAGS[1] == 1 && FNDFLAGS[2] != 1)
				ft_putzero(env);
		}
	}
}

static void			add_fonct_dd2(t_env *env)
{
	if (FNDFLAGS[2] == 1)
	{
		if ((FNDFLAGS[4] == 1 && NBR == -1))
			if ((int)ARG > 0)
				RET = RET + ft_putchar(' ');
		if (NBR != -1 && NBR > ARGLEN)
		{
			if (FNDFLAGS[2] == -1 && (FNDFLAGS[3] == 1)
			&& ((long int)ARG > 0))
				NBR = NBR - 1;
			if (FNDFLAGS[1] == 1 && FNDFLAGS[2] != 1)
				ft_putzero(env);
			else
				RET = RET + ft_putspace(NBR - ARGLEN);
		}
	}
}

int					fonct_dd(t_env *env)
{
	ARGLEN = ft_arglendd(env);
	if (FNDFLAGS[9] == 1)
		ft_flag_prec(env);
	else
	{
		add_fonct_dd(env);
		if ((long int)ARG >= 0 && FNDFLAGS[3] == 1 && FNDFLAGS[2] == 1)
		{
			ARGLEN = ARGLEN + 1;
			RET = RET + ft_putchar('+');
		}
		ft_which_putnbrdd(env);
		add_fonct_dd2(env);
	}
	return (1);
}
