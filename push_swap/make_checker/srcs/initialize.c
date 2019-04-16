/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:02 by alanter           #+#    #+#             */
/*   Updated: 2018/09/19 18:17:08 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		parse_arg(int argc, char **argv, t_stk *stk)
{
	int		nb_values;
	char	*str_arg;

	if (ft_strlen(argv[1]) != 0 && ft_strcmp(argv[1], "-v") == 0)
		stk->option = 1;
	if (stk->option == 1)
		str_arg = argv[2];
	else
		str_arg = argv[1];
	if (argc == 2 || (stk->option == 1 && argc == 3))
	{
		stk->arg = 1;
		nb_values = ft_wordcounter(str_arg, ' ');
	}
	else
		nb_values = argc - 1 - stk->option;
	return (nb_values);
}

static int		check_dbl(int *top, int stored_val, int new_nb)
{
	while (stored_val--)
	{
		if (top[stored_val] == new_nb)
		{
			write(2, "Error : a number can't be there twice.\n", 39);
			exit(1);
		}
	}
	return (0);
}

static int		init_stk_a(t_stk *stk, int argc, char **argv, int nb_values)
{
	static int	i = -1;
	static int	k = 0;
	int			op;

	op = stk->option + 1;
	if (stk->arg == 1)
	{
		while (++i < nb_values && argv[op][k] != 0)
		{
			if (check_dbl(&stk->stk_a[nb_values - i], i, ft_atoi(&argv[op][k])))
				return (1);
			stk->stk_a[nb_values - 1 - i] = ft_atoi(&argv[op][k]);
			while (argv[op][k] != ' ' && argv[op][k] != 0)
				k++;
			while (argv[op][k] == ' ' && argv[op][k] != 0)
				k++;
		}
	}
	while (++i < nb_values)
	{
		if (check_dbl(stk->stk_a, i, ft_atoi(argv[argc - 1 - i])))
			return (1);
		stk->stk_a[i] = ft_atoi(argv[argc - 1 - i]);
	}
	return (0);
}

int				init_t_stk(t_stk *stk, int argc, char **argv)
{
	stk->nb_values = parse_arg(argc, argv, stk);
	if (!(stk->stk_a = (int*)ft_memalloc(sizeof(int*) * stk->nb_values)))
		return (-1);
	if (!(stk->stk_b = (int*)ft_memalloc(sizeof(int*) * stk->nb_values)))
		return (-1);
	stk->top_a = stk->nb_values - 1;
	stk->top_b = -1;
	if (init_stk_a(stk, argc, argv, stk->nb_values))
		return (-1);
	return (stk->nb_values);
}
