/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:18:19 by djoly             #+#    #+#             */
/*   Updated: 2018/02/22 11:48:11 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			ft_print_data(void *p)
{
	int		i;

	i = 0;
	while (i < 128)
	{
		ft_printf("%c", (char *)p);
		p++;
		i++;
	}
}

void			ft_print_head(t_header *h)
{
	if (h == NULL)
		return ;
	ft_printf(" %p\t", (unsigned long)(h));
	ft_printf("%d\t", h->free);
	ft_printf("%d\t", h->size);
	ft_printf("%p\n", h->next);
}

void			ft_print_one_zone(t_zone *zone, int i_zone)
{
	t_header	*tmp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (zone)
	{
		tmp = zone->header;
		ft_printf("ft_print %d: zone %d index %d\n", __LINE__, i_zone, j);
		ft_printf("ft_print %d:\theader\t\ttmp\t\tfree\tsize\ti\t\tfirst_size\
		\n", __LINE__);
		while (tmp != NULL)
		{
			ft_printf("ft_print %d:\t%p\t%p\t%d\t%d\t%p\t%i\t%u\n", __LINE__,
			(unsigned long)(zone->header), (unsigned long)(tmp), tmp->free,
			tmp->size, tmp->size, i, tmp->first_size);
			tmp = tmp->next;
			i++;
		}
		j++;
		zone = zone->next;
	}
}

void			ft_print_zone(int i_zone)
{
	t_zone		*zone;

	zone = PTR_ZONE(i_zone);
	if (zone == NULL)
		return ;
	ft_print_one_zone(zone, i_zone);
	ft_printf("ft_print %d: zone debut fin : %p %p\n", __LINE__,
	(unsigned long)zone, ((unsigned long)((void*)zone + PAGE_SIZE * 4)));
}
