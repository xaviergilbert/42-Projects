/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:14:30 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/05 11:51:47 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		dump_memory(t_mem *arena)
{
	int			i;

	if (!arena)
		return (EXIT_FAILURE);
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("0x%04.4x : ", i);
		ft_printf("%02x ", arena[i++]);
		if (i % 64 == 0)
			ft_printf("\n");
	}
	ft_printf("\n");
	return (EXIT_SUCCESS);
}

static int		show_winner(t_vm *vm)
{
	t_champ		*c;

	if ((c = get_champ_by_id(vm->champs, vm->last_champ_alive)) == NULL)
	{
		ft_printf("Error: winner at last_champ_alive not found.\n");
		return (EXIT_FAILURE);
	}
	ft_printf("Le joueur %d(%s) a gagné.\n", c->id * -1,
		c->data.header.prog_name);
	return (EXIT_SUCCESS);
}

int				display_ending(t_vm *vm)
{
	if (vm->dump_nb > -1)
	{
		dump_memory(vm->arena);
		if (vm->process_list == NULL)
			show_winner(vm);
		free_process(vm);
	}
	else
		show_winner(vm);
	return (EXIT_SUCCESS);
}
