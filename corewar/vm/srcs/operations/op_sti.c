/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:05:48 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/04/01 16:56:11 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int					op_sti(t_vm *vm, t_process *proc, char *op)
{
	t_instruction	instruction;
	int				res;
	int				tmp;

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
	tmp = (short)get_real_value(vm, proc, &instruction, 1)
		+ (short)get_real_value(vm, proc, &instruction, 2);
	tmp %= IDX_MOD;
	tmp += proc->pc;
	tmp = tmp % MEM_SIZE + MEM_SIZE * (tmp < 0);
	int_to_fourchar(proc->reg[instruction.arg_list[0] - 1], vm->arena, tmp);
	print_debug(vm, op, res, proc);
	free_instruction(&instruction);
	return (res);
}
