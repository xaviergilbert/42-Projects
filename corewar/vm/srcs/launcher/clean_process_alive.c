/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process_alive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 04:29:54 by xgilbert          #+#    #+#             */
/*   Updated: 2019/03/26 14:02:22 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					clean_process_alive(t_vm *vm)
{
	t_process		*current_process;
	int				i;

	i = 0;
	current_process = vm->process_list;
	while (current_process)
	{
		if (current_process->live == 0)
			current_process = elimination_a_la_batte_le_processus(vm, i--);
		else
		{
			current_process->live = 0;
			current_process = current_process->next;
		}
		i++;
	}
	vm->nb_live = 0;
	return (i > 0);
}
