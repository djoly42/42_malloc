/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 10:54:17 by djoly             #+#    #+#             */
/*   Updated: 2016/03/09 15:07:41 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putzero2(int nbr)
{
	int i;

	i = -1;
	while (++i < nbr)
		ft_putchar('0');
	return (nbr);
}

int	ft_putspace(int nbr)
{
	int i;

	i = -1;
	while (++i < nbr)
		ft_putchar(' ');
	return (nbr);
}
