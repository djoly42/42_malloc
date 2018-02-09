/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:17:55 by djoly             #+#    #+#             */
/*   Updated: 2018/02/09 17:02:47 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

//ft_printf("line: %d\n", __LINE__);
int ft_find_data(void *data){
  ft_printf("ft_header %d: ft_find_head: %p\n", __LINE__, data);
  t_header *head;
  int i;
  i = 0;

  while (i < 3){
    if(PTR_ZONE(i) == NULL)
    {
      i++;
      continue;
    }
    head = PTR_ZONE(i)->header;
    while(head){
      if (((void *)head + META) == data){
        return 1;
      }
      head = head->next;
    }
    i++;
  }
  return 0;
}

t_header*		ft_find_empty_head(int i_zone)
{
	t_header		*tmp;
	t_zone			*zone;
	int					i;

	i = 0;
	ft_printf("ft_header %d: ft_find_empty_head\n", __LINE__);
	if (PTR_ZONE(i_zone) == NULL)
		return (NULL);
	zone = PTR_ZONE(i_zone);
	while(zone)
	{
		ft_printf("ft_header %d: zone %d\n", __LINE__, i);
		tmp = zone->header;
		while (tmp != NULL)
		{
			if(tmp->free != 1 && tmp->free != 0)
				ft_printf("ft_header %d: error dans tmp free \n", __LINE__);
			if(tmp->free == 1)
			{
				ft_printf("ft_header %d: ft_find_empty_head return tmp\n",__LINE__);
				ft_print_head(tmp);
				return (tmp);
			}
			tmp = tmp->next;
		}
		i++;
		zone = zone->next;
	}
	ft_printf("ft_header %d: ft_find_empty_head return NULL\n", __LINE__);
	return (NULL);
}

t_header*		ft_set_header(t_header* head, size_t size)
{
	ft_printf("ft_header %d: ft_set_header\n", __LINE__);
	head->free = 0;
	head->size = size;
	return head;
}
