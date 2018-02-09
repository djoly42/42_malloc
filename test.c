/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:16:45 by djoly             #+#    #+#             */
/*   Updated: 2018/02/09 15:23:36 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "malloc.h"
//#include
//#define malloc(x) NULL


int main (int ac, char **av) {

	ft_printf("main %d: go main\n", __LINE__);
  char *m;
	char *tab[10];
  m = malloc(10);

	ft_printf("main %d: end main\n", __LINE__);
  m = "WHAT";
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
  //free(m);
  return 0;
}
