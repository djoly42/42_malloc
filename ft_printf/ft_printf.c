/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:40:46 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 14:22:42 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_check_flags(t_env *env)
{
	int		ifind;
	char	*find;

	ifind = 0;
	if ((find = ft_strchr(FLAGS, FORMAT[IFOR])))
	{
		ifind = find - FLAGS;
		if (ifind == 5 && FORMAT[IFOR + 1] == 'h')
		{
			FNDFLAGS[ifind] = 2;
			IFOR = IFOR + 1;
		}
		else if (ifind == 6 && FORMAT[IFOR + 1] == 'l')
		{
			FNDFLAGS[ifind] = 2;
			IFOR = IFOR + 1;
		}
		else
			FNDFLAGS[ifind] = 1;
		IFOR = IFOR + 1;
		return (1);
	}
	return (0);
}

static int		test_format(t_env *env, int *ifind, char **find)
{
	while (!(*find = ft_strchr(TOKEN, FORMAT[IFOR])))
	{
		if (FORMAT[IFOR] == '\0')
			return (0);
		if (!(*ifind = ft_check_nbr(env)))
			*ifind = ft_check_flags(env);
		if (!(*ifind))
		{
			if (FORMAT[IFOR] == '%')
			{
				print_percent(env);
				ft_re_init_env(env);
			}
			else
			{
				env->error = 1;
				fonct_error(env);
				return (0);
			}
			IFOR = IFOR + 1;
		}
		if (FORMAT[IFOR] == '\0')
			return (0);
	}
	return (1);
}

int				ft_check_token(t_env *env)
{
	char	*find;
	int		ifind;

	IFOR = IFOR + 1;
	ifind = 0;
	if (env->error == 0)
		ARG = va_arg(AP, void *);
	else
		env->error = 0;
	if (test_format(env, &ifind, &find) == 0)
		return (0);
	ITOK = find - TOKEN;
	env->fonction[ITOK](env);
	return (1);
}

void			run_format(t_env *env)
{
	while (FORMAT[IFOR] != '\0')
	{
		if (FORMAT[IFOR] == '%')
		{
			if (FORMAT[IFOR + 1] == '\0')
				return ;
			else if (FORMAT[IFOR + 1] == '%')
			{
				RET = RET + ft_putchar('%');
				IFOR = IFOR + 1;
			}
			else
				ft_check_token(env);
			if (FORMAT[IFOR] == '\0')
				return ;
			ft_re_init_env(env);
		}
		else
		{
			RET = RET + ft_putchar(FORMAT[IFOR]);
		}
		IFOR = IFOR + 1;
	}
}

int				ft_printf(const char *format, ...)
{
	t_env		env;

	env.format = format;
	ft_init_env(&env);
	va_start(env.ap, format);
	run_format(&env);
	va_end(env.ap);
	return (env.ret);
}
