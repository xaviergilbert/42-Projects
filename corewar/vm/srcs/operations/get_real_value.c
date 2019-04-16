/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:45:19 by akhercha          #+#    #+#             */
/*   Updated: 2019/03/20 15:29:31 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

static int		does_mod(int opc)
{
	int			i;
	static int	no_mod[4] = { 9, 13, 14, 15 };

	i = 0;
	while (i < 4)
	{
		if (opc == no_mod[i])
			return (0);
		i++;
	}
	return (1);
}

int				get_real_value(t_vm *vm, t_process *proc, t_instruction *instr,
	int i)
{
	char	allo[4];
	short	ind;

	if (instr->argtype_tab[i] == DIR_CODE)
		return (instr->arg_list[i]);
	else if (instr->argtype_tab[i] == REG_CODE)
		return (proc->reg[instr->arg_list[i] - 1]);
	else if (instr->argtype_tab[i] == IND_CODE)
	{
		ind = (short)(instr->arg_list[i]);
		if (does_mod(proc->op_code))
			ind %= IDX_MOD;
		ind += proc->pc;
		allo[0] = vm->arena[ind % MEM_SIZE + MEM_SIZE * (ind < 0)] & 0xff;
		allo[1] = vm->arena[((ind + 1) % MEM_SIZE) + (MEM_SIZE
			* ((ind + 1) < 0))] & 0xff;
		allo[2] = vm->arena[((ind + 2) % MEM_SIZE) + (MEM_SIZE
			* ((ind + 2) < 0))] & 0xff;
		allo[3] = vm->arena[((ind + 3) % MEM_SIZE) + (MEM_SIZE
			* ((ind + 3) < 0))] & 0xff;
		return (fourchar_to_int(allo));
	}
	return (0);
}
