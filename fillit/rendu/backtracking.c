/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:17:31 by lucdubos          #+#    #+#             */
/*   Updated: 2017/12/18 17:17:27 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static void	re_init_c(t_carre *c)
{
	c->i = 0;
	c->j = 0;
}

static void	fonction_avancer(t_carre *c)
{
	if (c->carre[c->i][c->j] != '\0')
		c->j++;
	else
	{
		c->i++;
		c->j = 0;
	}
}

static int	backtracking(t_carre *c, t_pos **tab, int size, int count)
{
	while (c->carre[c->i])
	{
		if (test_fill(c, tab, count, size) == 1)
		{
			fill_carre(c, tab, count);
			return (1);
		}
		else
			fonction_avancer(c);
	}
	return (0);
}

static int	retrouve_coord_piece_plus_un(t_carre *c, int count)
{
	re_init_c(c);
	while (c->carre[c->i])
	{
		if (c->carre[c->i][c->j] == count + 'A')
			return (1);
		c->j++;
		if (c->carre[c->i][c->j] == '\0')
		{
			c->i++;
			c->j = 0;
		}
	}
	return (0);
}

int			main_backtracking(t_carre *c, t_pos **tab, int nb_n, int size)
{
	int		count;

	count = 0;
	re_init_c(c);
	while (nb_n > count)
	{
		if (backtracking(c, tab, size, count) == 1)
		{
			count++;
			re_init_c(c);
		}
		else
		{
			if (--count < 0)
				return (0);
			if (retrouve_coord_piece_plus_un(c, count) == 1)
				fonction_avancer(c);
			unfill_carre(c, count - 1);
		}
	}
	return (1);
}
