/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:05:48 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/04/01 15:12:48 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int					op_zjmp(t_vm *vm, t_process *proc, char *op)
{
	t_instruction	instruction;
	signed short	jump;
	int				ret;

	if ((ret = get_argument(op, &instruction)) <= 0)
		return (-1);
	jump = (instruction.arg_list[0]) & 0xFFFF;
	jump %= IDX_MOD;
	if (!proc->carry)
	{
		print_debug(vm, op, 3, proc);
		free_instruction(&instruction);
		return (3);
	}
	proc->pc += jump;
	proc->pc = (proc->pc % MEM_SIZE) + (MEM_SIZE * (proc->pc < 0));
	free_instruction(&instruction);
	return (0);
}
