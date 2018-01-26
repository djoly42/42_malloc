/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:17:06 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 15:57:08 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int			neg;
	long long	number;
	int			i;

	neg = 0;
	number = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10;
		number = number + (str[i] - 48);
		i++;
	}
	if (number > ((long long)INT_MAX + 1) || (number == ((long long)INT_MAX + 1)
	&& !neg))
		exit(ft_putstr("Error: des paramètres plus grand que l'int\n"));
	if (neg)
		return (-number);
	return (number);
}
