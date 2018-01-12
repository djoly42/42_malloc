/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:17:55 by djoly             #+#    #+#             */
/*   Updated: 2018/01/12 16:48:36 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_header* ft_find_empty_head(size_t size){
  t_header * tmp;
  if (size < TINY){
    tmp = glob.tiny->header;
    while (tmp != NULL){
        if(tmp->free == 1)
          return tmp;
    }
  }
  return NULL;
}

t_header* ft_set_header(t_header* head, size_t size)
{
  ft_putstr("set_free\n");
  head->free = 0;
  ft_putstr("set_size\n");
  head->size = size;
  return head;
}
