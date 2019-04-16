/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:05:59 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/19 14:50:40 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(-2);
		ft_putnbr(147483648);
	}
	if (nb < 0 && nb != -2147483648)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	if (nb >= 0)
		ft_putchar((nb % 10) + '0');
}

void	ft_print_words_tables(char **tab)
{
	int		j;

	j = 0;
	while (tab[j] != 0)
	{
		ft_putstr(tab[j++]);
		ft_putchar('\n');
	}
}

void	ft_show_tab(t_stock_par *par)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (par[i].str)
		i++;
	while (j < i)
	{
		ft_putstr(par[j].copy);
		ft_putchar('\n');
		ft_putnbr(par[j].size_param);
		ft_putchar('\n');
		ft_print_words_tables(par[j].tab);
		j++;
	}
}
