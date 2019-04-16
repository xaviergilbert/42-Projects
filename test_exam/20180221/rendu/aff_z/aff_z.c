/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:04:27 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/21 11:10:11 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int		i;

	if (ac != 2)
	{
		ft_putchar('z');
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == 'z')
		{
			ft_putchar('z');
			ft_putchar('\n');
			return (0);
		}
		i++;
	}
	ft_putchar('z');
	ft_putchar('\n');
	return (0);
}
