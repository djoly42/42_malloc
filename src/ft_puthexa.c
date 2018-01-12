/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:14:03 by djoly             #+#    #+#             */
/*   Updated: 2018/01/12 14:31:34 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		ft_puthexa(size_t ptr)
{
	size_t	i;

	i = 0;
	if (ptr)
	{
		i = ptr / 16;
		ft_puthexa(i);
		if (ptr % 16 < 10)
			ft_putchar('0' + ptr % 16);
		else
			ft_putchar('a' + (ptr % 16) - 10);
	}
	else
		ft_putstr("0x" );
}
