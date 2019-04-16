/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:07:01 by xgilbert          #+#    #+#             */
/*   Updated: 2018/03/26 18:27:38 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int			nb_mots(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[k])
	{
		while (ft_is_space(str[k]) == 0 && str[k])
			k++;
		i++;
		while (ft_is_space(str[k]) == 1 && str[k])
			k++;;
	}
	return (i);
}

int			nb_lettres(char *str)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	while (str[k] && ft_is_space(str[k]) == 0)
	{
		i++;
		k++;
	}
	return (i);
}

char		**ft_split(char *str)
{
	char		**tab;
	int			i;
	int			j;
	int			k;

	tab = (char**)malloc(sizeof(*tab) * nb_mots(str) + 1);
	i = 0;
	k = 0;
	while (str[k])
	{
		while (ft_is_space(str[k]))
			k++;
		if (str[k])
		{
			tab[i] = (char*)malloc(sizeof(tab) * nb_lettres(&str[k]) + 1);
			j = 0;
			while ((ft_is_space(str[k]) == 0) && str[k] != '\0')
				tab[i][j++] = str[k++];
			tab[i++][j] = '\0';
		}
	}
	tab[i] = 0;
	return (tab);
}
