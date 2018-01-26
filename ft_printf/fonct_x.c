/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:36:04 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 13:51:56 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_dies(t_env *env)
{
	ft_putzero2(1);
	if (ITOK == 10)
		ft_putchar('x');
	else
		ft_putchar('X');
	return (2);
}

static int		ft_test0(t_env *env)
{
	if (FNDFLAGS[6] == 1 && (long long unsigned int)ARG == 0)
		return (1);
	else if (FNDFLAGS[6] == 2 && (long long unsigned int)ARG == 0)
		return (1);
	else if (FNDFLAGS[7] == 1 && (uintmax_t)ARG == 0)
		return (1);
	else if (FNDFLAGS[6] == -1 && FNDFLAGS[7] == -1 && (unsigned int)ARG == 0)
		return (1);
	return (0);
}

static void		inter_xprec(t_env *env)
{
	if (FNDFLAGS[2] == -1 && NBR != -1)
	{
		if (NBR > NBRPREC)
		{
			if (NBRPREC > ARGLEN)
				RET = RET + ft_putspace(NBR - NBRPREC);
			else if (ft_test0(env))
				RET = RET + ft_putspace(NBR);
			else
				RET = RET + ft_putspace(NBR - ARGLEN);
		}
	}
	if (FNDFLAGS[0] == 1 && !ft_test0(env))
		RET = RET + print_dies(env);
	if (NBRPREC != -1 && NBRPREC > env->arglen)
		RET = RET + ft_putzero2(NBRPREC - env->arglen);
}

static void		x_prec(t_env *env)
{
	if (!ft_test0(env) && FNDFLAGS[0] == 1 && NBR != -1)
		NBR = NBR - 2;
	inter_xprec(env);
	if (ft_test0(env))
	{
		if (NBR != -1 && NBRPREC != -1)
			RET = RET + ft_putchar('0');
	}
	else
	{
		print_hexax(env);
		RET = RET + ARGLEN;
	}
	if (FNDFLAGS[2] == 1 && NBRPREC != -1 && NBR != -1)
		RET = RET + ft_putspace(NBR - NBRPREC);
}

int				fonct_x(t_env *env)
{
	env->arglen = hexa_lenx(env);
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{
		if (FNDFLAGS[0] == 1 && NBR != -1)
			NBR = NBR - 2;
		if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR > ARGLEN)
			RET = RET + ft_putspace(NBR - env->arglen);
		if (FNDFLAGS[0] == 1 && !ft_test0(env))
			RET = RET + print_dies(env);
		if (FNDFLAGS[2] != 1 && FNDFLAGS[1] == 1 && NBR != -1)
			RET = RET + ft_putzero2(NBR - env->arglen);
		if (ft_test0(env))
			ft_putchar('0');
		else
			print_hexax(env);
		RET = RET + ARGLEN;
		if (FNDFLAGS[2] == 1 && NBR != -1
				&& NBR > env->arglen && FNDFLAGS[9] == -1)
			RET = RET + ft_putspace(NBR - env->arglen);
	}
	return (1);
}
