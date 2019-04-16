/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:57:05 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/20 15:18:57 by xgilbert         ###   ########.fr       */
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

char	*search_and_replace(char *str, char l, char r)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == l)
			str[i] = r;
		i++;
	}
	return (str);
}

int		main(int ac, char **av)
{
	char	*str;

	if (ac != 4)
	{
		ft_putchar('\n');
		return (0);
	}
	str = search_and_replace(av[1], av[2][0], av[3][0]);
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}
