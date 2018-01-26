/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_oo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:03:36 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 13:11:06 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long int	ft_octalnbr(unsigned long int nb)
{
	if (nb > 7)
		return ((nb % 8) + 10 * ft_octalnbr(nb / 8));
	return (nb);
}

static void					inter_x_prec(t_env *env)
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
		RET = RET + ft_putoo((unsigned long int)ARG);
	}
	else
		RET = RET + ft_putspace(NBR);
}

static void					x_prec(t_env *env)
{
	if (NBRPREC != -1)
	{
		if (FNDFLAGS[2] != 1 && NBR > ARGLEN && NBRPREC < ARGLEN)
			RET = RET + ft_putspace(NBR - ARGLEN);
		else if (FNDFLAGS[2] != 1 && NBR > ARGLEN && NBRPREC < NBR)
			RET = RET + ft_putspace(NBR - NBRPREC);
		if (NBRPREC > env->arglen)
			RET = RET + ft_putzero2(NBRPREC - env->arglen);
		RET = RET + ft_putoo((unsigned long int)ARG);
		if (FNDFLAGS[2] == 1 && FNDFLAGS[9] == 1 && NBR > NBRPREC)
			RET = RET + ft_putspace(NBR - NBRPREC);
	}
	else if (NBR != -1)
		inter_x_prec(env);
	else if (FNDFLAGS[0] == 1)
	{
		if ((unsigned long int)ARG != 0)
			RET = RET + ft_putchar('0');
		RET = RET + ft_putoo((unsigned long int)ARG);
	}
}

static void					inter_putspace(t_env *env)
{
	if (FNDFLAGS[0] == 1)
		NBR = NBR - 1;
	RET = RET + ft_putspace(NBR - env->arglen);
}

int							fonct_oo(t_env *env)
{
	env->arglen = ft_nbrlenoo(ft_octalnbr((unsigned long int)ARG));
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{
		if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR != -1)
			inter_putspace(env);
		if (FNDFLAGS[2] != 1 && FNDFLAGS[1] == 1 && NBR != -1)
			RET = RET + ft_putzero2(NBR - env->arglen);
		if (FNDFLAGS[0] == 1)
			RET = RET + ft_putzero2(1);
		if (FNDFLAGS[7] == 1)
			RET = RET + ft_putoo((unsigned long int)ARG);
		else
			RET = RET + ft_putoo((unsigned long int)ARG);
		if (FNDFLAGS[2] == 1 && NBR != -1 && NBR > env->arglen)
			inter_putspace(env);
	}
	return (1);
}
