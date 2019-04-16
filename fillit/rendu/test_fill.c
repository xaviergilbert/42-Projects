/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.test_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:33:13 by lucdubos          #+#    #+#             */
/*   Updated: 2017/12/18 15:48:24 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int		test_fill(t_carre *c, t_pos **tab, int count, int sz)
{
	int		pos;
	int		flag;

	flag = 0;
	pos = 0;
	while (flag < 4)
	{
		if (c->i + tab[count][pos].y < 0 || c->j + tab[count][pos].x < 0)
			return (0);
		if (c->i + tab[count][pos].y >= sz || c->j + tab[count][pos].x >= sz)
			return (0);
		if (c->carre[c->i + tab[count][pos].y][c->j + tab[count][pos].x] == '.')
		{
			pos++;
			flag++;
		}
		else
			flag++;
	}
	if (pos == 4)
		return (1);
	return (0);
}
