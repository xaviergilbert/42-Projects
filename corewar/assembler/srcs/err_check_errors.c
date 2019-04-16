/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:56:45 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 12:40:34 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		err_check_errors(int error, t_asm *tasm, int n, int a)
{
	int			i;

	i = 0;
	error == 0 ? ft_printf("Instruction name invalid : >[%s]< ",
			tasm->instr[n]->name) : 0;
	error == 1 ? ft_printf("Number of arguments invalid in instruction : %s ",
			tasm->instr[n]->name) : 0;
	error == 2 ? ft_printf("Argument type invalid in instruction : %s ",
			tasm->instr[n]->name) : 0;
	error == 3 ? ft_printf("Error for label : >[%s]< in instruction : %s ",
			tasm->instr[n]->args[a], tasm->instr[n]->name) : 0;
	while (i < 3 && tasm->instr[n]->args[i] != NULL)
	{
		i > 0 ? ft_printf(", ") : 0;
		ft_printf("%s", tasm->instr[n]->args[i]);
		i++;
	}
	ft_printf("\n");
	free_and_exit(tasm);
}
