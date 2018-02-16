/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:24:43 by djoly             #+#    #+#             */
/*   Updated: 2018/02/16 15:28:35 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void ft_init_list_head(int i_zone, t_zone* add_zone)
{
	int i;
	t_header* tmp;
	t_header* tmpfirst;

	//ft_printf("ft_init %d: ft_list_head %p\n", __LINE__,(unsigned  long)(add_zone));
	tmp = NULL;
	add_zone->header = (void *) add_zone + sizeof(struct s_zone);
	tmp = add_zone->header;
	tmpfirst = add_zone->header;
  i = 1;
  tmp->free = 1;
  tmp->size = 0;
  //ft_print_head(tmp);
  while(i < (int)LIST_CALC(i_zone))
  {
    //ft_printf("ft_init %d: header : %p \t %d \t %d \t", __LINE__ , (unsigned  long)(tmp),  tmp->free, tmp->size );
    tmp->next = ((void *)tmp + META + DATA_CALC(i_zone));
    //ft_print_head(tmp);
    //ft_printf(" --- %X\n",(unsigned  long)(tmp->next));
    tmp = tmp->next;
    tmp->free = 1;
    tmp->size = 0;
  //ft_print_head(tmp);
    i++;
  }
  tmp->next = NULL;
  //ft_printf("ft_init %d: header first again : %X\n", __LINE__, (unsigned  long)(PTR_ZONE(i_zone)->header));
}

int		ft_page_calc(size_t size, int i_zone)
{
	//ft_printf("ft_page_calc %d: zone %d\n", __LINE__, i_zone);
	if (i_zone == 2)
	{
		//int tmp = (PAGE_SIZE * ((size / PAGE_SIZE) + 1));
		// ft_printf("ft_page_calc %d: page large %d\n", __LINE__, tmp);
		// ft_printf("ft_page_calc %d: calc %d\n", __LINE__, size);
		// ft_printf("ft_page_calc %d: calc %d\n", __LINE__, (size / PAGE_SIZE ));
		// ft_printf("ft_page_calc %d: calc %d\n", __LINE__, ((size / PAGE_SIZE ) + 1));
		// ft_printf("ft_page_calc %d: calc %d\n", __LINE__, (PAGE_SIZE * ((size / PAGE_SIZE ) + 1)));
		return (PAGE_SIZE * ((size / PAGE_SIZE ) + 1));
	}
	return MMAP_CALC(i_zone);
}

int		ft_init_zone(size_t size, int i_zone)
{
	//ft_printf("ft_init %d: ft_init_zone: %d\n", __LINE__, i_zone);
	t_zone	*zone;
	int			i;

	i = 0;
	if(PTR_ZONE(i_zone) == NULL)
	{
		//ft_printf("\n\nft_init %d: init zone: %d\n", __LINE__, i);
		if (!(PTR_ZONE(i_zone) = mmap(0, ft_page_calc(size, i_zone), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		{
			//ft_printf("error in mmap");
			return FALSE;
		}
		zone = PTR_ZONE(i_zone);
	}
	else
	{
		i++;
		zone = PTR_ZONE(i_zone);
		while(zone->next != NULL)
		{
			i++;
			zone = zone->next;
		}
		//ft_printf("ft_init %d: init zone: %d\n", __LINE__, i);
		if (!(zone->next = mmap(0, ft_page_calc(size, i_zone), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		{
			//ft_printf("error in mmap");
			return FALSE;
		}
		zone = zone->next;
	}


	ft_init_list_head(i_zone, zone);
	//ft_print_zone(0);
	//		ft_printf("ft_init %d:return TRUE\n", __LINE__);
	return TRUE;
}

int ft_init_malloc(size_t size, int i_zone)
{
 //	ft_printf("ft_init %d : ft_init_malloc: size %d i_zone %d\n",
 		//				__LINE__, size, i_zone);
	return ft_init_zone(size, i_zone);
}
// 	if (PTR_ZONE(i_zone) == NULL)
// 		return ft_init_zone(i_zone);
// 	return TRUE;
// }
