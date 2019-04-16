/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_cycle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:43:48 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/01 18:16:26 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

static int		process_hub(t_vm *vm, t_process *proc, char *op, int id_op)
{
	static int	(*inst_tab[16])(t_vm *, t_process *, char *) = {
		op_live,
		op_ld,
		op_st,
		op_add,
		op_sub,
		op_and,
		op_or,
		op_xor,
		op_zjmp,
		op_ldi,
		op_sti,
		op_fork,
		op_lld,
		op_lldi,
		op_lfork,
		op_aff
	};

	return (inst_tab[id_op - 1](vm, proc, op));
}

static int		exec_process(t_vm *vm, t_process *current_process)
{
	int			ret;
	char		*op;

	op = NULL;
	op = get_op((char*)vm->arena, current_process->pc,
		current_process->op_code);
	if (op == NULL)
		return (EXIT_FAILURE);
	ret = process_hub(vm, current_process, op, current_process->op_code);
	ft_strdel(&op);
	if (ret == -1)
		return (EXIT_FAILURE);
	current_process->pc = (current_process->pc + ret) % MEM_SIZE;
	current_process->op_code = 0;
	return (EXIT_SUCCESS);
}

static int		check_process_exec(t_vm *vm)
{
	t_process	*current;

	current = vm->process_list;
	while (current)
	{
		if (current->cycles_to_exec == 0 && current->op_code)
		{
			if (exec_process(vm, current) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (current->op_code)
			current->cycles_to_exec--;
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

static int		check_process_opc(t_vm *vm)
{
	t_process	*current;

	current = vm->process_list;
	while (current)
	{
		if (current->op_code == 0 && (vm->arena[current->pc] >= 1
			&& vm->arena[current->pc] <= 16))
		{
			current->op_code = vm->arena[current->pc];
			current->cycles_to_exec = g_op_tab[vm->arena[current->pc]].cycles
				- 1;
		}
		else if (current->op_code == 0)
			current->pc = (current->pc + 1) % MEM_SIZE;
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

int				for_each_cycle(t_vm *vm)
{
	check_process_opc(vm);
	if (check_process_exec(vm) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (--(vm->dump_nb) == 0)
		return (EXIT_DUMP);
	return (EXIT_SUCCESS);
}
