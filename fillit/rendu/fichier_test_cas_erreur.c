/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:50:23 by xgilbert          #+#    #+#             */
/*   Updated: 2018/01/09 16:32:54 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static int	nbr_diese(char *fr)
{
	int		k;
	int		count;

	k = 0;
	count = 0;
	while ((fr[k] != '\n' && fr[k + 1] != '\n') || fr[k + 1] != '\0')
	{
		if (fr[k] == '#')
			count++;
		if ((fr[k] == '\n' && fr[k + 1] == '\n') || fr[k + 1] == '\0')
		{
			if (count == 4)
			{
				k++;
				count = 0;
			}
			else
				return (0);
		}
		if (fr[k + 1] != '\0')
			k++;
	}
	return (1);
}

static int	nbr_point(char *fr)
{
	int		k;
	int		count;

	k = 0;
	count = 0;
	while ((fr[k] != '\n' && fr[k + 1] != '\n') || fr[k + 1] != '\0')
	{
		if (fr[k] == '.')
			count++;
		if ((fr[k] == '\n' && fr[k + 1] == '\n') || fr[k + 1] == '\0')
		{
			if (count == 12)
			{
				k++;
				count = 0;
			}
			else
				return (0);
		}
		if (fr[k + 1] != '\0')
			k++;
	}
	return (1);
}

static int	sous_fonction(char *fr, int count, int k)
{
	if (fr[k] == '#')
	{
		count++;
		if (fr[k - 1] == '#')
			count++;
		if (fr[k + 1] == '#')
			count++;
		if (fr[k + 5] == '#')
			count++;
		if (fr[k - 5] == '#')
			count++;
	}
	return (count);
}

static int	diese_solo(char *fr)
{
	int		k;
	int		count;

	fr = str_pour_diese_solo(fr);
	k = 4;
	count = 0;
	while ((fr[k] != '\n' && fr[k + 1] != '\n') || fr[k + 1] != '\0')
	{
		count = sous_fonction(fr, count, k);
		if ((fr[k] == '\n' && fr[k + 1] == '\n') || fr[k + 1] == '\0')
		{
			if (count >= 10)
			{
				k += 4;
				count = 0;
			}
			else
				return (0);
		}
		if (fr[k + 1] != '\0')
			k++;
	}
	return (1);
}

int			main_fichier_test(char *fr)
{
	int		i;

	i = 0;
	while (fr[i])
	{
		if (fr[i] != '.' && fr[i] != '#' && fr[i] != '\n' && fr[i] != '\0')
			return (0);
		i++;
	}
	if (fr[i - 1] != '\n' || fr[i - 2] != '\n')
		return (0);
	if (nbr_diese(fr) == 1 && nbr_point(fr) == 1 && diese_solo(fr) == 1
			&& lignes_correctes(fr) == 1)
		return (1);
	else
		return (0);
}
