/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:01:47 by djoly             #+#    #+#             */
/*   Updated: 2018/02/22 10:56:35 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			print_zone_name(int i_zone)
{
	if (i_zone == 0)
		ft_printf("TINY : ");
	else if (i_zone == 1)
		ft_printf("SMALL : ");
	else if (i_zone == 2)
		ft_printf("LARGE : ");
}

int				find_fill_header(int i_zone)
{
	t_header	*tmp;
	t_zone		*zone;

	if (PTR_ZONE(i_zone) == NULL)
		return (FALSE);
	zone = PTR_ZONE(i_zone);
	while (zone)
	{
		tmp = zone->header;
		while (tmp != NULL)
		{
			if (tmp->free == 0)
				return (TRUE);
			tmp = tmp->next;
		}
		zone = zone->next;
	}
	return (FALSE);
}

void			print_zone(int i_zone)
{
	t_header	*tmp;
	t_zone		*zone;

	if (PTR_ZONE(i_zone) == NULL)
		return ;
	zone = PTR_ZONE(i_zone);
	if (find_fill_header(i_zone))
	{
		print_zone_name(i_zone);
		ft_printf("0x%X\n", zone->header);
	}
	while (zone)
	{
		tmp = zone->header;
		while (tmp != NULL)
		{
			if (tmp->free == 0)
				ft_printf("0x%X - 0x%X : %d octets\n", tmp + META,
				tmp + META + tmp->size, tmp->size);
			tmp = tmp->next;
		}
		zone = zone->next;
	}
}

/*
**	ft_printf("-----------------\nmalloc %d: Go show_alloc_mem \n", __LINE__);
*/

void			show_alloc_mem(void)
{
	print_zone(0);
	print_zone(1);
	print_zone(2);
}
