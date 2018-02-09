/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:18:19 by djoly             #+#    #+#             */
/*   Updated: 2018/02/09 15:21:27 by djoly            ###   ########.fr       */
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
  ft_printf("ft_init %d: ft_print_head ", __LINE__);
  if(h == NULL)
  {
    ft_printf("ft_init %d: h NULL <-----------------------------\n", __LINE__);
    return;
  }
  ft_printf(" %p\t", (unsigned long)(h));
  ft_printf("%d\t", h->free);
  ft_printf("%d\t", h->size);
  ft_printf("%p\n", h->next);
  // ft_printf("ft_init %d: %X\t%d\t%d\n", __LINE__,(unsigned long)(h),
              // h->free,h->size);

}

void ft_print_zone(t_zone* zone)
{
  ft_printf("-----------\n");
  ft_printf("ft_init %d: print zone \n", __LINE__);
  if (zone == NULL){
    ft_printf("ft_init %d: zone null\n", __LINE__);
    return;
  }
  t_header* tmp;
  int i;
  tmp = zone->header;
  ft_printf("ft_init %d: i\theader\t\ttmp\t\tfree\tsize\n", __LINE__),
  // ft_printf("ft_init %d: %X     %X\t%d\t%d\n", __LINE__, (unsigned  long)(glob.tiny->header),
  //             (unsigned long)(tmp),tmp->free,tmp->size);
  i = 0;
  while (tmp != NULL){
  ft_printf("ft_init %d: %i\t%p\t%p\t%d\t%d\t%p\t", __LINE__, i,  (unsigned  long)(zone->header),
               (unsigned long)(tmp),tmp->free,tmp->size, tmp->size );
  //ft_print_data((void *)tmp + TINY_SIZE);
  ft_printf("\n");
    tmp = tmp->next;
    i++;
  }

  ft_printf("ft_init %d: zone debut fin : %p %p\n", __LINE__, (unsigned long)zone, ((unsigned long)((void*)zone + PAGE_SIZE * 4)) );
  ft_printf("-----------\n");

}
