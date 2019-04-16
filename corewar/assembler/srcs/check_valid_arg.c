/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:31:32 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 12:39:58 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_valid_reg(char *arg)
{
	int			i;
	int			value;
	int			k;

	k = 0;
	i = 1;
	value = ft_atoi(&arg[1]);
	while (ft_isdigit(arg[i]))
	{
		if (arg[i] == '0')
			k++;
		i++;
	}
	if (i != 1 && i - k <= 3 && !arg[i] && value > 0 && value <= REG_NUMBER)
		return (1);
	return (0);
}

int			check_valid_dir(char *arg)
{
	int			i;

	i = 1;
	if (arg[i] == '\0')
		return (0);
	if (arg[i] == LABEL_CHAR)
	{
		i++;
		while (arg[i] && ft_strchr(LABEL_CHARS, arg[i]))
			i++;
	}
	else if (ft_isdigit(arg[i]) || arg[i] == '-')
	{
		if (arg[i] == '-')
			i++;
		while (arg[i] && ft_isdigit(arg[i]))
			i++;
	}
	if (arg[i] == '\0')
		return (1);
	return (0);
}

int			check_valid_ind(char *arg)
{
	int			i;

	i = 0;
	if (ft_isdigit(arg[i]) || arg[i] == LABEL_CHAR || arg[i] == '-')
	{
		if (arg[i] == LABEL_CHAR)
		{
			i++;
			while (arg[i] && ft_strchr(LABEL_CHARS, arg[i]))
				i++;
		}
		else if (ft_isdigit(arg[i]) || arg[i] == '-')
		{
			if (arg[i] == '-')
				i++;
			while (ft_isdigit(arg[i]))
				i++;
		}
		if (!arg[i])
			return (1);
	}
	return (0);
}

void		check_valid_arg(t_asm *tasm, int n, int a, int type)
{
	int			res;

	res = -1;
	if (type == 1 && (res = check_valid_reg(tasm->instr[n]->args[a])) == 0)
		ft_printf("Register >[%s]< not valid for instruction [%s] in line : ",
		tasm->instr[n]->args[a], tasm->instr[n]->name);
	else if (type == 2 && (res = check_valid_dir(tasm->instr[n]->args[a])) == 0)
		ft_printf("Direct arg >[%s]< not valid for instruction [%s] in line : ",
		tasm->instr[n]->args[a], tasm->instr[n]->name);
	else if (type == 3 && (res = check_valid_ind(tasm->instr[n]->args[a])) == 0)
		ft_printf("Indirect arg >[%s]< invalid for instruction [%s] in line : ",
		tasm->instr[n]->args[a], tasm->instr[n]->name);
	a = 0;
	if (res == 0)
	{
		ft_printf("%s ", tasm->instr[n]->name);
		while (a < 3 && tasm->instr[n]->args[a])
		{
			a > 0 ? ft_printf(", ") : 0;
			ft_printf("%s", tasm->instr[n]->args[a]);
			a++;
		}
		ft_printf("\n");
		free_and_exit(tasm);
	}
}
