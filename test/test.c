/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:16:45 by djoly             #+#    #+#             */
/*   Updated: 2018/02/21 16:40:48 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "malloc.h"
//#include
//#define malloc(x) NULL

#include <stdlib.h>
#include <time.h>

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*dest;
	int		count;

	count = 0;
	length = 0;
	while (s1[length] != '\0')
		length++;
	dest = (char*)malloc(sizeof(*s1) * (length + 1));
	if (!dest)
		return (NULL);
	while (count < length)
	{

		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

int	rand_a_b(int	a,	int	b)
{
	return	rand()%(b-a) + a;
}

int main (int ac, char **av) {

	ft_printf("main %d: go main\n", __LINE__);
	char	*t;
  char *m;
	char *tab[10];
  m = ft_strdup("what");
	m = realloc(m, 20);
	m = realloc(m, 200);
	m = realloc(m, 2000);
	m = realloc(m, 20);
  free(m);
  return 0;
}
