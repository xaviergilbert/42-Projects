/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:51:55 by akhercha          #+#    #+#             */
/*   Updated: 2019/03/31 14:51:55 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int				twochar_to_int(char *str)
{
	int a;

	a = 0;
	a = (int)str[0] & 0xff;
	a = a << 8;
	a += (int)str[1] & 0xff;
	return (a);
}

int				fourchar_to_int(char *str)
{
	int a;

	a = 0;
	a += (int)str[0] & 0xff;
	a = (a << 8);
	a += (int)str[1] & 0xff;
	a = a << 8;
	a += (int)str[2] & 0xff;
	a = a << 8;
	a += (int)str[3] & 0xff;
	return (a);
}

static int		is_dir_two(int id_op)
{
	static int	op_two[6] = { 0x09, 0x0A, 0x0B, 0x0C, 0x0E, 0x0F };
	int			two;
	int			i;

	i = 0;
	two = 0;
	while (i < 6)
	{
		if (id_op == op_two[i])
			two = 1;
		i++;
	}
	return (two);
}

int				get_args(char *op, int type, int id_op, int *arg)
{
	int			two;

	two = is_dir_two(id_op);
	if (type == 3 || (type == 2 && two))
	{
		*arg = twochar_to_int(op);
		return (2);
	}
	if (type == 2)
	{
		*arg = fourchar_to_int(op);
		return (4);
	}
	if (type == 1)
	{
		*arg = (int)op[0];
		return (1);
	}
	return (0);
}
