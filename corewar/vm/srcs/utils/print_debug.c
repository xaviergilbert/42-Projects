/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avancement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:16:46 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/02 15:49:36 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int			print_debug(t_vm *vm, char *op, int size, t_process *proc)
{
	int		i;
	int		j;

	i = 0;
	j = proc->pc;
	if (vm->debug)
	{
		ft_printf("ADV %d (0x%04.4x -> 0x%04.4x) ", size, proc->pc,
			proc->pc + size);
		while (i < size)
		{
			ft_printf("%x ", vm->arena[j % MEM_SIZE]);
			j++;
			i++;
		}
		ft_printf("\n");
	}
	return (pc_increment(op));
}
