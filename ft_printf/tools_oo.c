/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_oo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:08:44 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 13:09:14 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_putoo(unsigned long int nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 7)
	{
		ret = ret + ft_putoo(nbr / 8);
		ret = ret + ft_putoo(nbr % 8);
	}
	else
		ret = ret + ft_putchar(nbr + '0');
	return (ret);
}

int					ft_nbrlenoo(unsigned long int nb)
{
	int i;

	i = 1;
	while (nb /= 8)
		i++;
	return (i);
}
