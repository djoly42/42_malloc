/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:22:49 by djoly             #+#    #+#             */
/*   Updated: 2018/01/26 10:29:38 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void 	*malloc(size_t size)
{
  ft_printf("woupi printf");
  t_header* tmp;

  if (size <= 0 || !ft_init(size))
    return NULL;

  ft_putstr("ft_find_empty_head\n");
  if(!(tmp = ft_find_empty_head(size)))
  {
    ft_putstr("ft_set_header\n");
    ft_puthexa((unsigned  long)(tmp));
    ft_putstr("\n");

    tmp = ft_set_header(tmp, size);
    ft_putstr("fin ft_set_header\n");
    return (void*) tmp + TINY_SIZE;
  }

  //LOG
  if (size < TINY_SIZE)
    ft_putstr("size < tiny\n");

  if (glob.tiny == NULL){
    ft_putstr("tiny null\n");
  }else{
    ft_putstr("tiny \n");
  }
  ft_putnbr(PAGE_SIZE);
  ft_putstr("\nmeta : ");

  ft_putnbr(META);



  (void)size;

  return NULL;

  ft_putstr("my ma lloc \n");
  ft_putnbr(sizeof(struct s_header));
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
