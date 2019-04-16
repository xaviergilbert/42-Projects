/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaylst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:41:12 by xgilbert          #+#    #+#             */
/*   Updated: 2018/09/13 18:44:41 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			ft_print_instr(char **split)
{
	int				j;

	j = 0;
	while (split[j] != 0)
	{
		if (split[j][0] != '\0')
		{
			ft_putstr(split[j++]);
			ft_putchar('\n');
		}
		else
			j++;
	}
}

void			displaylst(t_struct *s)
{
	t_element		*element_a;
	t_element		*element_b;

	if (s->a == NULL)
		return ;
	element_a = s->a->premier;
	element_b = s->b->premier;
	ft_printf("\n%22s %10s %22s\n", "LISTE A", "||||", "LISTE B");
	while (element_a != NULL)
	{
		ft_printf("Nb : %10d / Pos : %.3d   ||   ",
		element_a->nombre, element_a->pos);
		element_a = element_a->suivant;
		if (element_b != NULL)
		{
			ft_printf("Nb : %10d / Pos : %.3d %4s\n",
			element_b->nombre, element_b->pos, "||");
			element_b = element_b->suivant;
		}
		else
			ft_printf("\n");
	}
	s->option_s-- == 2 ? sleep(1) : s->option_s++;
}
