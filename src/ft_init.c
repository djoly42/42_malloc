/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:24:43 by djoly             #+#    #+#             */
/*   Updated: 2018/02/09 14:39:54 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void ft_print_data(void *p){
  int i = 0;
  while(i < 128){
    ft_printf("%c", (char * ) p);
    p++;
    i++;
  }
}

void ft_print_head(t_header* h)
{
  ft_printf("ft_init %d: ft_print_head ", __LINE__);
  if(h == NULL)
  {
    ft_printf("ft_init %d: h NULL <-----------------------------\n", __LINE__);
    return;
  }
  ft_printf(" %p\t", (unsigned long)(h));
  ft_printf("%d\t", h->free);
  ft_printf("%d\t", h->size);
  ft_printf("%p\n", h->next);
  // ft_printf("ft_init %d: %X\t%d\t%d\n", __LINE__,(unsigned long)(h),
              // h->free,h->size);

}

void ft_print_zone(t_zone* zone)
{
  ft_printf("-----------\n");
  ft_printf("ft_init %d: print zone \n", __LINE__);
  if (zone == NULL){
    ft_printf("ft_init %d: zone null\n", __LINE__);
    return;
  }
  t_header* tmp;
  int i;
  tmp = zone->header;
  ft_printf("ft_init %d: i\theader\t\ttmp\t\tfree\tsize\n", __LINE__),
  // ft_printf("ft_init %d: %X     %X\t%d\t%d\n", __LINE__, (unsigned  long)(glob.tiny->header),
  //             (unsigned long)(tmp),tmp->free,tmp->size);
  i = 0;
  while (tmp != NULL){
  ft_printf("ft_init %d: %i\t%p\t%p\t%d\t%d\t%p\t", __LINE__, i,  (unsigned  long)(glob.tiny->header),
               (unsigned long)(tmp),tmp->free,tmp->size, tmp->size );
  //ft_print_data((void *)tmp + TINY_SIZE);
  ft_printf("\n");
    tmp = tmp->next;
    i++;
  }

  ft_printf("ft_init %d: zone debut fin : %p %p\n", __LINE__, (unsigned long)zone, ((unsigned long)((void*)zone + PAGE_SIZE * 4)) );
  ft_printf("-----------\n");

}

void ft_init_list_head(int i_zone, t_zone* add_zone)
{
	int i;
	t_header* tmp;
	t_header* tmpfirst;

	ft_printf("ft_init %d: ft_list_head %p\n", __LINE__,(unsigned  long)(add_zone));
	tmp = NULL;
	PTR_ZONE(i_zone)->header = (void *) add_zone + sizeof(struct s_zone);
	tmp = PTR_ZONE(i_zone)->header;
	tmpfirst = PTR_ZONE(i_zone)->header;
  i = 1;
  tmp->free = 1;
  tmp->size = 0;
  //ft_print_head(tmp);
  while(i < LIST_CALC(i_zone))
  {
    //ft_printf("ft_init %d: header : %p \t %d \t %d \t", __LINE__ , (unsigned  long)(tmp),  tmp->free, tmp->size );
    tmp->next = ((void *)tmp + META + DATA_CALC(i_zone));
    ft_print_head(tmp);
    //ft_printf(" --- %X\n",(unsigned  long)(tmp->next));
    tmp = tmp->next;
    tmp->free = 1;
    tmp->size = 0;
  //ft_print_head(tmp);
    i++;
  }
  tmp->next = NULL;
  //ft_print_zone(glob.tiny);
  ft_printf("ft_init %d: header first again : %X\n", __LINE__, (unsigned  long)(PTR_ZONE(i_zone)->header));

  //ft_print_zone(glob.tiny);
}
// 	if (type == TINY){
//     //ft_printf("ft_init %d: header first: %X\n", __LINE__,(unsigned  long)(glob.tiny->header));
//   glob.tiny->header = (void *) add_zone + sizeof(struct s_zone) ;
//   tmp = glob.tiny->header;
//   tmpfirst = glob.tiny->header;
//   //glob.tiny->header = tmpfirst;
//     //ft_printf("ft_init %d: header first: %X\n", __LINE__,(unsigned  long)(glob.tiny->header));
//   }
//   else if(type == SMALL){
//     glob.small->header = (void *) add_zone + sizeof(struct s_zone);
//     tmp = glob.small->header;
//     tmpfirst = glob.small->header;
//   }
//   else{
//     ft_printf("ft_init %d: autres type %p\n", __LINE__,(unsigned  long)(add_zone));
//     return;
//
//   }
//   i = 1;
//   //ft_printf("ft_init %d:header first again: %X free: %X size: %X\n", __LINE__, (unsigned  long)(glob.tiny->header), (unsigned  long)(&tmp->free),
//     //          (unsigned  long)(&tmp->size));
//   tmp->free = 1;
//   tmp->size = 0;
//   //ft_print_head(tmp);
//   while(i < 100)
//   {
//
//     //ft_printf("ft_init %d: header : %p \t %d \t %d \t", __LINE__ , (unsigned  long)(tmp),  tmp->free, tmp->size );
//     tmp->next = ((void *)tmp + META + TINY_SIZE);
//     ft_print_head(tmp);
//     //ft_printf(" --- %X\n",(unsigned  long)(tmp->next));
//     tmp = tmp->next;
//     tmp->free = 1;
//     tmp->size = 0;
//   //ft_print_head(tmp);
//     i++;
//   }
//   tmp->next = NULL;
//   //ft_print_zone(glob.tiny);
//   ft_printf("ft_init %d: header first again : %X\n", __LINE__, (unsigned  long)(glob.tiny->header));
//
//   //ft_print_zone(glob.tiny);
// }

int ft_init_zone(int i_zone)
{
	ft_printf("ft_init %d: ft_init_zone: %d\n", __LINE__, i_zone);
	if (!(PTR_ZONE(i_zone) = mmap(0, MMAP_CALC(x), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
	{
		ft_printf("error in mmap");
		return FALSE;
	}
	ft_init_list_head(i_zone, PTR_ZONE(i_zone));
	return TRUE;
}


// 	if (size_type == TINY)
// 	{
//     ft_printf("ft_init %d: init tiny\n", __LINE__);
//     if (!(glob.tiny = mmap(0, PAGE_SIZE * 4, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
//     {
//       ft_printf("error in mmap");
//       return FALSE;
//     }
//     ft_init_list_head(TINY, glob.tiny);
//   }
//   else if(size_type == SMALL)
//   {
//     ft_printf("ft_init %d: init small\n", __LINE__);
//     if (!(glob.small = mmap(0, PAGE_SIZE * 26, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
//     {
//       ft_printf("error in mmap");
//       return FALSE;
//     }
//     ft_init_list_head(SMALL, glob.small);
//   }
//   else if(size_type == LARGE)
//   {
//     ft_printf("ft_init %d: init large\n", __LINE__);
//     if (!(glob.large = mmap(0, PAGE_SIZE * 26, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
//     {
//       ft_printf("error in mmap");
//       return FALSE;
//     }
//   }
//   //ft_print_zone(glob.tiny);
//   return TRUE;
// }

int ft_init_malloc(size_t size, int i_zone)
{
	ft_printf("ft_init %d : ft_init_malloc: size %d i_zone %d\n",
						__LINE__, size, i_zone);
	if (PTR_ZONE(i_zone) == NULL)
		return ft_init_zone(i_zone);
	return TRUE;
}
//   if ((size < TINY_SIZE) && (glob.tiny == NULL))
//   {
//     return ft_init_zone(TINY);
//     //base = mmap(0, getpagesize() * 4, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
//   }
//   else if ((size < SMALL_SIZE) && (glob.small == NULL))
//     return ft_init_zone(SMALL);
//   return TRUE;
// }
