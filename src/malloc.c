/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:22:49 by djoly             #+#    #+#             */
/*   Updated: 2018/02/22 13:32:13 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**	ft_printf("------------------\nmalloc %d: Go malloc: %u  size header %u
**  size zone %u\n", __LINE__, size, META, SIZE_STRUCT_ZONE);
*/

void			*malloc(size_t size)
{
	t_header	*tmp;
	int			i_zone;

	i_zone = ft_which_zone(size);
	if (size <= 0)
		return (NULL);
	if ((tmp = ft_find_empty_head(i_zone, size)) != NULL)
	{
		tmp = ft_set_header(tmp, size, i_zone);
		if (PRINT == 1)
			ft_printf("malloc %d: malloc addr %p\n", __LINE__,
			((void*)tmp + META));
		return ((void*)tmp + META);
	}
	else
	{
		ft_init_malloc(size, i_zone);
		if ((tmp = ft_find_empty_head(i_zone, size)) != NULL)
		{
			tmp = ft_set_header(tmp, size, i_zone);
			if (PRINT == 1)
				ft_printf("malloc %d: malloc addr %p\n",
					__LINE__, ((void*)tmp + META));
			return ((void*)tmp + META);
		}
	}
	return (NULL);
}

/*
** ft_printf("malloc %d: free addr %p\n", __LINE__, ptr);
*/

void			free(void *ptr)
{
	t_header	*head;

	if (ptr == NULL)
		return ;
	if ((head = ft_find_data(ptr)) != NULL)
	{
		head->size = 0;
		head->free = 1;
	}
	else
	{

		if (PRINT == 1)
		{
			ft_printf("malloc %d: free addr not find %p\n", __LINE__, ptr);
		}
	}
}

int				check_realloc(void *ptr, size_t size, t_header **dest)
{
	if (ptr && size <= 0)
		return (FALSE);
	if (ptr && size <= 0)
	{
		free(ptr);
		return (FALSE);
	}
	if ((*dest = ft_find_data(ptr)) == NULL)
	{
		return (FALSE);
	}
	return (TRUE);
}

/*
** ft_printf("malloc %d: realloc large ptr %p size:%d  h_dest %x\n",
** __LINE__, ptr,  size, h_dest);
** ft_print_zone(2);
*/

void			*realloc_large(void *ptr, size_t size, t_header *h_dest)
{
	void		*tmp;

	if (h_dest->size < size)
	{
		tmp = malloc(size);
		ft_copy_memory(ptr, tmp, size);
		h_dest = tmp - META;
		h_dest->size = size;
		free(ptr);
		return (tmp);
	}
	h_dest->size = size;
	return (ptr);
}

/*
** ft_printf("------------------\nmalloc %d: Go realloc ptr %p size:%d\n",
** __LINE__, ptr,  size);
*/

void			*realloc(void *ptr, size_t size)
{
	t_header	*h_dest;
	void		*tmp;

	if (ptr == NULL)
		return (malloc(size));
	if (!check_realloc(ptr, size, &h_dest))
		return (NULL);
	if (ft_which_zone(size) == LARGE)
		return (realloc_large(ptr, size, h_dest));
	if (ft_which_zone(size) == ft_which_type(h_dest))
	{
		h_dest->size = size;
		ft_printf("malloc %d: realloc addr %p\n", __LINE__, ptr);
		return (ptr);
	}
	tmp = malloc(size);
	ft_copy_memory(ptr, tmp, size);
	h_dest = tmp - META;
	h_dest->size = size;
	free(ptr);
	ft_printf("malloc %d: realloc addr %p\n", __LINE__, tmp);
	return (tmp);
}
