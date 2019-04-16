/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 17:05:32 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/13 09:33:55 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_sort_ascii(int argc, char **argv)
{
	char	*swap;
	int		a;
	int		i;

	a = 2;
	i = 0;
	while (a < argc)
	{
		while (argv[a][i] == argv[a - 1][i])
			i++;
		if (argv[a][i] - argv[a - 1][i] < 0)
		{
			swap = argv[a];
			argv[a] = argv[a - 1];
			argv[a - 1] = swap;
			a = 1;
		}
		a++;
		i = 0;
	}
}

int		main(int argc, char **argv)
{
	int		i;

	ft_sort_ascii(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
