/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:25:50 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/19 20:28:02 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	i++;
	return (i);
}

void	sous_fonction(int argc, char **argv, char *tab)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 1;
	while (c < argc)
	{
		j = 0;
		while (argv[c][j])
		{
			tab[i] = argv[c][j];
			i++;
			j++;
		}
		if (c < argc - 1)
		{
			tab[i] = '\n';
			i++;
		}
		c++;
	}
	tab[i] = '\0';
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		c;
	char	*tab;

	c = 1;
	i = 0;
	while (c < argc)
	{
		i += ft_strlen(argv[c]);
		c++;
	}
	tab = (char*)malloc(sizeof(*tab) * (i + 1));
	sous_fonction(argc, argv, tab);
	return (tab);
}
