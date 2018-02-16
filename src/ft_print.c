/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:18:19 by djoly             #+#    #+#             */
/*   Updated: 2018/02/16 16:02:30 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void ft_print_data(void *p){
  int i = 0;
  while(i < 128){
    ft_printf("%c", (char * ) p);
    p++;
    i++;
  }
}

void ft_print_head(t_header* h)
{
  ft_printf("ft_print %d: ft_print_head ", __LINE__);
  if(h == NULL)
  {
    ft_printf("ft_print %d: h NULL <-----------------------------\n", __LINE__);
    return;
  }
  ft_printf(" %p\t", (unsigned long)(h));
  ft_printf("%d\t", h->free);
  ft_printf("%d\t", h->size);
  ft_printf("%p\n", h->next);
  // ft_printf("ft_init %d: %X\t%d\t%d\n", __LINE__,(unsigned long)(h),
              // h->free,h->size);

}

void ft_print_zone(int i_zone)
{
	t_zone		*zone;
	t_header	*tmp;
	int				i;
	int				j;

	ft_printf("-----------\n");
	ft_printf("ft_print %d: print zone \n", __LINE__);
	zone = PTR_ZONE(i_zone);
	j = 0;
	i = 0;
	if (zone == NULL){
		ft_printf("ft_print %d: zone null\n", __LINE__);
		return;
	}
	while (zone)
	{
		tmp = zone->header;
		ft_printf("ft_print %d: zone %d index %d\n", __LINE__, i_zone, j),
		ft_printf("ft_print %d:\theader\t\ttmp\t\tfree\tsize\ti\n", __LINE__);
		while (tmp != NULL){
			ft_printf("ft_print %d:\t%p\t%p\t%d\t%d\t%p\t%i", __LINE__, (unsigned  long)(zone->header),
								(unsigned long)(tmp),tmp->free,tmp->size, tmp->size, i);
			ft_printf("\n");
			tmp = tmp->next;
			i++;
  	}
		j++;
		zone = zone->next;
	}
	ft_printf("ft_print %d: zone debut fin : %p %p\n", __LINE__, (unsigned long)zone, ((unsigned long)((void*)zone + PAGE_SIZE * 4)) );
	ft_printf("-----------\n");
}
