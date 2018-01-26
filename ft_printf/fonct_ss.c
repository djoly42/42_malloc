/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:00:07 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 13:32:18 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_wnstrlen(wchar_t *str, int n)
{
	int i;

	i = 0;
	if (*str != '\0')
		i = ft_wcharlen(*str);
	str++;
	while (*str != '\0' && i <= n)
	{
		i += ft_wcharlen(*str);
		if (i > n)
			return (i - ft_wcharlen(*str));
		str++;
	}
	return (i);
}

static void		inter_xprec(t_env *env)
{
	NBRPREC = ft_wnstrlen((wchar_t *)ARG, NBRPREC);
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

static void		x_prec(t_env *env)
{
	if (NBRPREC != -1)
	{
		inter_xprec(env);
		if (FNDFLAGS[9] == 1 && NBRPREC != -1)
			RET = RET + ft_put_wn_str((wchar_t *)ARG, NBRPREC);
		else
			RET = RET + ft_put_w_str((wchar_t *)ARG);
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

int				fonct_ss(t_env *env)
{
	if (ARG != NULL)
		ARGLEN = ft_wstrlen((wchar_t *)ARG);
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{
		if (ARG == NULL)
		{
			RET += ft_putstr("(null)");
			return (0);
		}
		if (FNDFLAGS[2] == -1 && NBR > ARGLEN)
		{
			if (FNDFLAGS[1] == 1)
				RET = RET + ft_putzero2(NBR - ARGLEN);
			else
				RET = RET + ft_putspace(NBR - ARGLEN);
		}
		RET = RET + ft_put_w_str((wchar_t *)ARG);
		if (FNDFLAGS[2] == 1 && NBR > ARGLEN)
			RET = RET + ft_putspace(NBR - ARGLEN);
	}
	return (0);
}
