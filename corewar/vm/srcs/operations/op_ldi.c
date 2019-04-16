/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:12:07 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/02 20:21:48 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

static void			assign_reg(int reg_id, t_vm *vm, t_process *proc, int tmp)
{
	proc->reg[reg_id] = vm->arena[tmp] << 24;
	proc->reg[reg_id] += vm->arena[((tmp + 1) % MEM_SIZE)
		+ MEM_SIZE * (tmp < 0)] << 16;
	proc->reg[reg_id] += vm->arena[((tmp + 2) % MEM_SIZE)
		+ MEM_SIZE * (tmp < 0)] << 8;
	proc->reg[reg_id] += vm->arena[((tmp + 3) % MEM_SIZE)
		+ MEM_SIZE * (tmp < 0)];
}

int					op_ldi(t_vm *vm, t_process *proc, char *op)
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
	tmp = (short)get_real_value(vm, proc, &instruction, 0)
		+ (short)get_real_value(vm, proc, &instruction, 1);
	tmp %= IDX_MOD;
	tmp += proc->pc;
	tmp = tmp % MEM_SIZE + MEM_SIZE * (tmp < 0);
	assign_reg(instruction.arg_list[2] - 1, vm, proc, tmp);
	print_debug(vm, op, res, proc);
	free_instruction(&instruction);
	return (res);
}
