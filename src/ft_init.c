/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:24:43 by djoly             #+#    #+#             */
/*   Updated: 2018/02/22 13:30:29 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int				ft_which_zone(size_t size)
{
	if (size <= TINY_SIZE)
		return (0);
	else if (size <= SMALL_SIZE)
		return (1);
	return (2);
}

void			ft_init_list_head(int i_zone, t_zone *add_zone)
{
	int			i;
	t_header	*tmp;
	t_header	*tmpfirst;

	tmp = NULL;
	add_zone->header = (void *)add_zone + sizeof(struct s_zone);
	tmp = add_zone->header;
	tmpfirst = add_zone->header;
	i = 1;
	tmp->free = 1;
	tmp->size = 0;
	while (i < (int)LIST_CALC(i_zone))
	{
		tmp->next = ((void *)tmp + META + DATA_CALC(i_zone));
		tmp = tmp->next;
		tmp->free = 1;
		tmp->size = 0;
		i++;
	}
	tmp->next = NULL;
}

int				ft_page_calc(size_t size, int i_zone)
{
	int			ret;

	if (i_zone == LARGE)
	{
		ret = (size / PAGE_SIZE);
		ret = (PAGE_SIZE * (ret + 1));
		if (PRINT)
			ft_printf("ft_init %d: ft_page_calc %u\n", __LINE__, ret);
		return (ret);
	}
	return (MMAP_CALC(i_zone));
}

int				ft_init_zone(size_t size, int i_zone)
{
	t_zone		*zone;

	zone = PTR_ZONE(i_zone);
	while (zone->next != NULL)
	{
		zone = zone->next;
	}
	if (!(zone->next = mmap(0, ft_page_calc(size, i_zone), PROT_READ |
	PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
	{
		ft_printf("error in mmap");
		return (FALSE);
	}
	zone = zone->next;
	ft_init_list_head(i_zone, zone);
	return (TRUE);
}

int				ft_init_malloc(size_t size, int i_zone)
{
	t_zone		*zone;
	int			i;

	i = 0;
	if (PTR_ZONE(i_zone) == NULL)
	{
		if (!(PTR_ZONE(i_zone) = mmap(0, ft_page_calc(size, i_zone),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		{
			ft_printf("error in mmap");
			return (FALSE);
		}
		zone = PTR_ZONE(i_zone);
		ft_init_list_head(i_zone, zone);
		return (TRUE);
	}
	return (ft_init_zone(size, i_zone));
}
