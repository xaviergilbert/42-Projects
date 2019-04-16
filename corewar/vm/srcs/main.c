/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:28:25 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/04 13:33:28 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				main(int ac, char **av)
{
	t_vm		vm;

	if (ac < 2 || !args_are_valids(ac, av))
	{
		ft_putstr("usage: ./corewar [-debug] [-dump nbr_cycles]");
		ft_putendl("[[-n number] chp1.cor] ...");
		return (EXIT_FAILURE);
	}
	init_vm(&vm);
	fill_vm_with_argv(&vm, ac, av);
	if (init_corewar(&vm) == EXIT_FAILURE)
		free_and_quit(&vm, MALLOC_ERR_MSG, EXIT_FAILURE);
	if (exec_vm(&vm) == EXIT_FAILURE)
		free_and_quit(&vm, MALLOC_ERR_MSG, EXIT_FAILURE);
	display_ending(&vm);
	return (EXIT_SUCCESS);
}
