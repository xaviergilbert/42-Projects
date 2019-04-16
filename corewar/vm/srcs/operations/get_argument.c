/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:52:32 by akhercha          #+#    #+#             */
/*   Updated: 2019/03/31 14:52:32 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int			get_nb_argument(int encoded_byte)
{
	if (((encoded_byte >> 2) & 0x03) && ((encoded_byte >> 4) & 0x03)
		&& ((encoded_byte >> 6) & 0x03))
		return (3);
	else if (((encoded_byte >> 4) & 0x03) && ((encoded_byte >> 6) & 0x03))
		return (2);
	else if ((encoded_byte >> 6) & 0x03)
		return (1);
	return (0);
}

int			*get_argument_type(int encoded_byte, int nb_argument)
{
	int		*argument_tab;

	if ((nb_argument <= 0)
		|| !(argument_tab = malloc(sizeof(int) * nb_argument)))
		return (0);
	argument_tab[0] = (encoded_byte >> 6) & 0x03;
	if (nb_argument >= 2)
		argument_tab[1] = (encoded_byte >> 4) & 0x03;
	if (nb_argument == 3)
		argument_tab[2] = (encoded_byte >> 2) & 0x03;
	return (argument_tab);
}

static void	get_encoding_byte(t_instruction *instruction, char *op, int *i)
{
	if (instruction->id_op != 1 && instruction->id_op != 9
		&& instruction->id_op != 12 && instruction->id_op != 15)
	{
		instruction->encoded_byte = (int)op[*i] & 0xff;
		*i = *i + 1;
	}
	else
		instruction->encoded_byte = 128;
}

int			get_argument(char *op, t_instruction *instr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	instr->argtype_tab = NULL;
	instr->arg_list = NULL;
	instr->id_op = (int)op[i++] & 255;
	get_encoding_byte(instr, op, &i);
	if (!(instr->nb_arg = get_nb_argument(instr->encoded_byte)))
		return (0);
	if (!(instr->argtype_tab = get_argument_type(instr->encoded_byte,
			instr->nb_arg)))
		return (-1);
	if (!(instr->arg_list = get_argument_type(instr->encoded_byte,
			instr->nb_arg)))
		return (-1);
	while (j < instr->nb_arg)
	{
		i += get_args(&op[i], instr->argtype_tab[j], instr->id_op,
			&(instr->arg_list[j]));
		j++;
	}
	return (i);
}
