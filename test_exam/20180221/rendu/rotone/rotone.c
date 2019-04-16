/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:12:25 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/21 11:23:55 by xgilbert         ###   ########.fr       */
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
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (av[1][i])
	{
		if ((av[1][i] >= 'a' && av[1][i] <= 'y') 
				|| (av[1][i] >= 'A' && av[1][i] <= 'Y'))
			ft_putchar(av[1][i] + 1);
		else if (av[1][i] == 'z' || av[1][i] == 'Z')
			ft_putchar(av[1][i] - 25);
		else
			ft_putchar(av[1][i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
