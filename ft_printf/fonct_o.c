/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:03:36 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 12:13:53 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void						inter_x_prec(t_env *env)
{
	if (FNDFLAGS[0] == 1)
	{
		if ((unsigned long int)ARG != 0)
		{
			RET = RET + ft_putspace(NBR - 1 - ARGLEN);
			RET = RET + ft_putchar('0');
		}
		else
			RET = RET + ft_putspace(NBR - 1);
		RET = RET + ft_which_putoctal(env);
	}
	else
		RET = RET + ft_putspace(NBR);
}

static void						x_prec(t_env *env)
{
	if (NBRPREC != -1)
	{
		if (FNDFLAGS[2] == -1 && NBR > ARGLEN && NBRPREC < ARGLEN)
			RET = RET + ft_putspace(NBR - ARGLEN);
		else if (FNDFLAGS[2] == -1 && NBR > ARGLEN && NBRPREC < NBR)
			RET = RET + ft_putspace(NBR - NBRPREC);
		if (NBRPREC > env->arglen)
			RET = RET + ft_putzero2(NBRPREC - env->arglen);
		RET = RET + ft_which_putoctal(env);
		if (FNDFLAGS[2] == 1 && FNDFLAGS[9] == 1 && NBR > NBRPREC)
			RET = RET + ft_putspace(NBR - NBRPREC);
	}
	else if (NBR != -1)
		inter_x_prec(env);
	else if (FNDFLAGS[0] == 1)
	{
		if ((unsigned long int)ARG != 0)
			RET = RET + ft_putchar('0');
		RET = RET + ft_which_putoctal(env);
	}
}

int								fonct_o(t_env *env)
{
	ARGLEN = ft_argleno(env);
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{
		if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR != -1)
		{
			if (FNDFLAGS[0] == 1)
				NBR = NBR - 1;
			RET = RET + ft_putspace(NBR - env->arglen);
		}
		if (FNDFLAGS[2] != 1 && FNDFLAGS[1] == 1 && NBR != -1)
			RET = RET + ft_putzero2(NBR - env->arglen);
		if (FNDFLAGS[0] == 1 && (unsigned long int)ARG != 0)
			RET = RET + ft_putzero2(1);
		RET = RET + ft_which_putoctal(env);
		if (FNDFLAGS[2] == 1 && NBR != -1 && NBR > env->arglen)
		{
			if (FNDFLAGS[0] == 1)
				NBR = NBR - 1;
			RET = RET + ft_putspace(NBR - env->arglen);
		}
	}
	return (1);
}
