/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 10:43:34 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 13:30:10 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			inter_xprec(t_env *env)
{
	if (FNDFLAGS[2] == -1 && NBR != -1)
	{
		if (NBRPREC > ARGLEN && NBR > ARGLEN)
		{
			if (FNDFLAGS[1] == 1)
				RET = RET + ft_putzero2(NBR - ARGLEN);
			else
				RET = RET + ft_putspace(NBR - ARGLEN);
		}
		else if (NBRPREC != -1 && NBR > NBRPREC)
		{
			if (FNDFLAGS[1] == 1)
				RET = RET + ft_putzero2(NBR - NBRPREC);
			else
				RET = RET + ft_putspace(NBR - NBRPREC);
		}
	}
}

static void			x_prec(t_env *env)
{
	if (NBRPREC != -1)
	{
		inter_xprec(env);
		if (FNDFLAGS[9] == 1 && NBRPREC != -1)
			RET = RET + ft_putstr2((char *)ARG, NBRPREC);
		else
			RET = RET + ft_putstr((char *)ARG);
		if (FNDFLAGS[2] == 1 && NBR != -1 && NBRPREC != -1)
		{
			if (NBRPREC > ARGLEN)
				RET = RET + ft_putspace(NBR - ARGLEN);
			else
				RET = RET + ft_putspace(NBR - NBRPREC);
		}
	}
	else
	{
		if (FNDFLAGS[1] == 1)
			RET = RET + ft_putzero2(NBR);
		else
			RET = RET + ft_putspace(NBR);
	}
}

static void			inter_foncts(t_env *env)
{
	if (FNDFLAGS[2] == -1 && NBR > ARGLEN)
	{
		if (FNDFLAGS[1] == 1)
			RET = RET + ft_putzero2(NBR - ARGLEN);
		else
			RET = RET + ft_putspace(NBR - ARGLEN);
	}
	RET = RET + ft_putstr((char *)ARG);
	if (FNDFLAGS[2] == 1 && NBR > ARGLEN)
		RET = RET + ft_putspace(NBR - ARGLEN);
}

int					fonct_s(t_env *env)
{
	if (FNDFLAGS[6] == 1)
	{
		fonct_ss(env);
		return (1);
	}
	if (ARG != NULL)
		ARGLEN = ft_strlen((char *)ARG);
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{
		if (ARG == NULL)
		{
			RET += ft_putstr("(null)");
			return (0);
		}
		inter_foncts(env);
	}
	return (0);
}
