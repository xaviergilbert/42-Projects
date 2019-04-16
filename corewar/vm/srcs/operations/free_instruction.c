/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:52:20 by akhercha          #+#    #+#             */
/*   Updated: 2019/03/31 14:52:20 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void		free_instruction(t_instruction *instruction)
{
	if (instruction->argtype_tab)
		free(instruction->argtype_tab);
	if (instruction->arg_list)
		free(instruction->arg_list);
}
