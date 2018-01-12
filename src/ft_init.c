/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:24:43 by djoly             #+#    #+#             */
/*   Updated: 2018/01/12 15:02:50 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


void ft_init_list_head(int type, t_zone* add_zone){
  int i;
  t_header* tmp;
  if (type == TINY){
    ft_putstr("header :");
    ft_puthexa((unsigned  long)(glob.tiny->header));
    glob.tiny->header = (void *) add_zone;
    ft_putstr(" --- ");
    ft_puthexa((unsigned  long)(glob.tiny->header));
    ft_putstr("\n");
  }
  i = 0;
  while(i < 100)
  {
    tmp = glob.tiny->header;
    glob.tiny->header


    i++;
  }

}

int ft_init_zone(int size_type)
{
  if (size_type == TINY)
  {
    ft_putstr("init tiny\n");
    ft_puthexa((unsigned  long)(glob.tiny));
    ft_putstr("\n");

    if (!(glob.tiny = mmap(0, PAGE_SIZE * 4, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
    {
      ft_putstr("error in mmap");
      return FALSE;
    }
    ft_init_list_head(TINY, glob.tiny);

    ft_puthexa((unsigned  long)(glob.tiny));
      ft_putstr("\nfin exa \n");
  }
  else if(size_type == SMALL)
  {
    ft_putstr("init tiny\n");
    if (!(glob.small = mmap(0, PAGE_SIZE * 26, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
    {
      ft_putstr("error in mmap");
      return FALSE;
    }
  }
  else if(size_type == LARGE)
  {
    ft_putstr("init tiny\n");
    if (!(glob.large = mmap(0, PAGE_SIZE * 26, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
    {
      ft_putstr("error in mmap");
      return FALSE;
    }
  }
    return TRUE;
}

int ft_init(size_t size){

  if ((size < TINY_SIZE) && (glob.tiny == NULL))
  {
    return ft_init_zone(TINY);
    //base = mmap(0, getpagesize() * 4, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
  }
    ft_putstr("end ft_init\n");
    return TRUE;
}
