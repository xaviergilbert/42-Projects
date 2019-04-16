/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:33:21 by xgilbert          #+#    #+#             */
/*   Updated: 2018/09/06 19:52:11 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			troisieme_partie(t_struct *s)
{
	get_pos_lst(s->a);
	if (s->b->nb == 0 && check_tri(s->a, s->a->nb) == 1)
	{
		ft_printf("OK\n");
		return (0);
	}
	else
	{
		ft_printf("KO\n");
		return (0);
	}
	return (0);
}

void		module(t_struct *s, char **line)
{
	if (ft_strcmp(*line, "pa") == 0)
		pa(s);
	else if (ft_strcmp(*line, "pb") == 0)
		pb(s);
	else if (ft_strcmp(*line, "sa") == 0)
		sa(s, s->a);
	else if (ft_strcmp(*line, "sb") == 0)
		sb(s, s->b);
	else if (ft_strcmp(*line, "ss") == 0)
		ss(s);
	else if (ft_strcmp(*line, "ra") == 0)
		ra(s);
	else if (ft_strcmp(*line, "rb") == 0)
		rb(s);
	else if (ft_strcmp(*line, "rr") == 0)
		rr(s);
	else if (ft_strcmp(*line, "rra") == 0)
		rra(s);
	else if (ft_strcmp(*line, "rrb") == 0)
		rrb(s);
	else if (ft_strcmp(*line, "rrr") == 0)
		rrr(s);
}

int			deuxieme_partie(t_struct *s)
{
	int			r;
	char		*line;

	while ((r = get_next_line(0, &line) != 0) && r != -1)
	{
		if (!(ft_strcmp(line, "pa") == 0 || ft_strcmp(line, "pb") == 0
		|| ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0
		|| ft_strcmp(line, "ss") == 0 || ft_strcmp(line, "ra") == 0
		|| ft_strcmp(line, "rb") == 0 || ft_strcmp(line, "rr") == 0
		|| ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0
		|| ft_strcmp(line, "rrr") == 0))
		{
			ft_printf("Error\n");
			free(line);
			return (0);
		}
		module(s, &line);
		free(line);
	}
	troisieme_partie(s);
	return (0);
}

int			main(int ac, char **av)
{
	t_struct	s;
	int			i;

	i = ac - 1;
	if (ac < 2)
		return (0);
	gestion_cas_erreur(&s, av + 1);
	if (!(init(&s, ac)))
		return (0);
	while (0 < i)
		insertlst(s.a, ft_atoi(av[i--]));
	deuxieme_partie(&s);
	dellst(s.a);
	dellst(s.b);
	free(s.str);
	free(s.a);
	free(s.b);
	return (0);
}
