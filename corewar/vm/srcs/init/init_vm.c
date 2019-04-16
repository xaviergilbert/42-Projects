/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:01:11 by akhercha          #+#    #+#             */
/*   Updated: 2019/03/30 15:37:37 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	init_champs(t_champ *champs)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		champs[i].id = -1;
		ft_bzero(&(champs[i].data), sizeof(t_champ_data));
		champs[i].filepath = NULL;
		champs[i].last_cycle_alive = -1;
		i++;
	}
	return (EXIT_SUCCESS);
}

int			init_vm(t_vm *vm)
{
	ft_bzero(vm->arena, MEM_SIZE);
	init_champs(vm->champs);
	vm->process_list = NULL;
	vm->dump_nb = -1;
	vm->last_champ_alive = -1;
	vm->nb_champs = -1;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->nb_live = 0;
	vm->nb_process = 0;
	vm->debug = 0;
	return (EXIT_SUCCESS);
}
