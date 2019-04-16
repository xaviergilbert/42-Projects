/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:16:14 by xgilbert          #+#    #+#             */
/*   Updated: 2018/09/17 11:00:56 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			deuxieme_partie(t_struct *s)
{
	int			i;

	i = 0;
	if (s->a->nb > 5)
		resume(s);
	else
		petite_lst(s);
	s->split_str = post_opti(s);
	s->option_a == 0 ? ft_print_instr(s->split_str) : displaylst(s);
	s->option_i == 1 || s->option_a == 1 ?
	ft_printf("\n %s\n", "----------------------------------------") : 0;
	s->option_i == 1 ? ft_printf("Nb d'elements : %d\n", s->a->nb) : 0;
	s->option_i == 1 ? ft_printf("Nb de coups : %d\n", s->nb_coups) : 0;
	s->option_i == 1 ? ft_printf("Liste divisee en fractions de %d elements\n",
	s->fraction) : 0;
	dellst(s->a);
	free(s->str);
	while (s->split_str[i])
		free(s->split_str[i++]);
	free(s->split_str);
	free(s->a);
	free(s->b);
}

int				main(int ac, char **av)
{
	t_struct	s;
	int			i;

	i = ac - 1;
	if (ac < 2)
		return (0);
	gestion_cas_erreur(&s, av + 1);
	if (ac == 2 || !(init(&s, ac)))
		return (0);
	while (s.option_a + s.option_i + s.option_s < i)
		insertlst(s.a, ft_atoi(av[i--]));
	get_pos_lst(s.a);
	if (check_tri(s.a, s.a->nb) == 1)
	{
		dellst(s.a);
		free(s.str);
		free(s.a);
		free(s.b);
		return (0);
	}
	deuxieme_partie(&s);
	return (0);
}
