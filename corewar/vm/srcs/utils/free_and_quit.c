/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:07:28 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/03 21:13:13 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			free_and_quit(t_vm *vm, char *msg, int code)
{
	if (vm->process_list)
		free_process(vm);
	ft_exit_with_msg(msg, code);
}
