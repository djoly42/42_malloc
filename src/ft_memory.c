/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:02:13 by djoly             #+#    #+#             */
/*   Updated: 2018/02/22 13:41:21 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				*ft_copy_memory(void *src, void *dest, size_t new_size)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	t_header		*h_src;
	t_header		*h_dest;

	h_src = src - META;
	h_dest = dest - META;
	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	while ((i < h_src->size) && (i < new_size))
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
