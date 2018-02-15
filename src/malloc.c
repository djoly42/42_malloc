/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:22:49 by djoly             #+#    #+#             */
/*   Updated: 2018/02/15 14:24:49 by djoly            ###   ########.fr       */
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
		ft_print_zone(0);
		ft_print_zone(1);
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
			ft_print_zone(0);
			ft_print_zone(1);
			ft_print_zone(2);
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
	if (ft_find_data(ptr))
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
	tmp = malloc(size);
	if (ptr == NULL)
		return (tmp);
	ft_copy_memory(ptr, tmp);
	h_dest = tmp - META;
	h_dest->size = size;
	return (tmp);
}

void	show_alloc_mem(void)
{

	ft_printf("-----------------\nmalloc %d: Go show_alloc_mem \n", __LINE__);
}
