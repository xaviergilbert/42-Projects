/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:13:30 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/16 17:30:00 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		last_is_first(t_liste *liste)
{
	t_element		*element;
	t_element		*first;

	element = liste->premier;
	while (element->suivant)
		element = element->suivant;
	first = element;
	element = liste->premier;
	while (element->suivant->suivant)
		element = element->suivant;
	element->suivant = NULL;
	first->suivant = liste->premier;
	liste->premier = first;
}

void		rra(t_struct *s)
{
	if (s->a->nb < 2)
		return ;
	if (s->option_a == 1)
	{
		displaylst(s);
		ft_printf("\n%30s\n", "OPERATION EFFECTUEE : RRA");
		ft_printf("\n %s\n", "----------------------------------------");
	}
	last_is_first(s->a);
	s->nb_coups++;
	s->str = ft_strjoin3(s->str, ft_strdup("rra\n"));
	get_info(s->a);
}

void		rrb(t_struct *s)
{
	if (s->b->nb < 2)
		return ;
	if (s->option_a == 1)
	{
		displaylst(s);
		ft_printf("\n%30s\n", "OPERATION EFFECTUEE : RRB");
		ft_printf("\n %s\n", "----------------------------------------");
	}
	last_is_first(s->b);
	s->nb_coups++;
	s->str = ft_strjoin3(s->str, ft_strdup("rrb\n"));
	get_info(s->b);
}

void		rrr(t_struct *s)
{
	rra(s);
	rrb(s);
	s->nb_coups--;
	s->str = ft_strjoin3(s->str, ft_strdup("rrr\n"));
	get_info(s->a);
	get_info(s->b);
}
