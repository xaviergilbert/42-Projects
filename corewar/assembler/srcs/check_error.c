/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:15:37 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 12:37:46 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_name(t_asm *tasm, int n)
{
	int			i;

	i = 1;
	while (i < 17 && (ft_strcmp(g_op_tab[i].opname, tasm->instr[n]->name) != 0
	&& ft_strcmp(g_op_tab[i].description, tasm->instr[n]->name) != 0))
		i++;
	tasm->instr[n]->opcode = i;
	if (i < 17)
		return (1);
	return (0);
}

int			check_arg_count(t_asm *tasm, int n)
{
	if (g_op_tab[tasm->instr[n]->opcode].arg_count != tasm->instr[n]->nb_arg)
		return (0);
	return (1);
}

int			check_arg_type(t_asm *tasm, int n, int opcode)
{
	int			a;
	int			arg_type;

	a = -1;
	while (++a < 3 && tasm->instr[n]->args[a])
	{
		arg_type = g_op_tab[opcode].arg_type[a];
		if (tasm->instr[n]->args[a][0] == 'r' && (arg_type == 1
		|| arg_type == 3 || arg_type == 7 || arg_type == 5))
			check_valid_arg(tasm, n, a, 1);
		else if (tasm->instr[n]->args[a][0] == DIRECT_CHAR
		&& (arg_type == 2 || arg_type == 3 || arg_type == 7 || arg_type == 6))
			check_valid_arg(tasm, n, a, 2);
		else if (arg_type == 4 || arg_type == 5 || arg_type == 7
		|| arg_type == 6)
			check_valid_arg(tasm, n, a, 3);
		else
			return (0);
	}
	return (1);
}

int			check_labels(t_asm *tasm, int n)
{
	int			a;
	int			i;
	int			k;

	a = -1;
	while (++a < 3 && tasm->instr[n]->args[a])
	{
		if (ft_strlen(tasm->instr[n]->args[a]) >= 1
			&& char_in_str(tasm->instr[n]->args[a], LABEL_CHAR))
		{
			i = 0;
			k = 0;
			while (tasm->instr[n]->args[a][k] != LABEL_CHAR)
				k++;
			k++;
			while (tasm->instr[i] && ft_strcmp(tasm->instr[i]->label,
			&tasm->instr[n]->args[a][k]) != 0)
				i++;
			if (tasm->instr[i])
				tasm->instr[n]->pos_label[a] = i;
			else
				err_check_errors(3, tasm, n, a);
		}
	}
	return (1);
}

int			check_errors(t_asm *tasm)
{
	int			n;

	n = -1;
	while (tasm->instr[++n])
	{
		while (tasm->instr[n] && !tasm->instr[n]->name)
			n++;
		if (!tasm->instr[n])
			break ;
		if (!check_name(tasm, n))
			err_check_errors(0, tasm, n, 0);
		if (!check_arg_count(tasm, n))
			err_check_errors(1, tasm, n, 0);
		if (!check_arg_type(tasm, n, tasm->instr[n]->opcode))
			err_check_errors(2, tasm, n, 0);
		check_labels(tasm, n);
	}
	return (1);
}
