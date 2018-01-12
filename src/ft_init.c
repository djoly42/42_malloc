/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:24:43 by djoly             #+#    #+#             */
/*   Updated: 2018/01/12 17:05:35 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void ft_print_zone(t_zone* zone)
{
  t_header* tmp;
  int i;
  ft_putstr("print zone \n");
//  tmp = zone->header;
ft_puthexa((unsigned  long)(glob.tiny->header));

  tmp = glob.tiny->header;
  i = 0;
  while (tmp != NULL){
    ft_putnbr(i);
    ft_putstr("\t\t");
    ft_puthexa((unsigned long)(tmp));
    ft_putstr("\t");
    ft_putnbr(tmp->free);
    ft_putstr("\t");
    ft_putnbr(tmp->size);
    ft_putstr("\n");


    tmp = tmp->next;
    i++;
  }

  ft_putstr("zone debut fin :");
  ft_puthexa((unsigned long)zone);
  ft_putstr(" ");
  ft_puthexa((unsigned long)((void*)zone + PAGE_SIZE * 4));
  ft_putstr("\n");

}

void ft_init_list_head(int type, t_zone* add_zone){
  ft_putstr("add_zone :");

  ft_puthexa((unsigned  long)(add_zone));
  ft_putstr("\n");

  int i;
  t_header* tmp;
  if (type == TINY){
    ft_putstr("header first :");
    ft_puthexa((unsigned  long)(glob.tiny->header));
    glob.tiny->header = (void *) add_zone;
    ft_putstr(" --- ");
    ft_puthexa((unsigned  long)(glob.tiny->header));
    ft_putstr("\n");
  }
  i = 1;
  tmp = glob.tiny->header;
  ft_putstr("header first again :");
  ft_puthexa((unsigned  long)(glob.tiny->header));
  ft_putstr("\n");
  tmp->free = 1;
  tmp->size = 0;
  ft_putstr("header first again :");
  ft_puthexa((unsigned  long)(glob.tiny->header));
  ft_putstr("\n");
  while(i < 100)
  {

    ft_putstr("header :");
    ft_puthexa((unsigned  long)(tmp->next));
    tmp->next = (void*)tmp + META + TINY_SIZE;
    ft_putstr(" --- ");
    ft_puthexa((unsigned  long)(tmp->next));
    ft_putstr("\n");
    tmp = tmp->next;
    tmp->free = 1;
    tmp->size = 0;

    i++;
  }
  tmp->next = NULL;
  ft_putstr("header first again :");
  ft_puthexa((unsigned  long)(glob.tiny->header));
  ft_putstr("\n");

  ft_print_zone(glob.tiny);

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
