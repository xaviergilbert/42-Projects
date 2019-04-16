/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:32:21 by xgilbert          #+#    #+#             */
/*   Updated: 2018/03/26 16:36:21 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int			main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	ft_putstr(av[ac - 1]);
	ft_putchar('\n');
	return (0);
}
