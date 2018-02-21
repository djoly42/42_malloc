/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:17:55 by djoly             #+#    #+#             */
/*   Updated: 2018/02/21 15:20:41 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_find_data(void *data){
  ft_printf("ft_header %d: ft_find_data: %p\n", __LINE__, data);
  t_header *head;
  int i_zone;
	t_zone			*zone;

	i_zone = -1;
  while (i_zone < 3){
    i_zone++;
  	//ft_printf("ft_header %d: while i zone %d\n", __LINE__, i_zone);
    if(PTR_ZONE(i_zone) == NULL)
      continue;
		zone = PTR_ZONE(i_zone);
		while(zone){
  	//ft_printf("ft_header %d: while zone %p\n", __LINE__, zone);
    	head = zone->header;
    	while(head){
  		//	ft_printf("ft_header %d: while head %p\n", __LINE__, head);
      	if (((void *)head + META) == data){
  			//	ft_printf("ft_header %d: ft_find_data return %p\n", __LINE__, head);
        	return head;
      	}
      	head = head->next;
    	}
			zone = zone->next;
		}
  }

	// ft_print_zone(TINY);
	// ft_print_zone(SMALL);
	// ft_print_zone(LARGE);
  ft_printf("ft_header %d: ft_find_data return NULL data search %p\n", __LINE__, data);
  return (NULL);
}

int		ft_which_type(t_header *src){
  //ft_printf("ft_header %d: ft_which_type: %p\n", __LINE__, src);
  t_header *head;
  int i_zone;
	t_zone			*zone;

	i_zone = -1;
  while (i_zone < 3){
    i_zone++;
  	//ft_printf("ft_header %d: before if\n", __LINE__);
    if(PTR_ZONE(i_zone) == NULL)
      continue;
  	//ft_printf("ft_header %d: after if\n", __LINE__);
		zone = PTR_ZONE(i_zone);
  	//ft_printf("ft_header %d: before while zone\n", __LINE__);
		while(zone){
    	head = zone->header;
    	while(head){
      	if (head == src){
        	return i_zone;
      	}
      	head = head->next;
    	}
			zone = zone->next;
		}
  	//ft_printf("ft_header %d: after while zone\n", __LINE__);
  }
  return (-1);
}

t_header*		ft_find_empty_head(int i_zone, size_t size)
{
	t_header		*tmp;
	t_zone			*zone;
	int					i;

	i = 0;
	//ft_printf("ft_header %d: ft_find_empty_head\n", __LINE__);
	if (PTR_ZONE(i_zone) == NULL)
		return (NULL);
	zone = PTR_ZONE(i_zone);
	while(zone)
	{
		//ft_printf("ft_header %d: zone %d\n", __LINE__, i);
		tmp = zone->header;
		while (tmp != NULL)
		{
			if(i_zone != LARGE && tmp->free == 1)
			{
				//ft_printf("ft_header %d: ft_find_empty_head return tmp\n",__LINE__);
				//ft_print_head(tmp);
				return (tmp);
			}
			else if (tmp->free == 1 && (tmp->first_size == 0 || tmp->first_size >= size))
			{
				return (tmp);
			}
			tmp = tmp->next;
		}
		i++;
		zone = zone->next;
	}
	//ft_printf("ft_header %d: ft_find_empty_head return NULL\n", __LINE__);
	return (NULL);
}

t_header*		ft_set_header(t_header* head, size_t size, int i_zone)
{
	//ft_printf("ft_header %d: ft_set_header\n", __LINE__);
	head->free = 0;
	head->size = size;
	if(i_zone == LARGE && head->first_size == 0){
		head->first_size = size;
	}
	return head;
}
