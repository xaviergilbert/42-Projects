/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:41:27 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/04 15:38:01 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

static int		check_nb_lives(t_vm *vm, int nb_checks)
{
	if (vm->nb_live >= NBR_LIVE)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		nb_checks = 0;
	}
	else
		nb_checks++;
	if (nb_checks >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		nb_checks = 0;
	}
	return (nb_checks);
}

int				exec_vm(t_vm *vm)
{
	int			nb_checks;
	int			cycles;
	int			ret;

	nb_checks = 0;
	if (vm->dump_nb == 0)
		return (EXIT_SUCCESS);
	while (clean_process_alive(vm))
	{
		cycles = 0;
		while (cycles < vm->cycle_to_die)
		{
			ret = for_each_cycle(vm);
			if ((ret == EXIT_FAILURE) || (ret == EXIT_DUMP))
				return (ret);
			cycles++;
		}
		nb_checks = check_nb_lives(vm, nb_checks);
	}
	return (EXIT_SUCCESS);
}
