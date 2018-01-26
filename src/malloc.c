/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:22:49 by djoly             #+#    #+#             */
/*   Updated: 2018/01/26 11:26:10 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void 	*malloc(size_t size)
{
  ft_printf("woupi printf");
  t_header* tmp;

  if (size <= 0 || !ft_init_malloc(size))
    return NULL;

  ft_printf("ft_find_empty_head\n");
  if(!(tmp = ft_find_empty_head(size)))
  {
    ft_printf( "ft_set_header %p \n",(unsigned  long)(tmp));

    tmp = ft_set_header(tmp, size);
    ft_printf("fin ft_set_header\n");
    return (void*) tmp + TINY_SIZE;
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



  (void)size;

  return NULL;

  ft_printf("my ma lloc \n");
  ft_printf("%d",sizeof(struct s_header));
  void *base;

  base = mmap(0, getpagesize() * 4, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
  return base;
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
