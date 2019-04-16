/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_get_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:42:48 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 13:03:10 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		malloc_instr_tab(t_asm *tasm)
{
	int			n;

	n = 0;
	while (tasm->file[n])
		n++;
	if (!(tasm->instr = malloc(sizeof(t_instr*) * n)))
	{
		ft_printf("Failed to malloc the instruction tab\n");
		free_and_exit(tasm);
	}
}

void		malloc_instr(t_asm *tasm, int *n, int label)
{
	(*n)++;
	if (!label)
	{
		if (!(tasm->instr[*n] = malloc(sizeof(t_instr))))
		{
			tasm->instr[*n] = NULL;
			ft_printf("Failed to malloc the instruction sub tabs\n");
			free_and_exit(tasm);
		}
		tasm->instr[*n]->label = NULL;
	}
	tasm->instr[*n]->name = NULL;
	tasm->instr[*n]->code_hexa = NULL;
	tasm->instr[*n]->byte = 0;
	tasm->instr[*n]->pos_first_byte = 0;
	tasm->instr[*n]->opcode = 0;
	tasm->instr[*n]->args[0] = NULL;
	tasm->instr[*n]->args[1] = NULL;
	tasm->instr[*n]->args[2] = NULL;
}

int			line_not_empty(t_asm *tasm, int i)
{
	int			k;

	k = 0;
	while (tasm->file[i] && tasm->file[i][k])
	{
		if (ft_isalnum(tasm->file[i][k]) || tasm->file[i][k] == '_')
			return (1);
		k++;
	}
	return (0);
}

int			is_label(t_asm *tasm, int i)
{
	int			k;

	k = 0;
	if (!tasm->file[i])
		return (0);
	while (tasm->file[i][k]
			&& (tasm->file[i][k] == ' ' || tasm->file[i][k] == '\t'))
		k++;
	if (!tasm->file[i][k])
		is_label(tasm, i + 1);
	while (tasm->file[i][k] && tasm->file[i][k] != LABEL_CHAR)
		k++;
	if (tasm->file[i][k] == LABEL_CHAR && (tasm->file[i][k + 1] == ' '
				|| tasm->file[i][k + 1] == '\t' || tasm->file[i][k + 1] == '\0'
				|| tasm->file[i][k + 1] == '\n'))
		return (1);
	return (0);
}
