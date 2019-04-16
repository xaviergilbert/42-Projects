/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:09:54 by xgilbert          #+#    #+#             */
/*   Updated: 2018/01/09 16:53:39 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static int	size_min(char *str)
{
	int		i;

	i = 0;
	while (nbr_n(liste_tetri_to_str(str)) * 4 > i * i)
		i++;
	return (i);
}

static void	solve(char *str, int size)
{
	t_carre		c;
	char		***tetri;
	t_pos		**tab;
	int			nb;

	nb = nbr_n(liste_tetri_to_str(str));
	c = carre_magique(liste_tetri_to_str(str), size);
	tetri = pieces_in_tab(liste_tetri_to_str(str));
	tab = pos_diese_in_struct(tetri, nbr_n(liste_tetri_to_str(str)));
	delete_tetri(tetri);
	while (main_backtracking(&c, tab, nb, size) == 0)
	{
		size++;
		delete_carre(&c);
		c = carre_magique(liste_tetri_to_str(str), size);
	}
	delete_tab(tab);
	print_tab(&c);
	delete_carre(&c);
}

void		print_tab(t_carre *c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (c->carre[i] != 0)
	{
		while (c->carre[i][j] != '\0')
		{
			ft_putchar(c->carre[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

int			main(int argc, char **argv)
{
	int			size;
	char		*str;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	str = liste_tetri_to_str(argv[1]);
	if (str == 0 || main_fichier_test(str) == 0 || nbr_n(str) > 26)
	{
		ft_putstr("error\n");
		free(str);
		return (0);
	}
	size = size_min(argv[1]);
	solve(argv[1], size);
	free(str);
	return (0);
}
