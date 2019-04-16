/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:30:52 by alanter           #+#    #+#             */
/*   Updated: 2018/09/19 03:07:40 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec(t_stk *stk, int i)
{
	void	(*ptr[4])(int *stack, int top);

	ptr[0] = ft_swap;
	ptr[1] = ft_rotate;
	ptr[2] = ft_rev_rotate;
	if (i < 3)
		(*ptr[i])(stk->stk_a, stk->top_a);
	else if (i < 6)
		(*ptr[i - 3])(stk->stk_b, stk->top_b);
	else if (i < 9)
	{
		(*ptr[i - 6])(stk->stk_a, stk->top_a);
		(*ptr[i - 6])(stk->stk_b, stk->top_b);
	}
	else if (i == 9)
		ft_push(stk->stk_b, stk->stk_a, &(stk->top_b), &(stk->top_a));
	else if (i == 10)
		ft_push(stk->stk_a, stk->stk_b, &(stk->top_a), &(stk->top_b));
}

void		inst(char *inst_in, t_stk *stk)
{
	int			i;
	static char	*inst[] = {"sa", "ra", "rra", "sb", "rb", "rrb", "ss", "rr",
		"rrr", "pa", "pb"};

	i = 0;
	while (i < 11)
	{
		if (!(ft_strcmp(inst[i], inst_in)))
			break ;
		i++;
	}
	if (i >= 11)
	{
		write(2, "Error : wrong instruction\n", 26);
		exit(0);
	}
	else
		exec(stk, i);
}
