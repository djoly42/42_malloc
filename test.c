/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:16:45 by djoly             #+#    #+#             */
/*   Updated: 2018/01/26 10:47:55 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "malloc.h"
//#include

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char const *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

int main (int ac, char **av) {

  char *m;
  m = malloc(10);

  ft_putstr("fin malloc\n");
  m = "WHAT";

  //m = malloc(10);

  //free(m);

  return 0;
}
