/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:56:58 by djoly             #+#    #+#             */
/*   Updated: 2018/01/12 13:55:46 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
//152
#define PAGE_SIZE getpagesize() //4096
#define TINY 1
#define SMALL 2
#define LARGE 3
#define TRUE 1
#define FALSE 0

#define TINY_SIZE 128
#define SMALL_SIZE 1024
#define META sizeof(struct s_header)

typedef struct s_header{
  size_t          size;
  struct s_header *next;
  int             free;
} t_header;

typedef struct s_zone{
  struct s_header *header;
  struct s_map    *next;
  size_t          size;
  size_t          count;
} t_zone;

typedef struct s_glob{
  t_zone *tiny;
  t_zone *small;
  t_zone *large;
} t_glob;


t_glob glob;

void free(void *ptr);
void *malloc(size_t size);
void *ft_realloc(void *ptr, size_t size);
void ft_show_alloc_mem(void);

boole ft_init(size_t size);


void ft_putchar(char c);
void ft_putnbr(int n);
size_t ft_strlen(const char *s);
void ft_putstr(char const *str);

#endif
