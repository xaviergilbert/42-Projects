/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:49:23 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 13:00:56 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		aff_elem_instruction(t_asm *tasm, int n)
{
	ft_printf("label %d :%s\n", n + 1, tasm->instr[n]->label);
	ft_printf("name instruction %d :%s\n", n + 1, tasm->instr[n]->name);
	ft_printf("les 3 args de l instru %d :%s %s %s\n", n + 1,
			tasm->instr[n]->args[0], tasm->instr[n]->args[1],
			tasm->instr[n]->args[2]);
	ft_printf("opcode : %d\n", tasm->instr[n]->opcode);
	tasm->instr[n]->name ? ft_printf("code hexa :%s\n",
			tasm->instr[n]->code_hexa) : 0;
	ft_printf("nbr_byte de l instruction : %d, pos_first_byte = %d\n\n",
			tasm->instr[n]->byte, tasm->instr[n]->pos_first_byte);
}

void		to_hexa(t_asm *tasm)
{
	int		n;

	n = 0;
	calcul_byte(tasm);
	while (tasm->instr[n])
	{
		if (tasm->instr[n]->name)
		{
			hexa_name(tasm, n);
			if (g_op_tab[tasm->instr[n]->opcode].encoded == 1)
				byte_encodage(tasm, n);
			byte_instructions(tasm, n);
		}
		n++;
	}
	tasm->header->prog_size = tasm->instr[n - 1]->pos_first_byte
		+ tasm->instr[n - 1]->byte;
}
