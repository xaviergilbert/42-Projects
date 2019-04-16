/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:40:02 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/21 13:23:13 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_swap(char *a, char *z)
{
	char c;

	c = *a;
	*a = *z;
	*z = c;
}

char	*rev_wstr(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = 0;
	k = 0;
	while (str[i])
		i++;
	new = (char*)malloc(sizeof(*new) * (i + 1));
	while (i != 0)
	{
		i--;
		while (str[i] == ' ' || str[i] == '\t')
			i--;
		while (str[i] != ' ' && str[i] != '\t' && i != 0)
			i--;
		if (i != 0)
			i++;
		j = i;
		while (str[i] != ' ' && str[i] != '\t' && str[i])
			new[k++] = str[i++];
		if (i != 0)
			new[k++] = ' ';
		if (j == 0)
			i = 0;
		else
			i = j - 1;
	}
	new[k] = '\0';
	return (new);
}

char	*epur(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ' || str[i] == '\t')
		str[i] = '\0';
	return (str);
}
int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	ft_putstr(epur(rev_wstr(av[1])));
	ft_putchar('\n');
	return (0);
}
