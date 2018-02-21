/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:56:58 by djoly             #+#    #+#             */
/*   Updated: 2018/02/21 13:04:42 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

#include <stdlib.h> /// <<<<<<<<<DELETE
#include "../ft_printf/ft_printf.h"

//152
#define PAGE_SIZE getpagesize() //4096
#define TINY 0
#define SMALL 1
#define LARGE 2
#define TRUE 1
#define FALSE 0


#define TINY_SIZE 128
#define SMALL_SIZE 1024
#define DATA_CALC(x) ((x == 0) ? TINY_SIZE : SMALL_SIZE )

#define META sizeof(struct s_header) // 24
#define SIZE_STRUCT_ZONE  sizeof(struct s_zone) // 24
//#define META_LARGE sizeof(struct s_header_large) // 24
//#define META_CALC(x)		((x <= 1) ? META : META_LARGE)

#define PTR_ZONE(x) (*(&(glob.tiny) + x))
#define MMAP_TINY		PAGE_SIZE * 4
#define MMAP_SMALL	PAGE_SIZE * 26 //106 496
#define MMAP_CALC(x) ((x == 0) ? MMAP_TINY : MMAP_SMALL)

#define TINY_LIST_SIZE (MMAP_TINY / (META + TINY_SIZE)) // 107.78
#define SMALL_LIST_SIZE ((MMAP_SMALL / (META + SMALL_SIZE)) / 2) // 101.61
#define LARGE_LIST_SIZE 1// 101.61
#define LIST_CALC(x)		((x == 0) ? TINY_LIST_SIZE : ((x == 1) ? SMALL_LIST_SIZE : LARGE_LIST_SIZE))

typedef struct s_header{ // 24 //32
  size_t          size;
	size_t					first_size;
  int             free;
  struct s_header *next;
} t_header;


typedef struct s_header_large{ // 24
	size_t					size_mmap;
  size_t          size;
  int             free;
  struct s_header_large *next;
} t_header_large;

typedef struct s_zone{
  struct s_header	*header;
  struct s_zone		*next;
  size_t					size;
  size_t					count;
} t_zone;

typedef struct s_glob{
  t_zone *tiny;
  t_zone *small;
  t_zone *large;
} t_glob;

t_glob glob;

void				free(void *ptr);
void*				malloc(size_t size);
void*				realloc(void *ptr, size_t size);
void				show_alloc_mem(void);

t_header*		ft_find_empty_head(int i_zone, size_t size);
int					ft_init_malloc(size_t size, int i_zone);
t_header*		ft_set_header(t_header* head, size_t size, int i_zone);
void*				ft_copy_memory(void *src, void *dest, size_t new_size);
void*				ft_find_data(void *data);
int					ft_which_type(t_header *src);

void				ft_print_head(t_header* h);
void				ft_print_zone(int i_zone);
void				ft_print_data(void *p);

#endif
