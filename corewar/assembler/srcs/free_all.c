/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:32:20 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 12:41:04 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			free_instr(t_asm *tasm)
{
	int			n;
	int			a;

	n = 0;
	if (tasm->instr)
	{
		while (tasm->instr[n])
		{
			a = 0;
			tasm->instr[n]->label ? free(tasm->instr[n]->label) : 0;
			tasm->instr[n]->name ? free(tasm->instr[n]->name) : 0;
			tasm->instr[n]->code_hexa ? free(tasm->instr[n]->code_hexa) : 0;
			while (a < 3)
			{
				tasm->instr[n]->args[a] ? free(tasm->instr[n]->args[a]) : 0;
				a++;
			}
			free(tasm->instr[n]);
			n++;
		}
		free(tasm->instr);
	}
}

void			free_file(t_asm *tasm)
{
	int			i;

	i = 0;
	if (tasm->file)
	{
		while (tasm->file[i])
			free(tasm->file[i++]);
		free(tasm->file);
	}
}

void			free_all(t_asm *tasm)
{
	free_instr(tasm);
	tasm->header ? free(tasm->header) : 0;
	free_file(tasm);
}

void			free_and_exit(t_asm *tasm)
{
	free_all(tasm);
	exit(0);
}
