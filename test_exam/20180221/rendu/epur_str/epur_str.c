/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:48:26 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/21 12:27:48 by xgilbert         ###   ########.fr       */
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

void	epur_str(char *str)
{
	int		i;
	int		k;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	k = i;
	while (str[k])
		k++;
	k--;
	while (str[k] == ' ' || str[k] == '\t')
		k--;
	str[++k] = '\0';
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t')
		&& (str[i + 1] == ' ' || str[i + 1] == '\t'))
			i++;
		else
		{
		ft_putchar(str[i]);
		i++;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	(epur_str(av[1]));
	ft_putchar('\n');
	return (0);
}
