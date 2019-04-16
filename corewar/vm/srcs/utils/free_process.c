/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:15:30 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/03 20:16:05 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				free_process(t_vm *vm)
{
	t_process	*current;
	t_process	*tmp;

	if (vm == NULL)
		return (EXIT_FAILURE);
	current = vm->process_list;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	return (EXIT_SUCCESS);
}
