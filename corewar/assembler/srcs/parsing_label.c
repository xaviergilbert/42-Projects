/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:50:08 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 12:59:04 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void			error_label(t_asm *tasm, int n, int a)
{
	ft_printf("Error label name : %s\n", tasm->instr[n]->args[a]);
	free_and_exit(tasm);
}

static int			is_number(char *str)
{
	int				i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i])
		return (0);
	else
		return (1);
}

static void			operation_label(t_asm *tasm, int a, int i, int n)
{
	int				neg;

	neg = 1;
	if (tasm->instr[n]->args[a][i])
	{
		if (tasm->instr[n]->args[a][i] == '-')
			neg = -1;
		else if (tasm->instr[n]->args[a][i] == '+')
			i++;
		else
			error_label(tasm, n, a);
		while (tasm->instr[n]->args[a][++i] == ' '
				|| tasm->instr[n]->args[a][i] == '\t')
			i++;
		if (is_number(&tasm->instr[n]->args[a][i]))
			tasm->instr[n]->operation_label[a] = ft_atoi(
				&tasm->instr[n]->args[a][i]) * neg;
		else
			error_label(tasm, n, a);
	}
}

void				proceed_parsing_label(t_asm *tasm, int n, int a)
{
	int				i;
	char			*tmp;

	i = 0;
	tasm->instr[n]->operation_label[a] = 0;
	if (tasm->instr[n]->args[a][i] == DIRECT_CHAR)
		i += 2;
	else
		i += 1;
	while (char_in_str(LABEL_CHARS, tasm->instr[n]->args[a][i]))
		i++;
	if (!(tmp = ft_strndup(tasm->instr[n]->args[a], i)))
		free_and_exit(tasm);
	while (tasm->instr[n]->args[a][i]
			&& (tasm->instr[n]->args[a][i] == ' '
				|| tasm->instr[n]->args[a][i] == '\t'))
		i++;
	operation_label(tasm, a, i, n);
	ft_strcpy(tasm->instr[n]->args[a], tmp);
	free(tmp);
}

void				parsing_label(t_asm *tasm)
{
	int				n;
	int				a;

	n = -1;
	while (tasm->instr[++n])
	{
		a = -1;
		while (++a < 3 && tasm->instr[n]->args[a])
		{
			if (tasm->instr[n]->args[a][0] == LABEL_CHAR
					|| tasm->instr[n]->args[a][1] == LABEL_CHAR)
				proceed_parsing_label(tasm, n, a);
		}
	}
}
