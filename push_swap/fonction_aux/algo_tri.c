/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:22:56 by xgilbert          #+#    #+#             */
/*   Updated: 2018/09/17 11:02:47 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			check_tri(t_liste *liste, int nb)
{
	t_element		*element;
	int				i;

	i = 0;
	element = liste->premier;
	while (element->suivant && i++ < nb)
	{
		if (element->pos + 1 != element->suivant->pos)
			return (0);
		else
			element = element->suivant;
	}
	return (1);
}

void		fusion_listes_2nd(t_struct *s)
{
	if (s->b->premier->nombre != s->b->plus_petit_elem->nombre ||
			s->b->nb < 2)
		pa(s);
	else
	{
		pa(s);
		ra(s);
	}
	if (s->a->premier->pos == s->a->premier->suivant->pos + 1)
	{
		sa(s, s->a);
		s->flag = 0;
	}
}

void		fusion_listes(t_struct *s)
{
	int			i;

	i = 0;
	s->flag = 0;
	while (s->b->nb > 0)
	{
		i = optimisation(s);
		while (i != 0)
		{
			if (i > 0)
			{
				i--;
				rb(s);
			}
			else if (i < 0)
			{
				i++;
				rrb(s);
			}
		}
		fusion_listes_2nd(s);
	}
}

void		algo_tri(t_struct *s)
{
	while (!(check_tri(s->a, s->a->nb)))
	{
		while (s->b->nb < s->fraction && (!(check_tri(s->a, s->a->nb))))
			s->a->premier->pos <= s->limite
			&& s->a->premier->pos > s->limite - s->fraction ? pb(s) : ra(s);
		while (s->a->dernier_elem->pos != s->limite - s->fraction
		&& s->limite > s->fraction && (!(check_tri(s->a, s->a->nb))))
			ra(s);
		fusion_listes(s);
		s->limite += s->fraction;
		while (s->a->premier->pos - 1 == s->a->dernier_elem->pos)
			ra(s);
	}
}

void		resume(t_struct *s)
{
	int			i;

	if (s->a->nb <= 30)
		i = 2;
	else if (s->a->nb > 30 && s->a->nb <= 80)
		i = 3;
	else if (s->a->nb > 80 && s->a->nb <= 200)
		i = 4;
	else if (s->a->nb > 200 && s->a->nb <= 500)
		i = 5;
	else
		i = 6;
	s->fraction = s->a->nb / i;
	s->limite = s->fraction;
	algo_tri(s);
}
