/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_increment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:43:00 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/02 16:53:51 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

static int		inc_calculator(int type, int id_op)
{
	static int	op_two[6] = {0x09, 0x0A, 0x0B, 0x0C, 0x0E, 0x0F};
	int			two;
	int			i;

	two = 0;
	i = 0;
	while (i < 6)
	{
		if (id_op == op_two[i])
			two = 1;
		i++;
	}
	if (type == 3)
		return (2);
	if (type == 2)
	{
		if (two)
			return (2);
		else
			return (4);
	}
	return (type == 1);
}

int				pc_increment(char *op)
{
	int			res;
	int			attempt;

	attempt = g_op_tab[(int)op[0]].arg_count;
	res = 2;
	res += inc_calculator((op[1] >> 6) & 0x03, op[0]);
	if (attempt >= 2)
		res += inc_calculator((op[1] >> 4) & 0x03, op[0]);
	if (attempt >= 3)
		res += inc_calculator((op[1] >> 2) & 0x03, op[0]);
	return (res);
}
