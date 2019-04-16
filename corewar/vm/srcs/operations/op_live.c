/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:20:25 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/01 16:55:09 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int					op_live(t_vm *vm, t_process *proc, char *op)
{
	t_champ			*champ;
	t_instruction	instruction;
	int				id;
	int				res;

	proc->live++;
	vm->nb_live++;
	if ((res = get_argument(op, &instruction)) <= 0)
		return (-1);
	id = get_real_value(vm, proc, &instruction, 0);
	if (!(champ = get_champ_by_id(vm->champs, id)))
	{
		free_instruction(&instruction);
		return (res);
	}
	vm->last_champ_alive = champ->id;
	ft_printf("[%d]%s a été rapporté comme en vie !\n",
		champ->id * (-1), champ->data.header.prog_name);
	print_debug(vm, op, res, proc);
	free_instruction(&instruction);
	return (res);
}
