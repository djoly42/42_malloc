/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:17:55 by djoly             #+#    #+#             */
/*   Updated: 2018/01/26 13:17:15 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_header* ft_find_empty_head(size_t size){
  t_header * tmp;
  //ft_printf("ft_header: ft_find_empty_head size: %d, tiny: %d\n", size, TINY_SIZE);

  if (size < TINY_SIZE){
    tmp = glob.tiny->header;
    //ft_printf("ft_header: ft_find_empty_head tmp %p\n", tmp);
    while (tmp != NULL){
        if(tmp->free == 1){
          ft_printf("ft_header: ft_find_empty_head return tmp\n");
          return tmp;
        }
    }
  }
  ft_printf("ft_header: ft_find_empty_head return NULL\n");
  return NULL;
}

t_header* ft_set_header(t_header* head, size_t size)
{
  ///ft_printf("set_free\n");
  head->free = 0;
//  ft_printf("set_size\n");
  head->size = size;
  return head;
}
