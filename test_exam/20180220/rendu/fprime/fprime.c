/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:44:01 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/20 17:30:48 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		first_prime(int nb)
{
	int		i;

	i = 2;
	while (nb % i != 0)
		i++;
	if (nb == i)
	{
		printf("%d", i);
		return (0);
	}
	printf("%d*", i);
	first_prime(nb / i);
	return (0);
}

int		main(int ac, char **av)
{
	int		nb;

	if (ac != 2)
	{
		printf("\n");
		return (0);
	}
	nb = atoi(av[1]);
	if (nb == 1)
	{
		printf("1\n");
		return (0);
	}
	first_prime(nb);
	printf("\n");
	return (0);
}
