/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petite_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:56:45 by xgilbert          #+#    #+#             */
/*   Updated: 2018/10/03 15:38:29 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		lst_deux(t_struct *s, t_liste *liste)
{
	if (check_tri(liste, s->a->nb) == 0)
		sa(s, s->a);
}

void		lst_trois(t_struct *s, t_liste *liste)
{
	get_info(liste);
	if (check_tri(s->a, s->a->nb))
		return ;
	if (s->a->premier->pos == s->a->plus_grand_elem->pos)
	{
		ra(s);
		if (check_tri(s->a, s->a->nb) == 0)
			sa(s, s->a);
	}
	else if (s->a->premier->pos == s->a->plus_petit_elem->pos)
	{
		ra(s);
		sa(s, s->a);
		rra(s);
	}
	else if (s->a->deuxieme_elem->pos == s->a->plus_grand_elem->pos)
	{
		ra(s);
		ra(s);
	}
	else
		sa(s, s->a);
}

void		lst_quatre(t_struct *s)
{
	while (s->a->premier->pos != 1 && s->a->premier->pos != 2)
		ra(s);
	if (s->a->premier->pos == 1 || s->a->premier->pos == 2)
	{
		pb(s);
		while (s->a->premier->pos != 1 && s->a->premier->pos != 2)
			ra(s);
		pb(s);
	}
	if (check_tri(s->a, s->a->nb) == 0)
		sa(s, s->a);
	if (check_tri(s->b, s->b->nb))
		sb(s, s->b);
	pa(s);
	pa(s);
}

void		lst_cinq(t_struct *s)
{
	get_info(s->a);
	while (s->b->nb < 2)
	{
		if (s->a->premier->pos == 1 || s->a->premier->pos == 2)
			pb(s);
		else
			ra(s);
		get_info(s->a);
	}
	lst_trois(s, s->a);
	check_tri(s->b, s->b->nb) == 1 ? sb(s, s->b) : 0;
	pa(s);
	pa(s);
}

void		petite_lst(t_struct *s)
{
	if (check_tri(s->a, s->a->nb))
		return ;
	if (s->a->nb == 2)
		lst_deux(s, s->a);
	else if (s->a->nb == 3)
		lst_trois(s, s->a);
	else if (s->a->nb == 4)
		lst_quatre(s);
	else if (s->a->nb == 5)
		lst_cinq(s);
}
