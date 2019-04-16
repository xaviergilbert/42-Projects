/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:42:17 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/01 16:53:43 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int					op_aff(t_vm *vm, t_process *proc, char *op)
{
	t_instruction	instruction;
	int				res;

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
	print_debug(vm, op, res, proc);
	instruction.arg_list[0] %= 256;
	ft_printf("%c", instruction.arg_list[0]);
	free_instruction(&instruction);
	return (res);
}
