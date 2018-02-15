/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:01:47 by djoly             #+#    #+#             */
/*   Updated: 2018/02/15 16:48:39 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		print_zone_name(int i_zone)
{
	if(i_zone == 0)
		ft_printf("TINY : ");
	else if(i_zone == 1)
		ft_printf("SMALL : ");
	else if(i_zone == 2)
		ft_printf("LARGE : ");
}

void		print_zone(int i_zone)
{
		t_header		*tmp;
		t_zone			*zone;
		int					i;

		i = 0;
		//ft_printf("ft_header %d: ft_find_empty_head\n", __LINE__);
		if (PTR_ZONE(i_zone) == NULL)
			return;
		zone = PTR_ZONE(i_zone);
		print_zone_name(i_zone);
		ft_printf("0x%X\n", zone->header);
		while(zone)
		{
			//ft_printf("ft_header %d: zone %d\n", __LINE__, i);
			tmp = zone->header;
			while (tmp != NULL)
			{
				if (tmp->free == 0)
					ft_printf("0x%X - 0x%X : %d octets\n", tmp + META, tmp + META + tmp->size, tmp->size);
				tmp = tmp->next;
			}
			i++;
			zone = zone->next;
		}
		//ft_printf("ft_header %d: ft_find_empty_head return NULL\n", __LINE__);
		return;
}

void		show_alloc_mem(void)
{
	ft_printf("-----------------\nmalloc %d: Go show_alloc_mem \n", __LINE__);
	print_zone(0);
	print_zone(1);
	print_zone(2);

}
