/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:22:49 by djoly             #+#    #+#             */
/*   Updated: 2018/01/11 17:09:59 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void 	*malloc(size_t size){

//  t_header h;

  (void)size;
  ft_putstr("my ma lloc \n");
  ft_putnbr(sizeof(struct s_header));
  void *base;

  base = mmap(0, getpagesize() * 2, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
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
