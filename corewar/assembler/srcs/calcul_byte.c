/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:53:07 by lucdubos          #+#    #+#             */
/*   Updated: 2019/04/12 12:45:43 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		instru_calcul_byte(t_asm *tasm, int n)
{
	int		i;

	i = 0;
	tasm->instr[n]->byte = 1;
	while (i < 3 && tasm->instr[n]->args[i])
	{
		if (tasm->instr[n]->args[i][0] == DIRECT_CHAR
		&& !g_op_tab[tasm->instr[n]->opcode].half_size)
			tasm->instr[n]->byte += DIR_SIZE;
		else if (tasm->instr[n]->args[i][0] == 'r')
			tasm->instr[n]->byte += 1;
		else
			tasm->instr[n]->byte += IND_SIZE;
		i++;
	}
	if (i >= 2)
		tasm->instr[n]->byte += 1;
	if (ft_strcmp("aff", tasm->instr[n]->name) == 0)
		tasm->instr[n]->byte += 1;
}

void		calcul_byte(t_asm *tasm)
{
	int		n;

	n = 0;
	tasm->instr[n]->pos_first_byte = 0;
	if (tasm->instr[n]->name)
		instru_calcul_byte(tasm, n);
	n++;
	while (tasm->instr[n])
	{
		if (tasm->instr[n]->name)
			instru_calcul_byte(tasm, n);
		else
			tasm->instr[n]->byte = 0;
		tasm->instr[n]->pos_first_byte = tasm->instr[n - 1]->pos_first_byte
		+ tasm->instr[n - 1]->byte;
		n++;
	}
}
