/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:56:58 by djoly             #+#    #+#             */
/*   Updated: 2018/01/11 16:37:13 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_header *t_header;

struct s_header{
  size_t  size;
  t_header  next;
  int     free;
};

void free(void *ptr);
void *malloc(size_t size);
void *ft_realloc(void *ptr, size_t size);
void ft_show_alloc_mem(void);


#endif
