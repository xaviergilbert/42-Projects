/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:19:22 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/20 15:46:12 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		negatif;
	int		k;
	int		res;

	k = 0;
	while (str[k] == '\t' || str[k] == '\v' || str[k] == '\n' || str[k] == '\r'
			|| str[k] == '\f' || str[k] == ' ')
		k++;
	if (str[k] == '-')
	{
		negatif = 1;
		k++;
	}
	if (str[k] == '+')
		k++;
	res = 0;
	while (str[k] >= '0' && str[k] <= '9')
	{
		if (res != 0)
			res *= 10;
		res += (str[k] - 48);
		k++;
	}
	if (negatif == 1)
		res *= -1;
	return (res);
}

#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("%d\n", atoi(av[1]));
	printf("%d", ft_atoi(av[1]));
	return (0);
}
