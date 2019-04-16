/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elimination_a_la_batte_le_processus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 04:25:07 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/01 17:36:07 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process			*elimination_a_la_batte_le_processus(t_vm *vm, int i)
{
	t_process		*current;
	t_process		*tmp;
	int				j;

	tmp = NULL;
	current = vm->process_list;
	if (i == 0)
		vm->process_list = current->next;
	else
	{
		j = 0;
		while (current && j < i)
		{
			tmp = (j == i - 1) ? current : tmp;
			current = current->next;
			j++;
		}
		if (!current || !tmp)
			return (NULL);
		tmp->next = current->next;
	}
	free(current);
	return (tmp ? tmp->next : vm->process_list);
}
