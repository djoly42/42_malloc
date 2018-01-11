/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:56:58 by djoly             #+#    #+#             */
/*   Updated: 2018/01/11 17:50:41 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_header{
  size_t          size;
  struct s_header *next;
  int             free;
} t_header;

typedef struct s_map{
  struct s_header *header;
  struct s_map    *next;
  size_t          size;
  size_t          count;
} t_map;

typedef struct s_glob{
  t_map *tiny;
  t_map *small;
  t_map *large;
} t_glob;


void free(void *ptr);
void *malloc(size_t size);
void *ft_realloc(void *ptr, size_t size);
void ft_show_alloc_mem(void);

void ft_putchar(char c);
void ft_putnbr(int n);
size_t ft_strlen(const char *s);
void ft_putstr(char const *str);

#endif
