/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:30:41 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 14:58:12 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check_nbr(t_env *env)
{
	if (FORMAT[IFOR] >= '1' && FORMAT[IFOR] <= '9')
	{
		if (FNDFLAGS[9] == 1)
		{
			NBRPREC = ft_atoi(&FORMAT[IFOR]);
			IFOR = IFOR + ft_nbrlen(NBRPREC);
		}
		else
		{
			NBR = ft_atoi(&FORMAT[IFOR]);
			IFOR = IFOR + ft_nbrlen(NBR);
		}
		return (1);
	}
	return (0);
}

void		ft_re_init_env(t_env *env)
{
	int i;

	i = 0;
	ITOK = 0;
	NBR = -1;
	NBRPREC = -1;
	env->putneg = 0;
	env->arglen = 0;
	NBNEG = 0;
	while (i < 10)
	{
		FNDFLAGS[i] = -1;
		i++;
	}
}

void		ft_init_list2(t_env *env)
{
	env->fonction[0] = fonct_s;
	env->fonction[1] = fonct_ss;
	env->fonction[2] = fonct_p;
	env->fonction[3] = fonct_d;
	env->fonction[4] = fonct_dd;
	env->fonction[5] = fonct_d;
	env->fonction[6] = fonct_o;
	env->fonction[7] = fonct_oo;
	env->fonction[8] = fonct_u;
	env->fonction[9] = fonct_u;
	env->fonction[10] = fonct_x;
	env->fonction[11] = fonct_x;
	env->fonction[12] = fonct_c;
	env->fonction[13] = fonct_cc;
}

void		ft_init_env(t_env *env)
{
	int i;

	i = 0;
	ft_init_list2(env);
	IFOR = 0;
	ITOK = 0;
	NBR = -1;
	env->error = 0;
	env->putneg = 0;
	NBRPREC = -1;
	NBNEG = 0;
	while (i < 10)
	{
		FNDFLAGS[i] = -1;
		i++;
	}
	RET = 0;
}
