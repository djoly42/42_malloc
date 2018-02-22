/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:56:58 by djoly             #+#    #+#             */
/*   Updated: 2018/02/22 13:37:55 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <sys/mman.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# define PAGE_SIZE getpagesize()
# define TINY 0
# define SMALL 1
# define LARGE 2
# define TRUE 1
# define FALSE 0
# define TINY_SIZE 128
# define SMALL_SIZE 1024
# define DATA_CALC(x) ((x == 0) ? TINY_SIZE : SMALL_SIZE )
# define META sizeof(struct s_header)
# define SIZE_STRUCT_ZONE  sizeof(struct s_zone)
# define PTR_ZONE(x)	(*(&(g_glob.tiny) + x))
# define MMAP_TINY		PAGE_SIZE * 4
# define MMAP_SMALL	PAGE_SIZE * 26
# define MMAP_CALC(x) ((x == 0) ? MMAP_TINY : MMAP_SMALL)
# define TINY_LIST_SIZE (MMAP_TINY / (META + TINY_SIZE))
# define SMALL_LIST_SIZE ((MMAP_SMALL / (META + SMALL_SIZE)) / 2)
# define LIST_CALC2(x)  ((x == 1) ? SMALL_LIST_SIZE : LARGE_LIST_SIZE)
# define LIST_CALC(x)		((x == 0) ? TINY_LIST_SIZE : LIST_CALC2(x))
# define LARGE_LIST_SIZE 1
# define PRINT 0

typedef struct s_header	t_header;

struct					s_header
{
	size_t				size;
	size_t				first_size;
	int					free;
	t_header			*next;
};

typedef struct s_zone	t_zone;

struct					s_zone
{
	t_header			*header;
	t_zone				*next;
	size_t				size;
	size_t				count;
};

typedef struct s_glob	t_glob;

struct					s_glob
{
	t_zone				*tiny;
	t_zone				*small;
	t_zone				*large;
};

t_glob	g_glob;

void					free(void *ptr);
void					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
void					show_alloc_mem(void);
t_header				*ft_find_empty_head(int i_zone, size_t size);
int						ft_init_malloc(size_t size, int i_zone);
t_header				*ft_set_header(t_header *head, size_t size, int i_zone);
void					*ft_copy_memory(void *src, void *dest, size_t new_size);
void					*ft_find_data(void *data);
int						ft_which_type(t_header *src);
void					ft_print_head(t_header *h);
void					ft_print_zone(int i_zone);
void					ft_print_data(void *p);
int						ft_which_zone(size_t size);

#endif
