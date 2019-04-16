/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:11:43 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/19 17:17:36 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int		main(int argc, char **argv)
{
	int		nb;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	nb = atoi(argv[1]);
	if (nb == 1)
	{
		printf("1\n");
		return (0);
	}
	first_prime(nb);
	printf("\n");
	return (0);
}
