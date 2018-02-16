/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:22:49 by djoly             #+#    #+#             */
/*   Updated: 2018/02/16 14:24:15 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			ft_which_zone(size_t size)
{
	if (size <= TINY_SIZE)
		return (0);
	else if (size <= SMALL_SIZE)
		return (1);
	return (2);
}

void		*malloc(size_t size)
{
	t_header	*tmp;
	int				i_zone;

	ft_printf("------------------\nmalloc %d: Go malloc: %u\n", __LINE__, size);
	i_zone = ft_which_zone(size);

	if (size <= 0 )
		return (NULL);
	if ((tmp = ft_find_empty_head(i_zone)) != NULL)
	{
		// ft_print_zone(glob.tiny);
		tmp = ft_set_header(tmp, size);
		// ft_printf("print tiny\n");
		// ft_print_zone(glob.tiny);
		// ft_printf("print small\n");
		// ft_print_zone(glob.small);
		//ft_print_zone(0);
		//ft_print_zone(1);
	ft_printf("print tiny\n");
	ft_print_zone(0);
		ft_printf("malloc %d: OK MALLOC  size: %d header: %p return malloc: %p\n", __LINE__, size, tmp, ((void*)tmp + META));
		return ((void*)tmp + META);
	}
	else
	{

		ft_init_malloc(size, i_zone);
		ft_printf("malloc %d: fin init malloc\n", __LINE__);
//		exit (1);
		if ((tmp = ft_find_empty_head(i_zone)) != NULL)
		{
			// ft_print_zone(glob.tiny);
			tmp = ft_set_header(tmp, size);
			//ft_print_zone(0);
			//ft_print_zone(1);
			//ft_print_zone(2);
	ft_printf("print tiny\n");
	ft_print_zone(0);
			ft_printf("malloc %d: OK MALLOC size: %d header: %p return malloc: %p\n", __LINE__, size, tmp, ((void*)tmp + META));
			return ((void*)tmp + META);
		}
	}
	ft_printf("print tiny\n");
	ft_print_zone(0);
	ft_printf("print small\n");
	ft_print_zone(1);

	ft_printf("malloc %d: size expect: %d return NULL <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n", __LINE__, size);
	return (NULL);
}

void		free(void *ptr)
{
	t_header	*head;

	ft_printf("malloc %d:----------------------\n", __LINE__);
	ft_printf("malloc %d:|                     |\n", __LINE__);
	ft_printf("malloc %d: Go free %p\n", __LINE__, ptr);
	ft_printf("malloc %d: Go free meta %p\n", __LINE__, ptr - META);
	ft_printf("malloc %d:|                     |\n", __LINE__);
	ft_printf("malloc %d:----------------------\n", __LINE__);
	if (ptr == NULL)
		return ;
	if (ft_find_data(ptr) != NULL)
	{
		ft_printf("malloc %d: data find %p\n", __LINE__, ptr);
		head = ptr - META;
		ft_printf("malloc %d: old value %d\n", __LINE__, head->size);
		head->size = 0;
		head->free = 1;
	}
	else
	{
		ft_printf("----------\nmalloc %d: data not find %p\n",
							__LINE__, ptr);
		ft_printf("print tiny\n");
		ft_print_zone(0);
		ft_printf("print small\n");
		ft_print_zone(1);
	}
}

void		*realloc(void *ptr, size_t size)
{
	t_header	*h_dest;
	void			*tmp;

	ft_printf("------------------\nmalloc %d: Go realloc size:%d\n",
						__LINE__, size);
	if (ptr == NULL)
		return malloc(size);
	if (ptr && size <= 0)
	{
		free(ptr);
		return (NULL);
	}
	if ((h_dest = ft_find_data(ptr)) == NULL)
	{
		ft_printf("------------------\nmalloc %d: return NULL\n", __LINE__);
		return (NULL);
	}
	ft_printf("------------------\nmalloc %d: type size %d\n", __LINE__, ft_which_zone(size));
	ft_printf("------------------\nmalloc %d: type size %d\n", __LINE__, ft_which_type(h_dest));
	if(ft_which_zone(size) == ft_which_type(h_dest)){
		ft_printf("------------------\nmalloc %d: type EQUAL\n", __LINE__);
		h_dest->size = size;
		ft_print_zone(0);
		return ptr;
	}
	ft_printf("------------------\nmalloc %d: type NOT EQUAL\n", __LINE__);
	tmp = malloc(size);
	ft_copy_memory(ptr, tmp);
	h_dest = tmp - META;
	h_dest->size = size;
	free(ptr);
	ft_printf("print tiny\n");
	ft_print_zone(0);
	ft_print_zone(1);
	ft_printf("------------------\nmalloc %d: return realloc",
						__LINE__);
	return (tmp);
}
