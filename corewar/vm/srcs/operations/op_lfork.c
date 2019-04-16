/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:18:07 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/02 20:21:44 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int					op_lfork(t_vm *vm, t_process *proc, char *op)
{
	t_instruction	instruction;
	t_process		*new;
	int				res;

	if ((res = get_argument(op, &instruction)) <= 0)
		return (-1);
	if (!(new = new_process()))
		return (EXIT_FAILURE);
	cpy_process(&new, proc);
	new->pc += (short)get_real_value(vm, proc, &instruction, 0);
	new->pc = new->pc % MEM_SIZE + MEM_SIZE * (new->pc < 0);
	new->op_code = 0;
	new->next = NULL;
	new->carry = proc->carry;
	new->id = ++(vm->nb_process);
	link_process(vm, new);
	free_instruction(&instruction);
	return (res);
}
