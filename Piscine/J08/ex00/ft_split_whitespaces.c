/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 17:01:20 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/17 12:04:47 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		nombre_mots(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[k])
	{
		if (!(str[0] == ' ' || str[0] == '\n' || str[0] == '\t'))
			i++;
		while (str[k] == ' ' || str[k] == '\n' || str[k] == '\t')
		{
			k++;
			if (!(str[k] == ' ' || str[k] == '\n' || str[k] == '\t'))
				i++;
		}
		k++;
	}
	return (i);
}

int		nombre_lettres(char *str, int k)
{
	int		i;

	i = 1;
	while (str[k] != '\0'
	&& (!(str[k] == ' ' || str[k] == '\n' || str[k] == '\t')))
	{
		i++;
		k++;
	}
	return (i);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	j = 0;
	k = 0;
	tab = (char**)malloc(sizeof(*tab) * (nombre_mots(str) + 1));
	while (str[k])
	{
		while (str[k] == ' ' || str[k] == '\n' || str[k] == '\t')
			k++;
		if (str[k])
		{
			i = 0;
			tab[j] = (char*)malloc(sizeof(tab) * (nombre_lettres(str, k) + 1));
			while (str[k] && (!(str[k] == ' '
			|| str[k] == '\n' || str[k] == '\t')))
				tab[j][i++] = str[k++];
			tab[j++][i] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}
