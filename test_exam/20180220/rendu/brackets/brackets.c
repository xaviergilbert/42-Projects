/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:32:27 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/21 18:24:25 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		check_parentheses(char *str)
{
	int		i;
	int		c_par;
	int		c_acc;
	int		c_cro;

	i = 0;
	c_par = 0;
	c_acc = 0;
	c_cro = 0;
	while (str[i])
	{
		if (str[i] == '(')
			c_par++;
		else if (str[i] == ')')
			c_par--;
		else if (str[i] == '[')
			c_cro++;
		else if (str[i] == ']')
			c_cro--;
		else if (str[i] == '{')
			c_acc++;
		else if (str[i] == '}')
			c_acc--;
		if (c_par < 0 || c_acc < 0 || c_cro < 0)
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	if (c_par != 0 || c_acc != 0 || c_cro != 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	else
	{
		ft_putstr("OK\n");
		return (0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;

	if (ac == 1)
	{
		ft_putchar ('\n');
		return (0);
	}
	i = 1;
	while (av[i])
	{
		check_parentheses(av[i]);
		i++;
	}
	return (0);
}
