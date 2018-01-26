/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:14:24 by djoly             #+#    #+#             */
/*   Updated: 2016/03/09 20:21:51 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putzero3(t_env *env)
{
	int i;

	i = -1;
	while (++i < (NBR - 1))
		RET = RET + ft_putchar('0');
}

static void		ft_check_env(t_env *env)
{
	if (NBR != -1)
	{
		if (FNDFLAGS[1] == 1 && FNDFLAGS[2] == -1)
			ft_putzero3(env);
		else
			RET = RET + ft_putspace(env->nbr - 1);
	}
}

int				fonct_c(t_env *env)
{
	if (FNDFLAGS[2] == 1)
	{
		if (FNDFLAGS[6] == 1)
			RET = RET + ft_put_w_char((wchar_t)ARG);
		else
			RET = RET + ft_putchar((char)ARG);
		ft_check_env(env);
	}
	else
	{
		ft_check_env(env);
		if (FNDFLAGS[6] == 1)
			RET = RET + ft_put_w_char((wchar_t)ARG);
		else
			RET = RET + ft_putchar((char)ARG);
	}
	return (1);
}
