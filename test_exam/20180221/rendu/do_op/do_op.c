/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:25:00 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/21 11:48:03 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int		nb1;
	int		nb2;
	int		res;

	if (ac != 4)
	{
		printf("\n");
		return (0);
	}
	nb1 = atoi(av[1]);
	nb2 = atoi(av[3]);
	if (av[2][0] == '+')
	{
		res = nb1 + nb2;
		printf("%d\n", res);
	}
	if (av[2][0] == '-')
	{
		res = nb1 - nb2;
		printf("%d\n", res);
	}
	if (av[2][0] == '*')
	{
		res = nb1 * nb2;
		printf("%d\n", res);
	}
	if (av[2][0] == '/')
	{
		res = nb1 / nb2;
		printf("%d\n", res);
	}
	if (av[2][0] == '%')
	{
		res = nb1 % nb2;
		printf("%d\n", res);
	}
	return (0);
}
