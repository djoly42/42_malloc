/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:16:45 by djoly             #+#    #+#             */
/*   Updated: 2018/01/26 13:35:48 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "malloc.h"
//#include


int main (int ac, char **av) {

  char *m;
  m = malloc(10);
	ft_printf("main %d: end malloc\n", __LINE__);
  m = "WHAT";
	ft_printf("test %d: %p ", __LINE__, m);

  //m = malloc(10);

  //free(m);

  return 0;
}
