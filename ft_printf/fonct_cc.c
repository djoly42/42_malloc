/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_cc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 10:02:20 by djoly             #+#    #+#             */
/*   Updated: 2016/03/09 20:18:21 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_check_env(t_env *env)
{
	if (NBR != -1)
	{
		if (FNDFLAGS[1] == 1 && FNDFLAGS[2] == -1)
			ft_putzero(env);
		else
			RET = RET + ft_putspace(env->nbr - 1);
	}
}

int				fonct_cc(t_env *env)
{
	if (FNDFLAGS[2] == 1)
	{
		RET = RET + ft_put_w_char((wchar_t)ARG);
		ft_check_env(env);
	}
	else
	{
		ft_check_env(env);
		RET = RET + ft_put_w_char((wchar_t)ARG);
	}
	return (1);
}
