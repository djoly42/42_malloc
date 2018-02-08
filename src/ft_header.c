/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:17:55 by djoly             #+#    #+#             */
/*   Updated: 2018/02/08 16:31:17 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
/*
//ft_printf("line: %d\n", __LINE__);
t_header* ft_find_head(t_header *head){
  ft_printf("ft_header %d: ft_find_head: %d\n", __LINE__, head);
  t_header * tmp;

  tmp = NULL;
  if (size < TINY_SIZE){
    ft_printf("line: %d\n", __LINE__);
    tmp = glob.tiny->header;
  }
  else if(size >= TINY_SIZE && size < SMALL_SIZE){
    ft_printf("line: %d\n", __LINE__);
    tmp = glob.small->header;
  }
  else{
    ft_printf("ft_header %d: ft_find_empty_head Gros malloc\n", __LINE__);

  }
    ft_printf("line: %d\n", __LINE__);
    ft_printf("line: %d\n", __LINE__);
    while (tmp != NULL){
      //ft_printf("line: %d\n", __LINE__);
        if(tmp->free != 1 && tmp->free != 0){
          ft_printf("ft_header %d: error dans tmp free \n", __LINE__);
          exit(1);
        }
        if(tmp->free == 1){
          ft_printf("ft_header %d: ft_find_empty_head return tmp\n",__LINE__);
          ft_print_head(tmp);
          return tmp;
        }
        tmp = tmp->next;
    }
  ft_printf("ft_header %d: ft_find_empty_head return NULL\n", __LINE__);
  return NULL;
}
*/
t_header* ft_find_empty_head(size_t size){
  ft_printf("ft_header %d: ft_find_empty_head\n", __LINE__);
  t_header * tmp;

  tmp = NULL;
  if (size < TINY_SIZE){
    ft_printf("line: %d\n", __LINE__);
    tmp = glob.tiny->header;
  }
  else if(size >= TINY_SIZE && size < SMALL_SIZE){
    ft_printf("line: %d\n", __LINE__);
    tmp = glob.small->header;
  }
  else{
    ft_printf("ft_header %d: ft_find_empty_head Gros malloc\n", __LINE__);

  }
    ft_printf("line: %d\n", __LINE__);
    ft_printf("line: %d\n", __LINE__);
    while (tmp != NULL){
      //ft_printf("line: %d\n", __LINE__);
        if(tmp->free != 1 && tmp->free != 0){
          ft_printf("ft_header %d: error dans tmp free \n", __LINE__);
          exit(1);
        }
        if(tmp->free == 1){
          ft_printf("ft_header %d: ft_find_empty_head return tmp\n",__LINE__);
          ft_print_head(tmp);
          return tmp;
        }
        tmp = tmp->next;
    }
  ft_printf("ft_header %d: ft_find_empty_head return NULL\n", __LINE__);
  return NULL;
}

t_header* ft_set_header(t_header* head, size_t size)
{
  ft_printf("ft_header %d: ft_set_header\n", __LINE__);
  ///ft_printf("set_free\n");
  head->free = 0;
//  ft_printf("set_size\n");
  head->size = size;
  return head;
}
