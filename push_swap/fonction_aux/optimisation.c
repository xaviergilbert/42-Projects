/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:05:42 by xgilbert          #+#    #+#             */
/*   Updated: 2018/09/05 15:37:41 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			pos_deux_plus_grand(t_struct *s)
{
	t_element		*element;
	int				i;

	if (s->b->nb <= 1 || s->flag == 1)
		return (1000);
	element = s->b->premier;
	i = 0;
	while (element->pos != s->b->plus_grand_elem->pos - 1)
	{
		element = element->suivant;
		i++;
	}
	if (i <= s->b->nb - i)
		return (i);
	else
		return ((-(s->b->nb - i)));
}

int			pos_plus_grand(t_struct *s)
{
	t_element		*element;
	int				i;

	element = s->b->premier;
	i = 0;
	while (element->nombre != s->b->plus_grand_elem->nombre)
	{
		element = element->suivant;
		i++;
	}
	if (i <= s->b->nb - i)
		return (i);
	else
		return ((-(s->b->nb - i)));
}

int			pos_plus_petit(t_struct *s)
{
	t_element		*element;
	int				i;

	element = s->b->premier;
	i = 0;
	while (element && element->nombre != s->b->plus_petit_elem->nombre)
	{
		element = element->suivant;
		i++;
	}
	if (i <= s->b->nb - i)
		return (i);
	else
		return ((-(s->b->nb - i)));
}

int			optimisation(t_struct *s)
{
	int			p;
	int			g;
	int			pg;

	get_info(s->b);
	p = pos_plus_petit(s);
	pg = pos_plus_grand(s);
	g = pos_deux_plus_grand(s);
	s->option_i == 1 ? ft_printf("Nb coups pour :\n") : 0;
	s->option_i == 1 ? ft_printf("-plus_grand_elem : %d\n", pg) : 0;
	s->option_i == 1 ? ft_printf("-deuxieme_plus_grand_elem : %d\n", g) : 0;
	s->option_i == 1 ? ft_printf("-plus_petit_elem : %d\n", p) : 0;
	s->option_i == 1 ? ft_printf("-flag : %d\n", s->flag) : 0;
	s->option_s == 1 ? s->option_s = 2 : 0;
	if (ft_vabsolue(pg) > ft_vabsolue(p) && ft_vabsolue(p) <= ft_vabsolue(g))
		return (p);
	else if (ft_vabsolue(g) < ft_vabsolue(pg) && s->flag == 0)
	{
		s->flag = 1;
		return (g);
	}
	else
		return (pg);
	return (0);
}
