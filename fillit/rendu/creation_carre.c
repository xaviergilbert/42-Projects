/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LUCcreation_carre.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:33:33 by lucdubos          #+#    #+#             */
/*   Updated: 2017/12/18 15:52:54 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int				nbr_n(char *fr)
{
	int		nb_n;
	int		k;

	k = 0;
	nb_n = 0;
	while (fr[k])
	{
		if (fr[k] == '\n' && fr[k + 1] == '\n')
			nb_n++;
		k++;
	}
	return (nb_n);
}

static void		*init_carre(t_carre *c, char *fr, int size)
{
	int		nb_n;

	nb_n = nbr_n(fr);
	if (!(c->carre = (char**)malloc(sizeof(c->carre) * (size + 1))))
		return (0);
	while (c->i < size)
	{
		if (!(c->carre[c->i] = (char*)malloc(sizeof(*c->carre) * (size + 1))))
			return (0);
		c->j = 0;
		while (c->j < size)
		{
			c->carre[c->i][c->j] = '.';
			c->j++;
		}
		c->carre[c->i][c->j] = '\0';
		c->j = 0;
		c->i++;
	}
	c->carre[c->i] = 0;
	return (0);
}

t_carre			carre_magique(char *fr, int size)
{
	t_carre	c;

	c.i = 0;
	c.j = 0;
	c.carre = NULL;
	init_carre(&c, fr, size);
	return (c);
}

void			delete_carre(t_carre *c)
{
	int		i;

	i = 0;
	while (c->carre[i])
	{
		free(c->carre[i]);
		i++;
	}
	free(c->carre);
}
