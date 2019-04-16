/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:50:00 by alanter           #+#    #+#             */
/*   Updated: 2018/09/13 04:02:27 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(int *stack, int top)
{
	int	tmp;

	if (top > 0)
	{
		tmp = stack[top];
		stack[top] = stack[top - 1];
		stack[top - 1] = tmp;
	}
}

void	ft_rotate(int *stack, int top)
{
	int	tmp;
	int i;

	if (top > 0)
	{
		i = -1;
		tmp = stack[top];
		while (top - i - 1 >= 0 && ++i < top)
			stack[top - i] = stack[top - i - 1];
		stack[0] = tmp;
	}
}

void	ft_rev_rotate(int *stack, int top)
{
	int	tmp;
	int i;

	if (top > 0)
	{
		i = -1;
		tmp = stack[0];
		while (++i < top)
			stack[i] = stack[i + 1];
		stack[top] = tmp;
	}
}

void	ft_push(int *src, int *dst, int *top_s, int *top_d)
{
	if (*top_s >= 0)
	{
		(*top_d)++;
		dst[*top_d] = src[*top_s];
		(*top_s)--;
	}
}
