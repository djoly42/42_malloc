/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:16:45 by djoly             #+#    #+#             */
/*   Updated: 2018/02/16 17:44:41 by djoly            ###   ########.fr       */
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

	m = malloc(1024 * 16);
	free(m);
	m = malloc(1024 * 17);


  m = ft_strdup("what");
  ft_strdup("NO");
	ft_printf("test %d: %s ", __LINE__, m);
	m = realloc(m, 20);
	ft_printf("test %d: %s ", __LINE__, m);
	m = realloc(m, 200);
	ft_printf("test %d: %s ", __LINE__, m);
	//ft_print_zone(0);
	exit(0);
	t = malloc(50000);
	t = malloc(20000);
	ft_printf("main %d: END MALLOC LARGE\n", __LINE__);
	//exit(0);
  m = malloc(10);

	ft_printf("main %d: end main\n", __LINE__);
  *m = 'a';
	ft_printf("test %d: %s ", __LINE__, m);

  tab[0] = malloc(1);
  tab[1] = malloc(2);
  tab[2] = malloc(3);
  tab[3] = malloc(4);
	free(tab[2]);
  tab[2] = malloc(5);
  //free(m);

  tab[4] = malloc(300);
  tab[5] = malloc(400);
  tab[6] = malloc(500);
  tab[7] = malloc(600);
	free(tab[6]);
	free(tab[5]);
  tab[6] = malloc(700);

	//ft_show_alloc_mem();

	int i = 0;
	int nombre_aleatoire = 0;
	srand(time(NULL)); // initialisation de rand
	for(i=0; i<400; i++){
	nombre_aleatoire = rand_a_b(0, 1000);
	ft_printf("main %d:i: %d ",__LINE__, i);
	ft_printf("main %d:%d ",__LINE__, nombre_aleatoire);
	malloc(nombre_aleatoire);
	}
  //free(m);
  return 0;
}
