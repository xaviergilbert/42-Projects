/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:05:48 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/04/01 16:55:18 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int					op_lld(t_vm *vm, t_process *proc, char *op)
{
	t_instruction	instr;
	int				res;

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
	proc->reg[instr.arg_list[1] - 1] = get_real_value(vm, proc, &instr, 0);
	proc->carry = !proc->reg[instr.arg_list[1] - 1];
	free_instruction(&instr);
	return (res);
}
