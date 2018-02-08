/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:02:13 by djoly             #+#    #+#             */
/*   Updated: 2018/02/08 11:51:49 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


void * ft_copy_memory(void *src, void *dest){

  size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
  t_header  *h_src;
  t_header  *h_dest;

  h_src = src - META;
  h_dest = dest - META;
	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
  ft_printf("ft_copy_memory %d: src %p\n", __LINE__, src);
  ft_printf("ft_copy_memory %d: header %p\n", __LINE__, h_src);
  ft_printf("ft_copy_memory %d: size %d\n", __LINE__, h_src->size);
	while (i < h_src->size)
	{
		s1[i] = s2[i];
		i++;
	}
  h_dest->free = 0;
  h_dest->size = h_src->size;
  h_src->free = 1;
  h_src->size = 0;
	return (dest);
}
//   ft_printf("ft_memory %d: ft_copy_memory ", __LINE__);
//
//   int       i;
//
//   h_src = src - META;
//   h_dest = dest - META;
//   i = 0;
//   while(i < h_src->size){
//     dest + i = src + i;
//     i++;
//   }
//   h_dest->free = 0;
//   h_dest->size = h_src->size;
//   h_src->free = 1;
//   h_src->size = 0;
// }
