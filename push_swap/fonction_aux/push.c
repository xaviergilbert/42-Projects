/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:18:45 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/17 14:51:38 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		pa(t_struct *s)
{
	t_element	*element;

	if (s->b->nb == 0)
		return ;
	if (s->option_a == 1)
	{
		displaylst(s);
		ft_printf("\n%30s\n", "OPERATION EFFECTUEE : PA");
		ft_printf("\n %s\n", "----------------------------------------");
	}
	element = s->a->premier;
	s->a->premier = s->b->premier;
	s->b->premier = s->b->premier->suivant;
	s->a->premier->suivant = element;
	s->b->nb--;
	s->a->nb++;
	s->nb_coups++;
	s->str = ft_strjoin3(s->str, ft_strdup("pa\n"));
	get_info(s->a);
	get_info(s->b);
}

void		pb(t_struct *s)
{
	t_element	*element;

	if (s->a->nb == 0)
		return ;
	if (s->option_a == 1)
	{
		displaylst(s);
		ft_printf("\n%30s\n", "OPERATION EFFECTUEE : PB");
		ft_printf("\n %s\n", "----------------------------------------");
	}
	element = s->b->premier;
	s->b->premier = s->a->premier;
	s->a->premier = s->a->premier->suivant;
	s->b->premier->suivant = element;
	s->b->nb++;
	s->a->nb--;
	s->nb_coups++;
	s->str = ft_strjoin3(s->str, ft_strdup("pb\n"));
	get_info(s->a);
	get_info(s->b);
}
