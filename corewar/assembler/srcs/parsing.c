/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:35:47 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 14:15:28 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		rm_comm(t_asm *tasm)
{
	int			i;
	int			k;
	int			quote;

	i = 0;
	quote = 0;
	while (tasm->file[i])
	{
		k = 0;
		while (tasm->file[i][k] && tasm->file[i][k] != '#')
		{
			if (tasm->file[i][k] == '"' && quote == 0)
				quote = 1;
			else if (tasm->file[i][k] == '"' && quote == 1)
				quote = 0;
			k++;
		}
		if (tasm->file[i][k] == '#' && quote == 0)
			ft_bzero(&tasm->file[i][k], ft_strlen(&tasm->file[i][k]));
		i++;
	}
}

void		reformatage_donnees(t_asm *tasm)
{
	int			n;
	int			a;
	char		*tmp;

	n = -1;
	while (tasm->instr[++n])
	{
		if (tasm->instr[n]->label)
		{
			if (!(tmp = ft_strtrim(tasm->instr[n]->label)))
				free_and_exit(tasm);
			ft_strcpy(tasm->instr[n]->label, tmp);
			free(tmp);
		}
		a = -1;
		while (++a < 3 && tasm->instr[n]->args[a])
		{
			if (!(tmp = ft_strtrim(tasm->instr[n]->args[a])))
				free_and_exit(tasm);
			ft_strcpy(tasm->instr[n]->args[a], tmp);
			free(tmp);
		}
	}
}

int			parsing(t_asm *tasm)
{
	int			i;

	i = 0;
	rm_comm(tasm);
	i = get_header(tasm);
	get_body(tasm, i - 1);
	reformatage_donnees(tasm);
	if (!tasm->instr[0])
	{
		ft_printf("Erreur : pas d'instruction\n");
		free_and_exit(tasm);
	}
	parsing_label(tasm);
	check_errors(tasm);
	return (0);
}
