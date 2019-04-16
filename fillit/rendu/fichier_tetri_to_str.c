/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_tetri_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:20:44 by xgilbert          #+#    #+#             */
/*   Updated: 2018/01/09 16:32:43 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static int		double_conditions(char *str, int k)
{
	if (str[k] == '\n' && str[k - 1] == '\n')
	{
		k++;
		str[k++] = '\n';
		str[k++] = '\n';
		str[k] = '\n';
	}
	if (str[k] == '\0')
	{
		k++;
		str[k] = '\0';
		k++;
		str[k] = '\0';
		k++;
		str[k] = '\0';
	}
	return (k);
}

char			*str_pour_diese_solo(char *str1)
{
	int		k;
	int		i;
	char	*str;

	k = 0;
	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * 650)))
		return (0);
	while (str1[i])
	{
		while (k <= 4)
		{
			str[k] = '\n';
			k++;
		}
		str[k] = str1[i];
		k = double_conditions(str, k);
		k++;
		i++;
	}
	return (str);
}

char			*liste_tetri_to_str(char *liste_tetri)
{
	int		k;
	char	buffer[1];
	int		filein;
	int		nbread;
	char	*str;

	k = 0;
	filein = open((liste_tetri), O_RDONLY);
	nbread = read(filein, buffer, 1);
	if (!(str = (char*)malloc(sizeof(*str) * 650)))
		return (0);
	while (nbread > 0)
	{
		str[k] = buffer[0];
		nbread = read(filein, buffer, 1);
		if (k > 650)
			return (0);
		k++;
	}
	str[k++] = '\n';
	str[k] = '\0';
	close(filein);
	return (str);
}

int				lignes_correctes(char *fr)
{
	int		i;
	int		count;

	i = 0;
	while (fr[i])
	{
		count = 0;
		while (fr[i] == '#' || fr[i] == '.')
		{
			i++;
			count++;
		}
		if (fr[i] == '\n')
		{
			if (count == 4)
			{
				if (fr[i + 1] == '\n')
					i++;
				i++;
			}
			else
				return (0);
		}
	}
	return (1);
}
