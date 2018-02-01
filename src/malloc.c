/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:22:49 by djoly             #+#    #+#             */
/*   Updated: 2018/02/01 17:49:12 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void 	*malloc(size_t size)
{
  ft_printf("------------------\nmalloc %d: Go malloc: %u\n", __LINE__, size);
  t_header* tmp;

  if (size <= 0 || !ft_init_malloc(size))
    return NULL;

  //ft_printf("malloc %d: ft_find_empty_head\n", __LINE__);
  if((tmp = ft_find_empty_head(size)) != NULL)
  {
    //ft_printf("malloc %d: tmp : %p\n", __LINE__, tmp);

    tmp = ft_set_header(tmp, size);
    ft_printf("malloc %d: tmp: %p return malloc: %p\n", __LINE__, tmp, ((void*) tmp + TINY_SIZE));
    ft_printf("-----------\n");

  ft_print_zone(glob.tiny);
    return (void*) tmp + TINY_SIZE;
  }
  else
  {
    ft_printf("malloc: ft_find_empty_head NULL\n");
  }


  //LOG
  if (size < TINY_SIZE)
    ft_printf("size < tiny\n");

  if (glob.tiny == NULL){
    ft_printf("tiny null\n");
  }else{
    ft_printf("tiny \n");
  }
  ft_printf("%d", PAGE_SIZE);
  ft_printf("\nmeta : ");

  ft_printf("%d", META);
  return NULL;
}

void free(void *ptr){
  (void)ptr;
}

void *realloc(void *ptr, size_t size){
  (void)ptr;
  (void)size;
  return ptr;
}

void show_alloc_mem(){
  return;
}
