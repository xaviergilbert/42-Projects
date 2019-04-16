/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:05:48 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/04/01 16:55:51 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int					op_or(t_vm *vm, t_process *proc, char *op)
{
	int				a;
	int				b;
	t_instruction	instruction;
	int				res;

	if ((res = get_argument(op, &instruction)) <= 0)
	{
		if (!has_valid_args(&instruction))
			return (print_debug(vm, op, pc_increment(op), proc));
		return (-1);
	}
	if (!has_valid_args(&instruction))
	{
		free_instruction(&instruction);
		return (print_debug(vm, op, pc_increment(op), proc));
	}
	a = get_real_value(vm, proc, &instruction, 0);
	b = get_real_value(vm, proc, &instruction, 1);
	proc->reg[instruction.arg_list[2] - 1] = a | b;
	proc->carry = !proc->reg[instruction.arg_list[2] - 1];
	free_instruction(&instruction);
	print_debug(vm, op, pc_increment(op), proc);
	return (res);
}
