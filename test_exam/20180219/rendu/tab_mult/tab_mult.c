/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:01:24 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/19 15:52:19 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}

int		main(int argc, char **argv)
{
	int		i;
	int		res;
	int		c;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 1;
	res = 0;
	c = 0;
	while (argv[1][c])
	{
		if (res != 0)
			res *= 10;
		res = res + (argv[1][c] - 48);
		c++;
	}
	while (i != 10)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putstr(argv[1]);
		ft_putstr(" = ");
		ft_putnbr(i * res);
		ft_putchar('\n');
	i++;
	}
	return (0);
}
