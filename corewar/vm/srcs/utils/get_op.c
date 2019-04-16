/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:10:20 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/01 15:10:48 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	typecode_to_size(int typecode, int op_two)
{
	if (typecode == REG_CODE)
		return (1);
	else if (typecode == DIR_CODE)
		return (op_two ? 2 : 4);
	else if (typecode == IND_CODE)
		return (2);
	return (0);
}

static int	get_size(int op_id, int encoded_byte)
{
	int		size;
	int		op_two;

	size = 0;
	op_two = 0;
	if (op_id == 0x01)
		return (4);
	else if (op_id == 0x09 || op_id == 0x0C || op_id == 0x0F)
		return (2);
	if (op_id == 0x0A || op_id == 0x0B || op_id == 0x0E)
		op_two = 1;
	size += typecode_to_size((encoded_byte >> 2) & 0x03, op_two);
	size += typecode_to_size((encoded_byte >> 4) & 0x03, op_two);
	size += typecode_to_size((encoded_byte >> 6) & 0x03, op_two);
	return (size);
}

char		*get_op(char *arena, int pc, int op_id)
{
	int		i;
	int		encoding_byte;
	char	*str;
	int		size;

	encoding_byte = 0;
	i = 0;
	if (op_id != 1 && op_id != 9 && op_id != 0x0C && op_id != 0x0F)
		encoding_byte = arena[(pc + 1) % 4096];
	size = get_size(op_id, encoding_byte);
	if (!(str = (char *)malloc(sizeof(char) * (size + 3))))
		return (NULL);
	while (size + 2 > 0)
	{
		str[i] = arena[pc % 4096];
		str[i] = str[i] & 0xFF;
		i++;
		size--;
		pc++;
	}
	str[0] = (char)op_id;
	str[i] = '\0';
	return (str);
}
