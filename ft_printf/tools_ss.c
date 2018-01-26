/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:17:44 by djoly             #+#    #+#             */
/*   Updated: 2016/03/09 17:12:34 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wcharlen(wchar_t c)
{
	if (c < 256)
		return (1);
	else if (c < 0x7FF)
		return (2);
	else if (c < 0xFFFF)
		return (3);
	return (4);
}

int		ft_put_wn_str(wchar_t *str, int n)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (*str != '\0')
		j = ft_wcharlen(*str);
	while (*str != '\0' && j <= n)
	{
		i += ft_put_w_char(*str);
		j = i + (ft_wcharlen(*str));
		if (j > n)
			return (i);
		str++;
	}
	return (i);
}

int		ft_put_w_str(wchar_t *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		i += ft_put_w_char(str[j]);
		j++;
	}
	return (i);
}

int		ft_wstrlen(wchar_t *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[j] != '\0')
	{
		i += ft_wcharlen(*str);
		j++;
	}
	return (i);
}

int		ft_arglens(t_env *env)
{
	if (FNDFLAGS[6] == 1)
		return (ft_wstrlen((wchar_t *)ARG));
	else
		return (ft_strlen((char *)ARG));
}
