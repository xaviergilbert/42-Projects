/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:05:48 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/04/02 20:21:25 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int					op_sub(t_vm *vm, t_process *proc, char *op)
{
	t_instruction	instr;
	int				res;
	int				ret;

	(void)vm;
	if ((res = get_argument(op, &instr)) <= 0)
	{
		if (!has_valid_args(&instr))
			return (print_debug(vm, op, pc_increment(op), proc));
		return (-1);
	}
	if (!has_valid_args(&instr))
	{
		free_instruction(&instr);
		return (print_debug(vm, op, pc_increment(op), proc));
	}
	proc->reg[instr.arg_list[2] - 1] = proc->reg[instr.arg_list[1] - 1]
		- proc->reg[instr.arg_list[0] - 1];
	proc->carry = !proc->reg[instr.arg_list[2] - 1];
	ret = res;
	print_debug(vm, op, res, proc);
	free_instruction(&instr);
	return (ret);
}
