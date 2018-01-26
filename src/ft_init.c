/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:24:43 by djoly             #+#    #+#             */
/*   Updated: 2018/01/26 11:25:08 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void ft_print_zone(t_zone* zone)
{
  t_header* tmp;
  int i;
  ft_printf("print zone \n");
//  tmp = zone->header;
ft_printf("%X", (unsigned  long)(glob.tiny->header));

  tmp = glob.tiny->header;
  ft_printf("%X", (unsigned long)(tmp));
  ft_printf("\t:");
  ft_printf("%d", tmp->free);
  ft_printf("\t:");
  ft_printf("%d", tmp->size);
  ft_printf("\n");
  i = 0;
  while (tmp != NULL){
    ft_printf("%d", i);
    ft_printf("\t\t");
    ft_printf("%p", (unsigned long)(tmp));
    ft_printf("\t");
    ft_printf("%d", tmp->free);
    ft_printf("\t");
    ft_printf("%d", tmp->size);
    ft_printf("\n");


    tmp = tmp->next;
    i++;
  }

  ft_printf("zone debut fin :");
  ft_printf("%p", (unsigned long)zone);
  ft_printf(" ");
  ft_printf("%p", (unsigned long)((void*)zone + PAGE_SIZE * 4));
  ft_printf("\n");

}

void ft_init_list_head(int type, t_zone* add_zone){
  ft_printf("add_zone :");

  ft_printf("%p", (unsigned  long)(add_zone));
  ft_printf("\n");

  int i;
  t_header* tmp;
  t_header* tmpfirst;

  if (type == TINY){
    ft_printf("header first :");
    ft_printf("%X", (unsigned  long)(glob.tiny->header));
    glob.tiny->header = (void *) add_zone;
    ft_printf(" --- ");
    ft_printf("%X", (unsigned  long)(glob.tiny->header));
    ft_printf("\n");
  }
  i = 1;
  tmp = glob.tiny->header;
  tmpfirst = glob.tiny->header;

  ft_printf("header first again :");
  ft_printf("%X", (unsigned  long)(glob.tiny->header));
  ft_printf("\n");
  ft_printf("free");
  ft_printf("%X", (unsigned  long)(&tmp->free));
  ft_printf("\n");
  ft_printf("size");
  ft_printf("%X", (unsigned  long)(&tmp->size));
  ft_printf("\n");
  tmp->free = 1;
  tmp->size = 0;
  ft_printf("header first again :");
  ft_printf("%X", (unsigned  long)(glob.tiny->header));
  ft_printf("\n");
  //return ;
  while(i < 100)
  {

    ft_printf("header :");
    ft_printf("%p", (unsigned  long)(tmp));
    ft_printf("\t");
    ft_printf("%d", tmp->free);
    ft_printf("\t");
    ft_printf("%d", tmp->size);
    ft_printf("\t");
    tmp->next = (void*)tmp + META + TINY_SIZE;
    ft_printf(" --- ");
    ft_printf("%X", (unsigned  long)(tmp->next));
    ft_printf("\n");
    tmp = tmp->next;
    tmp->free = 1;
    tmp->size = 0;

    i++;
  }
  tmp->next = NULL;
  glob.tiny->header = tmpfirst;
  ft_printf("header first again :");
  ft_printf("%X", (unsigned  long)(glob.tiny->header));
  ft_printf("\n");

  ft_print_zone(glob.tiny);

}

int ft_init_zone(int size_type)
{
  if (size_type == TINY)
  {
    ft_printf("init tiny\n");
    ft_printf("%X", (unsigned  long)(glob.tiny));
    ft_printf("\n");

    if (!(glob.tiny = mmap(0, PAGE_SIZE * 4, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
    {
      ft_printf("error in mmap");
      return FALSE;
    }
    ft_init_list_head(TINY, glob.tiny);
  }
  else if(size_type == SMALL)
  {
    ft_printf("init tiny\n");
    if (!(glob.small = mmap(0, PAGE_SIZE * 26, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
    {
      ft_printf("error in mmap");
      return FALSE;
    }
  }
  else if(size_type == LARGE)
  {
    ft_printf("init tiny\n");
    if (!(glob.large = mmap(0, PAGE_SIZE * 26, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
    {
      ft_printf("error in mmap");
      return FALSE;
    }
  }
  return TRUE;
}

int ft_init_malloc(size_t size){

  if ((size < TINY_SIZE) && (glob.tiny == NULL))
  {
    return ft_init_zone(TINY);
    //base = mmap(0, getpagesize() * 4, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
  }
    ft_printf("end ft_init\n");
    return TRUE;
}
