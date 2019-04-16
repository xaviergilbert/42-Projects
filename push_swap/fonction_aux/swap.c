/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:13:34 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/16 17:30:22 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		swap_firsttwo(t_liste *liste)
{
	t_element		*tmp1;
	t_element		*tmp2;
	t_element		*tmp3;

	tmp1 = liste->premier;
	tmp2 = tmp1->suivant;
	tmp3 = tmp2->suivant;
	if (tmp3 != NULL)
	{
		tmp1->suivant = tmp3;
		liste->premier = tmp2;
		tmp2->suivant = tmp1;
	}
	else
	{
		tmp1->suivant = NULL;
		liste->premier = tmp2;
		tmp2->suivant = tmp1;
	}
}

void		sa(t_struct *s, t_liste *liste)
{
	if (s->a->nb < 2)
		return ;
	if (s->option_a == 1)
	{
		displaylst(s);
		ft_printf("\n%30s\n", "OPERATION EFFECTUEE : SA");
		ft_printf("\n %s\n", "----------------------------------------");
	}
	swap_firsttwo(liste);
	s->nb_coups++;
	s->str = ft_strjoin3(s->str, ft_strdup("sa\n"));
	get_info(s->a);
}

void		sb(t_struct *s, t_liste *liste)
{
	if (s->b->nb < 2)
		return ;
	if (s->option_a == 1)
	{
		displaylst(s);
		ft_printf("\n%30s\n", "OPERATION EFFECTUEE : SB");
		ft_printf("\n %s\n", "----------------------------------------");
	}
	swap_firsttwo(liste);
	s->nb_coups++;
	s->str = ft_strjoin3(s->str, ft_strdup("sb\n"));
	get_info(s->b);
}

void		ss(t_struct *s)
{
	sa(s, s->a);
	sb(s, s->b);
	s->nb_coups--;
	s->str = ft_strjoin3(s->str, ft_strdup("ss\n"));
	get_info(s->a);
	get_info(s->b);
}
