/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:29:52 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/21 12:39:23 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int		plus_grand;

	if (ac != 3)
	{
		printf("\n");
		return (0);
	}
	if (atoi(av[1]) > atoi(av[2]))
		plus_grand = atoi(av[2]);
	else
		plus_grand = atoi(av[1]);
	while (atoi(av[1]) % plus_grand != 0 || atoi(av[2]) % plus_grand != 0)
		plus_grand--;
	printf("%d\n", plus_grand);
	return (0);
}
