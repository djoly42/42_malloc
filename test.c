/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:16:45 by djoly             #+#    #+#             */
/*   Updated: 2018/02/08 16:09:36 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "malloc.h"
//#include


int main (int ac, char **av) {

	ft_printf("main %d: go main\n", __LINE__);
  char *m;
  m = malloc(10);
	ft_printf("main %d: end main\n", __LINE__);
  m = "WHAT";
	ft_printf("test %d: %s ", __LINE__, m);

  //m = malloc(10);

  //free(m);

  return 0;
}
