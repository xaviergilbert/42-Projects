/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:11:06 by xgilbert          #+#    #+#             */
/*   Updated: 2018/01/09 16:56:44 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_H
# define TETRIS_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_var
{
	int		n;
	int		i;
	int		j;
	int		d;
}				t_var;

typedef struct	s_carre
{
	char	**carre;
	int		i;
	int		j;
}				t_carre;

int				main_backtracking(t_carre *c, t_pos **tab, int nb_n, int size);
void			unfill_carre(t_carre *c, int count);
t_pos			**stock_min_size_letter(t_pos **tab, int size);
void			fill_carre(t_carre *c, t_pos **tab, int count);
int				test_fill(t_carre *c, t_pos **tab, int count, int size);
char			*str_pour_diese_solo(char *str);
char			***pieces_in_tab(char *str);
char			*liste_tetri_to_str(char *liste_tetri);
t_carre			carre_magique(char *fr, int size);
int				main_fichier_test(char *fr);
void			print_tab(t_carre *c);
int				nbr_n(char *fr);
t_pos			**pos_diese_in_struct(char ***str, int nb_n);
void			delete_carre(t_carre *c);
void			delete_tetri(char ***tetri);
void			delete_tab(t_pos **tab);
int				lignes_correctes(char *fr);

#endif
