/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:51:28 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 12:59:40 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		free_error(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 1;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			i++;
			k++;
		}
		if (s[i])
			i++;
	}
	return (k);
}

static int		ft_count_letters(char const *s, char c, int i)
{
	int		k;

	k = 2;
	while (s[i] && s[i] != c)
	{
		k++;
		i++;
	}
	return (k);
}

static char		**splitsplit(char const *s, int c, char **split)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (s[k])
	{
		if (!(split[j] = ft_strnew(ft_count_letters(s, c, k))))
		{
			free_error(split);
			return (0);
		}
		i = 0;
		while (s[k] && s[k] != c)
			split[j][i++] = s[k++];
		split[j][i++] = s[k++];
		split[j++][i] = '\0';
	}
	split[j] = 0;
	return (split);
}

char			**split_file(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (0);
	if (!(split = (char**)malloc(sizeof(*split) * (ft_count_words(s, c) + 1))))
		return (0);
	split = splitsplit(s, c, split);
	return (split);
}
