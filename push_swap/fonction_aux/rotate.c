/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:09:30 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/17 14:17:38 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		first_is_last(t_liste *liste)
{
	t_element	*element;
	t_element	*end;

	end = liste->premier;
	liste->premier = liste->premier->suivant;
	element = liste->premier;
	while (element->suivant)
		element = element->suivant;
	element->suivant = end;
	end->suivant = NULL;
}

void		ra(t_struct *s)
{
	if (s->a->nb < 2)
		return ;
	if (s->option_a == 1)
	{
		displaylst(s);
		ft_printf("\n%30s\n", "OPERATION EFFECTUEE : RA");
		ft_printf("\n %s\n", "----------------------------------------");
	}
	first_is_last(s->a);
	s->nb_coups++;
	s->str = ft_strjoin3(s->str, ft_strdup("ra\n"));
	get_info(s->a);
}

void		rb(t_struct *s)
{
	if (s->b->nb < 2)
		return ;
	if (s->option_a == 1)
	{
		displaylst(s);
		ft_printf("\n%30s\n", "OPERATION EFFECTUEE : RB");
		ft_printf("\n %s\n", "----------------------------------------");
	}
	first_is_last(s->b);
	s->nb_coups++;
	s->str = ft_strjoin3(s->str, ft_strdup("rb\n"));
	get_info(s->b);
}

void		rr(t_struct *s)
{
	ra(s);
	rb(s);
	s->nb_coups--;
	s->str = ft_strjoin3(s->str, ft_strdup("rr\n"));
	get_info(s->a);
	get_info(s->b);
}
