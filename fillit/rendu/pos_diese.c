/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.pos_diese_in_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:42:35 by lucdubos          #+#    #+#             */
/*   Updated: 2017/12/18 17:24:38 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static t_pos	**re_pos_diese_in_struct(t_pos **tab, int nb_n)
{
	int		pos;
	int		count;

	count = 0;
	while (count < nb_n)
	{
		pos = 1;
		while (pos < 4)
		{
			tab[count][pos].x -= tab[count][0].x;
			tab[count][pos].y -= tab[count][0].y;
			pos++;
		}
		tab[count][0].x = 0;
		tab[count][0].y = 0;
		count++;
	}
	return (tab);
}

static void		premier_if(t_pos **tab, t_var *t)
{
	tab[t->n][t->d].x = t->j;
	tab[t->n][t->d++].y = t->i;
}

static void		deuxieme_if(t_var *t)
{
	t->j = -1;
	t->i++;
}

t_pos			**pos_diese_in_struct(char ***tetri, int nb_n)
{
	t_pos	**tab;
	t_var	t;

	t.n = -1;
	t.j = 0;
	if (!(tab = (t_pos**)malloc(sizeof(tab) * (nb_n) + 1)))
		return (0);
	while (tetri[++t.n])
	{
		t.d = 0;
		if (!(tab[t.n] = (t_pos*)malloc(sizeof(tab) * 4)))
			return (0);
		t.i = 0;
		while (tetri[t.n][t.i] != 0)
		{
			if (tetri[t.n][t.i][t.j] == '#')
				premier_if(tab, &t);
			if (tetri[t.n][t.i][t.j] == '\0')
				deuxieme_if(&t);
			t.j++;
		}
	}
	tab[t.n] = 0;
	tab = re_pos_diese_in_struct(tab, nb_n);
	return (tab);
}

void			delete_tab(t_pos **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
