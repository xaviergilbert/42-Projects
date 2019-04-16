/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:32:41 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/20 16:57:50 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fichier.h"

int		doop(int i, char *str2, int j)
{
	t_doop		operateur[5];
	int			k;

	operateur[0].car = '+';
	operateur[0].fonction = add;
	operateur[1].car = '-';
	operateur[1].fonction = sous;
	operateur[2].car = '*';
	operateur[2].fonction = mult;
	operateur[3].car = '/';
	operateur[3].fonction = div;
	operateur[4].car = '%';
	operateur[4].fonction = mod;
	k = 0;
	while (k < 5)
	{
		if (str2[0] == operateur[k].car)
			return (operateur[k].fonction(i, j));
		k++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc != 4)
		return (0);
	if (argv[3][0] == '0' && (argv[2][0] == '/'))
	{
		ft_putstr("Stop : division by zero");
		return (0);
	}
	if (argv[3][0] == '0' && (argv[2][0] == '%'))
	{
		ft_putstr("Stop : modulo by zero");
		return (0);
	}
	i = ft_atoi(argv[1]);
	j = ft_atoi(argv[3]);
	ft_putnbr(doop(i, argv[2], j));
	return (0);
}
