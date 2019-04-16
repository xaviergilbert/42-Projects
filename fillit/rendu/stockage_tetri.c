/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocdage_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:33:52 by xgilbert          #+#    #+#             */
/*   Updated: 2017/12/18 17:21:26 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static void	premiere_sous_fonction(char *str, t_var *t, char ***tetri)
{
	if (!(tetri[t->n][t->i] = (char*)malloc(sizeof(tetri) * 5)))
		exit(0);
	t->j = 0;
	while (str[t->d] != '\n' && str[t->d] != '\0')
		tetri[t->n][t->i][t->j++] = str[t->d++];
	if (str[t->d++] == '\n')
	{
		tetri[t->n][t->i++][t->j] = '\0';
		t->j = 0;
	}
}

char		***pieces_in_tab(char *str)
{
	char	***tetri;
	t_var	t;

	t.n = 0;
	t.d = 0;
	if (!(tetri = (char***)malloc(sizeof(tetri) * (nbr_n(str) + 1))))
		return (0);
	while (str[t.d])
	{
		if (!(tetri[t.n] = (char**)malloc(sizeof(tetri) * 5)))
			return (0);
		t.i = 0;
		while (str[t.d] != '\n' && str[t.d + 1] != '\n' && str[t.d] != '\0')
			premiere_sous_fonction(str, &t, tetri);
		if (str[t.d - 1] == '\n' && str[t.d++] == '\n')
		{
			t.i = 0;
			t.n++;
		}
	}
	tetri[t.n] = 0;
	return (tetri);
}

void		delete_tetri(char ***tetri)
{
	int		i;
	int		n;

	n = 0;
	while (tetri[n])
	{
		i = 0;
		while (tetri[n][i])
		{
			free(tetri[n][i]);
			i++;
		}
		free(tetri[n]);
		n++;
	}
	free(tetri);
}
