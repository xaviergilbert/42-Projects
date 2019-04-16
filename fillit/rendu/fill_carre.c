/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.fill_carre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:01:13 by lucdubos          #+#    #+#             */
/*   Updated: 2017/12/18 17:18:27 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

void	unfill_carre(t_carre *c, int count)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (c->carre[i])
	{
		if (c->carre[i][j] > count + 'A' && c->carre[i][j] <= 'Z')
			c->carre[i][j] = '.';
		j++;
		if (c->carre[i][j] == '\0')
		{
			j = 0;
			i++;
		}
	}
}

void	fill_carre(t_carre *c, t_pos **tab, int count)
{
	int		pos;

	unfill_carre(c, count);
	pos = 0;
	while (pos < 4)
	{
		c->carre[c->i + tab[count][pos].y][c->j
		+ tab[count][pos].x] = count + 'A';
		pos++;
	}
}
