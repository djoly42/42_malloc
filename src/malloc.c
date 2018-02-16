/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:22:49 by djoly             #+#    #+#             */
/*   Updated: 2018/02/16 18:11:13 by djoly            ###   ########.fr       */
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
	//ft_printf("malloc %d: \n", __LINE__);

	if (size <= 0 )
		return (NULL);
	if ((tmp = ft_find_empty_head(i_zone)) != NULL)
	{
		// ft_print_zone(glob.tiny);
	//ft_printf("malloc %d: \n", __LINE__);
		tmp = ft_set_header(tmp, size);
		// ft_printf("print tiny\n");
		// ft_print_zone(glob.tiny);
		// ft_printf("print small\n");
		// ft_print_zone(glob.small);
		//ft_print_zone(0);
		//ft_print_zone(1);
	//ft_printf("print tiny\n");
		ft_print_zone(LARGE);
		//ft_printf("malloc %d: OK MALLOC  size: %d header: %p return malloc: %p\n", __LINE__, size, tmp, ((void*)tmp + META));
		return ((void*)tmp + META);
	}
	else
	{
	//ft_printf("malloc %d: \n", __LINE__);

		ft_init_malloc(size, i_zone);
		//ft_printf("malloc %d: fin init malloc\n", __LINE__);
//		exit (1);
		if ((tmp = ft_find_empty_head(i_zone)) != NULL)
		{
	//ft_printf("malloc %d: \n", __LINE__);
			// ft_print_zone(glob.tiny);
			tmp = ft_set_header(tmp, size);
			//ft_print_zone(0);
			//ft_print_zone(1);
			//ft_print_zone(2);
	//ft_printf("print tiny\n");
		ft_print_zone(LARGE);
		//	ft_printf("malloc %d: OK MALLOC size: %d header: %p return malloc: %p\n", __LINE__, size, tmp, ((void*)tmp + META));
			return ((void*)tmp + META);
		}
	}
	//ft_printf("malloc %d: \n", __LINE__);
	//ft_printf("print tiny\n");
	//ft_print_zone(0);
	//ft_printf("print small\n");
	//ft_print_zone(1);

	ft_printf("malloc %d: size expect: %d return NULL <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n", __LINE__, size);
	return (NULL);
}

void		erase

void		free(void *ptr)
{
	t_header	*head;
	ft_printf("malloc %d: Go free %p\n", __LINE__, ptr);
	if (ptr == NULL)
		return ;
	if ((head = ft_find_data(ptr)) != NULL)
	{
		head->size = 0;
		head->free = 1;
		if (ft_which_type(head) == LARGE)
			erase_large(head);
		ft_print_zone(2);
	}
	else
	{
		 ft_printf("----------\nmalloc %d: data not find %p\n",
		 					__LINE__, ptr);
		 ft_print_zone(2);
		// ft_printf("print tiny\n");
		// ft_print_zone(0);
		// ft_printf("print small\n");
		// ft_print_zone(1);
	}
}
		// ft_print_zone(0);
		// ft_print_zone(1);
	// ft_printf("------------------\nmalloc %d: type size %d\n", __LINE__, ft_which_zone(size));
		//ft_printf("------------------\nmalloc %d: type EQUAL\n", __LINE__);
	//ft_printf("------------------\nmalloc %d: type NOT EQUAL\n", __LINE__);

int			check_realloc(void *ptr, size_t size, t_header **dest)
{
	if (ptr && size <= 0)
		return FALSE;
		if (ptr && size <= 0)
		{
			free(ptr);
			return FALSE;
		}
		if ((*dest = ft_find_data(ptr)) == NULL)
		{
			return FALSE;
		}
	return TRUE;
}

void		*realloc_large(void *ptr, size_t size, t_header	*h_dest)
{
	void	*tmp;
	if (h_dest->size < size)
	{
		tmp = malloc(size);
		ft_copy_memory(ptr, tmp, size);
		h_dest = tmp - META;
		h_dest->size = size;
		free(ptr);
		ft_print_zone(2);
		return tmp;
	}
	h_dest->size = size;
	ft_print_zone(2);
	return ptr;
}

void		*realloc(void *ptr, size_t size)
{
	//ft_printf("------------------\nmalloc %d: Go realloc ptr %p size:%d\n",
		//				__LINE__, ptr,  size);
	t_header	*h_dest;
	void			*tmp;

	if (ptr == NULL)
		return malloc(size);
	if (!check_realloc(ptr, size, &h_dest))
		return (NULL);
	if (ft_which_zone(size) == LARGE)
		return realloc_large(ptr, size, h_dest);

	if(ft_which_zone(size) == ft_which_type(h_dest)){
		h_dest->size = size;
		//ft_printf("malloc %d: return ptr %p\n", __LINE__, ptr);
		return ptr;
	}
	tmp = malloc(size);
	ft_copy_memory(ptr, tmp, size);
	h_dest = tmp - META;
	h_dest->size = size;
	free(ptr);
	// ft_printf("------------------\nmalloc %d: return realloc", __LINE__);
	return (tmp);
}
