/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:30:53 by alanter           #+#    #+#             */
/*   Updated: 2018/09/19 19:52:09 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			sorted(t_stk *stk, int size)
{
	int			nb_sort;
	static int	i = 0;

	nb_sort = 0;
	while (nb_sort + 1 < size && stk->stk_a[nb_sort + 1] < stk->stk_a[nb_sort])
		nb_sort++;
	if (nb_sort + 1 >= size && i == 0)
	{
		ft_printf("OK\n");
		i = 1;
		return (1);
	}
	else if (i == 0)
	{
		ft_printf("KO\n");
		i = -1;
		return (-1);
	}
	if (i == 1)
		return (1);
	else if (i == -1)
		return (-1);
	return (0);
}

static int	check_string(char **argv, int i)
{
	int j;

	j = 0;
	while (argv[i][j] != 0)
	{
		if (ft_atoll(&argv[i][j]) > INT_MAX || ft_atoll(&argv[i][j]) < INT_MIN
				|| ft_strchr(&argv[i][j], ' ') - &argv[i][j] > 12)
		{
			write(2, "Error : int only.\n", 18);
			exit(-1);
		}
		if (ft_isdigit(argv[i][j]) || argv[i][j] == ' ')
			j++;
		else if (argv[i][j] != 0 && argv[i][j] == '-' &&
				ft_isdigit(argv[i][j + 1]) && (j == 0 || argv[i][j - 1] == ' '))
			j++;
		else if (argv[i][j] != 0)
		{
			write(2, "error : valid numbers, space and - only.\n", 41);
			exit(-1);
		}
	}
	return (0);
}

static int	check_input(int argc, char **argv, t_stk *stk)
{
	int i;

	i = 0;
	if (!(ft_strcmp(argv[1], "-v")) && (i += 1))
		stk->visual = 1;
	while (++i < argc)
	{
		if (i == 1 || (stk->visual == 1 && i == 2))
			check_string(argv, i);
		else if (((ft_strlen(argv[i]) > 12))
			|| ft_atoll(argv[i]) > INT_MAX || ft_atoll(argv[i]) < INT_MIN)
		{
			write(2, "Error : int only.\n", 18);
			exit(-1);
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_stk	*stk;

	if (ac < 1 || av[1] == NULL || !(stk = (t_stk*)ft_memalloc(sizeof(t_stk))))
		return (-1);
	if (!(check_input(ac, av, stk)))
	{
		if ((stk->nb_values = init_t_stk(stk, ac, av)) == -1)
			return (-1);
		if (stk->visual != 1)
		{
			while (get_next_line(0, &stk->inst) > 0)
			{
				inst(stk->inst, stk);
				free(stk->inst);
			}
			free(stk->inst);
		}
		else
			window(*stk);
		sorted(stk, stk->nb_values);
	}
	free(stk->stk_a);
	free(stk->stk_b);
	free(stk);
	return (0);
}
