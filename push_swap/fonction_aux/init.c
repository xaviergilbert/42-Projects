/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 19:52:12 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/17 15:27:14 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			init(t_struct *s, int nb)
{
	s->nb_coups = 0;
	if (!(s->a = (t_liste*)malloc(sizeof(*s->a))))
		return (0);
	if (!(s->b = (t_liste*)malloc(sizeof(*s->a))))
	{
		free(s->a);
		return (0);
	}
	s->a->premier = NULL;
	s->b->premier = NULL;
	s->a->nb = nb - 1 - s->option_a - s->option_i - s->option_s;
	s->b->nb = 0;
	s->str = ft_strdup("");
	s->flag = 0;
	return (1);
}
