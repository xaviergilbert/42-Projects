/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:54:24 by xgilbert          #+#    #+#             */
/*   Updated: 2018/03/26 17:04:24 by xgilbert         ###   ########.fr       */
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

char		*fonction(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' '
			|| str[i + 1] == '\t' || str[i + 1] == '\0'))
			str[i] -= 32;
		i++;
	}
	return (str);
}

int			main(int ac, char **av)
{
	char	*str;
	int		i;

	if (ac < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		str = fonction(av[i]);
		ft_putstr(str);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
