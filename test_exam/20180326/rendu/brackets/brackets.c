/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:34:22 by xgilbert          #+#    #+#             */
/*   Updated: 2018/03/26 19:03:22 by xgilbert         ###   ########.fr       */
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

int			match_brackets(char a, char b)
{
	if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
		return (1);
	else
		return (0);
}

int			check_brackets(char *str)
{
	int			i;
	int			pos;
	char		buffer[4096];

	i = 0;
	pos = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			buffer[++pos] = str[i];
		if (str[i] == ')' || str[i] == ']' || str[i] == '}')
			if (!(match_brackets(buffer[pos--], str[i]) == 1))
				return (0);
		i++;
	}
	return (1);
}

int			main(int ac, char **av)
{
	int			i;

	if (ac < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 1;
	while (av[i])
	{
		if (check_brackets(av[i]))
			ft_putstr("OK\n");
		else
			ft_putstr("Error\n");
		i++;
	}
}
