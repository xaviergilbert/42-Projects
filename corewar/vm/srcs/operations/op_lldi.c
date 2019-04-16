/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:05:48 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/04/01 16:55:27 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

static void	assign_reg_lldi(int tmp, t_instruction *instr,
	t_process *proc, t_vm *vm)
{
	int reg_id;

	reg_id = instr->arg_list[2] - 1;
	instr->arg_list[0] = tmp;
	instr->argtype_tab[0] = IND_CODE;
	proc->reg[reg_id] = get_real_value(vm, proc, instr, 0);
}

int			op_lldi(t_vm *vm, t_process *proc, char *op)
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
	tmp += proc->pc;
	tmp = tmp % MEM_SIZE + MEM_SIZE * (tmp < 0);
	assign_reg_lldi(tmp, &instruction, proc, vm);
	proc->carry = !proc->reg[instruction.arg_list[2] - 1];
	print_debug(vm, op, res, proc);
	free_instruction(&instruction);
	return (res);
}
