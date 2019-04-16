/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:22:53 by xgilbert          #+#    #+#             */
/*   Updated: 2018/09/13 17:51:19 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft/libft.h"

typedef struct		s_elem
{
	int				nombre;
	int				pos;
	struct s_elem	*suivant;
}					t_element;

typedef struct		s_liste
{
	t_element		*premier;
	t_element		*deuxieme_elem;
	t_element		*dernier_elem;
	t_element		*plus_grand_elem;
	t_element		*plus_petit_elem;
	int				nb;
}					t_liste;

typedef struct		s_struct
{
	t_liste			*a;
	t_liste			*b;
	int				nb_coups;
	char			*str;
	char			**split_str;
	int				flag;
	int				fraction;
	int				limite;
	int				option_a;
	int				option_i;
	int				option_s;
}					t_struct;

/*
** Operations
*/

void				sa(t_struct *s, t_liste *liste);
void				sb(t_struct *s, t_liste *liste);
void				ss(t_struct *s);
void				pa(t_struct *s);
void				pb(t_struct *s);
void				ra(t_struct *s);
void				rb(t_struct *s);
void				rr(t_struct *s);
void				rra(t_struct *s);
void				rrb(t_struct *s);
void				rrr(t_struct *s);

/*
** Fichiers algos
*/

void				resume(t_struct *s);
int					check_tri(t_liste *liste, int nb);
int					optimisation(t_struct *s);
void				petite_lst(t_struct *s);
char				**post_opti(t_struct *s);

/*
** Fichiers Display
*/

void				displaylst(t_struct *s);
void				ft_print_instr(char **split);

/*
** Fichiers main
*/

int					main(int ac, char **av);

/*
** Fichiers infos
*/

void				get_pos_lst(t_liste *liste);
t_liste				*initlst(t_liste *liste, int nb);
int					init(t_struct *s, int nb);
void				insertlst(t_liste *liste, int nb);
void				dellst(t_liste *liste);
void				get_info(t_liste *liste);
void				gestion_cas_erreur(t_struct *s, char **str);

#endif
