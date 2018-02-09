/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:16:45 by djoly             #+#    #+#             */
/*   Updated: 2018/02/09 15:11:35 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "malloc.h"
//#include
//#define malloc(x) NULL


int main (int ac, char **av) {

	ft_printf("main %d: go main\n", __LINE__);
  char *m;
	char *tab[5];
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

  return 0;
}
