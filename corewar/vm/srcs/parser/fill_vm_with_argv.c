/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_vm_with_argv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:51:32 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/01 15:07:49 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		fill_champ(t_vm *vm, char *cor_file, int *id, int cli_flag)
{
	int			i;

	if (!ft_file_exists(cor_file))
		ft_exit_with_msg("Error: file .cor not found.", EXIT_FAILURE);
	if (champ_id_exists(vm->champs, *id))
	{
		if (cli_flag)
			ft_exit_with_msg("Error: duplicated id.", EXIT_FAILURE);
		while (champ_id_exists(vm->champs, *id))
			(*id)++;
	}
	i = 0;
	while (vm->champs[i].id != -1)
		i++;
	vm->champs[i].id = *id++;
	vm->champs[i].filepath = cor_file;
	return (EXIT_SUCCESS);
}

static int		parse_arg(t_vm *vm, char **av, int *actual_arg, int *next_id)
{
	if (ft_strcmp(av[*actual_arg], "-dump") == 0)
		vm->dump_nb = ft_atoi(av[++(*actual_arg)]);
	else if (ft_strcmp(av[*actual_arg], "-debug") == 0)
		vm->debug = 1;
	else if (ft_strcmp(av[*actual_arg], "-n") == 0)
		*actual_arg += 2;
	else if (ft_str_ends_with(av[*actual_arg], ".cor"))
		fill_champ(vm, av[*actual_arg], next_id, 0);
	return (EXIT_SUCCESS);
}

static int		parse_given_id_arg(t_vm *vm, char **av, int *actual_arg)
{
	int			given_id;

	if (ft_strcmp(av[*actual_arg], "-n") == 0)
	{
		*actual_arg += 2;
		given_id = ft_atoi(av[*actual_arg - 1]);
		fill_champ(vm, av[*actual_arg], &given_id, 1);
	}
	return (EXIT_SUCCESS);
}

int				fill_vm_with_argv(t_vm *vm, int ac, char **av)
{
	int			actual_arg;
	int			next_id;

	actual_arg = 1;
	while (actual_arg < ac)
	{
		parse_given_id_arg(vm, av, &actual_arg);
		actual_arg++;
	}
	next_id = 1;
	actual_arg = 1;
	while (actual_arg < ac)
	{
		parse_arg(vm, av, &actual_arg, &next_id);
		actual_arg++;
	}
	return (EXIT_SUCCESS);
}
