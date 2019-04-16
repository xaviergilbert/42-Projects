/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_are_valids.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:34:00 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/05 11:32:19 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	check_arg(char **av, int actual_arg, int *nb_champs)
{
	if ((ft_strcmp(av[actual_arg], "-dump") != 0)
		&& (ft_strcmp(av[actual_arg], "-n") != 0)
		&& (ft_strcmp(av[actual_arg], "-debug") != 0)
		&& !ft_str_ends_with(av[actual_arg], ".cor"))
		return (-1);
	if (ft_strcmp(av[actual_arg], "-dump") == 0)
	{
		if (!ft_isnumber(av[++actual_arg])
			|| !ft_is_positive_int(av[actual_arg]))
			return (-1);
	}
	else if (ft_strcmp(av[actual_arg], "-n") == 0)
	{
		if (!ft_isnumber(av[++actual_arg])
			|| !ft_is_positive_int(av[actual_arg])
			|| !ft_str_ends_with(av[++actual_arg], ".cor"))
			return (-1);
		(*nb_champs)++;
	}
	else if (ft_str_ends_with(av[actual_arg], ".cor"))
		(*nb_champs)++;
	return (actual_arg);
}

int			args_are_valids(int ac, char **av)
{
	int		actual_arg;
	int		nb_champs;

	actual_arg = 1;
	nb_champs = 0;
	while (actual_arg < ac)
	{
		if ((actual_arg = check_arg(av, actual_arg, &nb_champs)) == -1)
			return (0);
		actual_arg++;
	}
	return ((nb_champs > 0) && (nb_champs <= MAX_PLAYERS));
}
