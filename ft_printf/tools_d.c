/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 20:05:41 by djoly             #+#    #+#             */
/*   Updated: 2016/03/09 20:34:11 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putzero(t_env *env)
{
	int i;

	if ((int)ARG < 0 && env->putneg != 1)
	{
		RET = RET + ft_putchar('-');
		env->nbneg = (-1) * (int)env->arg;
		env->putneg = 1;
	}
	if (NBR != -1)
		NBR = NBR - ft_nbrlen((int)ARG);
	i = -1;
	while (++i < NBR)
		RET = RET + ft_putchar('0');
}

void		ft_which_putnbrnegd(t_env *env)
{
	if (FNDFLAGS[5] == -1 && FNDFLAGS[6] == -1 && FNDFLAGS[7] == -1 &&
	FNDFLAGS[8] == -1 && (int)ARG < 0)
		RET = RET + ft_putnbr((int)NBNEG);
	else if (FNDFLAGS[6] == 1)
		RET = RET + ft_putnbr((long int)NBNEG);
	else if (FNDFLAGS[6] == 2)
		RET = RET + ft_putnbr((long long int)NBNEG);
	else if (FNDFLAGS[8] == 1)
		RET = RET + ft_putnbr((size_t)NBNEG);
	else if (FNDFLAGS[5] == 2)
		RET = RET + ft_putnbr((signed char)NBNEG);
	else if (FNDFLAGS[7] == 1)
		RET = RET + ft_putnbr((intmax_t)NBNEG);
	else if (FNDFLAGS[5] == 1)
		RET = RET + ft_putnbr((short int)NBNEG);
	else
		RET = RET + ft_putnbr((int)NBNEG);
}

void		ft_which_putnbrd(t_env *env)
{
	if (FNDFLAGS[5] == -1 && FNDFLAGS[6] == -1 && FNDFLAGS[7] == -1 &&
	FNDFLAGS[8] == -1 && (int)ARG < 0)
		RET = RET + ft_putnbr((int)ARG);
	else if (FNDFLAGS[6] == 1)
		RET = RET + ft_putnbr((long int)ARG);
	else if (FNDFLAGS[6] == 2)
		RET = RET + ft_putnbr((long long int)ARG);
	else if (FNDFLAGS[8] == 1)
		RET = RET + ft_putnbr((size_t)ARG);
	else if (FNDFLAGS[5] == 2)
		RET = RET + ft_putnbr((signed char)ARG);
	else if (FNDFLAGS[7] == 1)
		RET = RET + ft_putnbr((intmax_t)ARG);
	else if (FNDFLAGS[5] == 1)
		RET = RET + ft_putnbr((short int)ARG);
	else
		RET = RET + ft_putnbr((int)ARG);
}

void		is_neg(t_env *env)
{
	if ((int)ARG < 0 && env->putneg != 1)
	{
		RET = RET + ft_putchar('-');
		env->nbneg = (-1) * (int)env->arg;
		env->putneg = 1;
	}
}

void		before_nbrd_prec(t_env *env)
{
	if (NBR >= ARGLEN && NBR > NBRPREC && FNDFLAGS[2] == -1)
	{
		if (FNDFLAGS[3] == 1)
			NBR = NBR - 1;
		if ((int)ARG < 0 && ARGLEN <= NBRPREC)
			NBR = NBR - 1;
		if (NBRPREC >= ARGLEN)
			RET = RET + ft_putspace(NBR - NBRPREC);
		else if ((int)ARG == 0 && NBRPREC == -1)
			RET = RET + ft_putspace(NBR);
		else if (ARGLEN > NBRPREC)
			RET = RET + ft_putspace(NBR - ARGLEN);
	}
	if (FNDFLAGS[3] == 1)
		RET = RET + ft_putchar('+');
	if (NBRPREC >= ARGLEN)
	{
		is_neg(env);
		if (NBRPREC == ARGLEN && env->putneg == 1)
			RET = RET + ft_putzero2(1);
		else if (NBRPREC > ARGLEN && env->putneg == 1)
			RET = RET + ft_putzero2(NBRPREC - ARGLEN + 1);
		else
			RET = RET + ft_putzero2(NBRPREC - ARGLEN);
	}
}
