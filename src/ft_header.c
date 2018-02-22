/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:17:55 by djoly             #+#    #+#             */
/*   Updated: 2018/02/22 12:08:40 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*ft_find_data(void *data)
{
	t_header	*head;
	int			i_zone;
	t_zone		*zone;

	i_zone = -1;
	while (++i_zone < 3)
	{
		zone = PTR_ZONE(i_zone);
		while (zone)
		{
			head = zone->header;
			while (head)
			{
				if (((void *)head + META) == data)
				{
					return (head);
				}
				head = head->next;
			}
			zone = zone->next;
		}
	}
	return (NULL);
}

int				ft_which_type(t_header *src)
{
	t_header	*head;
	int			i_zone;
	t_zone		*zone;

	i_zone = -1;
	while (++i_zone < 3)
	{
		if (PTR_ZONE(i_zone) == NULL)
			continue;
		zone = PTR_ZONE(i_zone);
		while (zone)
		{
			head = zone->header;
			while (head)
			{
				if (head == src)
				{
					return (i_zone);
				}
				head = head->next;
			}
			zone = zone->next;
		}
	}
	return (-1);
}

t_header		*ft_find_empty_head(int i_zone, size_t size)
{
	t_header	*tmp;
	t_zone		*zone;
	int			i;

	i = 0;
	if (PTR_ZONE(i_zone) == NULL)
		return (NULL);
	zone = PTR_ZONE(i_zone);
	while (zone)
	{
		tmp = zone->header;
		while (tmp != NULL)
		{
			if (i_zone != LARGE && tmp->free == 1)
				return (tmp);
			else if (tmp->free == 1 && (tmp->first_size == 0 ||
				tmp->first_size >= size))
				return (tmp);
			tmp = tmp->next;
		}
		i++;
		zone = zone->next;
	}
	return (NULL);
}

t_header		*ft_set_header(t_header *head, size_t size, int i_zone)
{
	head->free = 0;
	head->size = size;
	if (i_zone == LARGE && head->first_size == 0)
	{
		head->first_size = size;
	}
	return (head);
}
