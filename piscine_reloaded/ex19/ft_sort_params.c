/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:49:02 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/07 14:49:26 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_sort_params(int argc, char **argv)
{
	char	*swap;
	int		i;
	int		j;

	i = 0;
	j = 2;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] == argv[j - 1][i])
			i++;
		if (argv[j][i] < argv[j - 1][i])
		{
			swap = argv[j - 1];
			argv[j - 1] = argv[j];
			argv[j] = swap;
			j = 1;
		}
		j++;
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	ft_sort_params(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i++]);
		ft_putchar('\n');
	}
	return (0);
}
