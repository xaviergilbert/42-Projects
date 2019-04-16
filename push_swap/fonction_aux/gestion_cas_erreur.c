/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_cas_erreur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:54:47 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/17 16:02:40 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			check_format(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][0] == '-' || str[i][0] == '+')
				j++;
			else if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int			overflow(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = ft_itoa_base(ft_atoi(str[i]), 10);
		if (ft_strcmp(str[i], tmp) != 0)
		{
			free(tmp);
			return (0);
		}
		free(tmp);
		i++;
	}
	return (1);
}

int			doublons(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		if (str[j])
		{
			while (str[j] && ft_atoi(str[i]) != ft_atoi(str[j]))
				j++;
			if (str[j] && ft_atoi(str[i]) == ft_atoi(str[j]))
				return (0);
		}
		i++;
	}
	return (1);
}

void		check_option(t_struct *s, char **str)
{
	int		i;

	s->option_a = 0;
	s->option_i = 0;
	s->option_s = 0;
	i = 0;
	while (str[i])
		i++;
	if (ft_strcmp(str[0], "-a") == 0 || (i > 1 && ft_strcmp(str[1], "-a") == 0)
	|| (i > 2 && ft_strcmp(str[2], "-a") == 0))
		s->option_a = 1;
	if (ft_strcmp(str[0], "-i") == 0 || (i > 1 && ft_strcmp(str[1], "-i") == 0)
	|| (i > 2 && ft_strcmp(str[2], "-i") == 0))
		s->option_i = 1;
	if (ft_strcmp(str[0], "-s") == 0 || (i > 1 && ft_strcmp(str[1], "-s") == 0)
	|| (i > 2 && ft_strcmp(str[2], "-s") == 0))
		s->option_s = 1;
}

void		gestion_cas_erreur(t_struct *s, char **str)
{
	check_option(s, str);
	str += s->option_a + s->option_i + s->option_s;
	if (!(check_format(str)))
	{
		ft_printf("Error\n");
		exit(0);
	}
	if (!(overflow(str)))
	{
		ft_printf("Error\n");
		exit(0);
	}
	if (!(doublons(str)))
	{
		ft_printf("Error\n");
		exit(0);
	}
}
