/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:22:49 by djoly             #+#    #+#             */
/*   Updated: 2018/01/12 13:50:51 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void 	*malloc(size_t size){
  if (size <= 0 || ft_init(size))
    return NULL;

  if(ft_init(size))
  {
    return NULL;
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
