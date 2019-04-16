/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:09:17 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/02 16:54:22 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

static int		get_code_equivalence(int code)
{
	static int	equ[3][2] = {
		{REG_CODE, T_REG},
		{DIR_CODE, T_DIR},
		{IND_CODE, T_IND}
	};
	int			i;

	i = 0;
	while (i < 3)
	{
		if (equ[i][0] == code)
			return (equ[i][1]);
		i++;
	}
	return (-1);
}

int				has_valid_nb_arg(t_instruction *instruction)
{
	return (g_op_tab[instruction->id_op].arg_count == instruction->nb_arg);
}

static int		has_valid_value(t_instruction *instr, int i)
{
	if (instr->argtype_tab[i] == REG_CODE)
	{
		if (instr->arg_list[i] < 1 || instr->arg_list[i] > 16)
			return (0);
	}
	return (1);
}

int				has_valid_args(t_instruction *instr)
{
	int			i;
	int			code_equ;

	if (!instr->argtype_tab || !instr->arg_list)
		return (0);
	if (!has_valid_nb_arg(instr))
		return (0);
	i = 0;
	while (i < instr->nb_arg)
	{
		if ((code_equ = get_code_equivalence(instr->argtype_tab[i])) == -1)
			return (0);
		if (!(code_equ & g_op_tab[instr->id_op].arg_type[i]))
			return (0);
		if (!has_valid_value(instr, i))
			return (0);
		i++;
	}
	return (1);
}
