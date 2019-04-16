/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:05:48 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/04/16 18:29:02 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

static void			handle_ind(t_instruction *instr, t_process *proc, t_vm *vm)
{
	int				address;

	address = (short)instr->arg_list[1];
	address %= IDX_MOD;
	address += proc->pc;
	address = address % MEM_SIZE + MEM_SIZE * (address < 0);
	int_to_fourchar(proc->reg[instr->arg_list[0] - 1], vm->arena, address);
}

int					op_st(t_vm *vm, t_process *proc, char *op)
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
	if (instr.argtype_tab[1] == IND_CODE)
		handle_ind(&instr, proc, vm);
	else
		proc->reg[instr.arg_list[1] - 1] = proc->reg[instr.arg_list[0] - 1];
	print_debug(vm, op, res, proc);
	free_instruction(&instr);
	return (res);
}
