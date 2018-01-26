/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:35:37 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 13:23:55 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			print_dies(t_env *env)
{
	ft_putzero2(1);
	if (ITOK == 10)
		ft_putchar('X');
	else
		ft_putchar('x');
	return (2);
}

static int			ft_test0(t_env *env)
{
	if (FNDFLAGS[6] == 1 && (long long unsigned int)ARG == 0)
		return (1);
	else if (FNDFLAGS[6] == 2 && (long long unsigned int)ARG == 0)
		return (1);
	else if (FNDFLAGS[7] == 1 && (uintmax_t)ARG == 0)
		return (1);
	else if (FNDFLAGS[6] == -1 && FNDFLAGS[7] == -1 && (unsigned int)ARG == 0)
		return (1);
	else
		return (0);
}

static void			interx_prec(t_env *env)
{
	if (NBRPREC != -1 && NBRPREC > (ARGLEN - 2))
		RET = RET + ft_putzero2(NBRPREC - ARGLEN + 2);
	if (ft_test0(env))
	{
		if (NBRPREC != -1)
			RET = RET + ft_putchar('0');
	}
	else
	{
		print_hexap(env);
		RET = RET + ARGLEN - 2;
	}
	if (FNDFLAGS[2] == 1 && NBRPREC != -1 && NBR > NBRPREC)
		RET = RET + ft_putspace(NBR - NBRPREC);
}

static void			x_prec(t_env *env)
{
	if (NBRPREC != -1)
	{
		if (FNDFLAGS[2] == -1 && NBR != -1 && NBR > NBRPREC)
		{
			if (NBRPREC > ARGLEN)
				RET = RET + ft_putspace(NBR - NBRPREC - 2);
			else if (ft_test0(env))
				RET = RET + ft_putspace(NBR);
			else
				RET = RET + ft_putspace(NBR - ARGLEN);
		}
		RET = RET + print_dies(env);
		interx_prec(env);
	}
	else
		RET = RET + print_dies(env);
}

int					fonct_p(t_env *env)
{
	ARGLEN = hexa_lenp(env);
	ARGLEN = ARGLEN + 2;
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{
		if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR > ARGLEN)
			RET = RET + ft_putspace(NBR - env->arglen);
		RET = RET + print_dies(env);
		if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == 1 && NBR > ARGLEN)
			RET = RET + ft_putzero2(NBR - ARGLEN);
		if (ft_test0(env))
			RET = RET + ft_putchar('0');
		else
		{
			print_hexap(env);
			RET = RET + ARGLEN - 2;
		}
		if (FNDFLAGS[2] == 1 && NBR != -1 &&
		NBR > env->arglen && FNDFLAGS[9] == -1)
			RET = RET + ft_putspace(NBR - ARGLEN);
	}
	return (1);
}
