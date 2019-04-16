/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_body.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:53:31 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 12:43:01 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			get_label(t_asm *tasm, int i, int n, int *k)
{
	while (tasm->file[i][*k] && ft_isspace(tasm->file[i][*k]) == 1)
		(*k)++;
	while (tasm->file[i][*k] && ft_isspace(tasm->file[i][*k]) == 0)
		(*k)++;
	*k > 0 ? (*k)-- : 0;
	if (tasm->file[i][*k] && tasm->file[i][*k] == ':')
	{
		if (!(tasm->instr[n]->label = ft_strndup(tasm->file[i], *k)))
			free_and_exit(tasm);
		(*k)++;
		return (1);
	}
	else
		tasm->instr[n]->label = NULL;
	*k = 0;
	return (0);
}

int			get_the_name(t_asm *tasm, int i, int n, int *k)
{
	int			c;

	c = 0;
	while (tasm->file[i][*k] && ft_isspace(tasm->file[i][*k]) == 1)
		(*k)++;
	while (tasm->file[i][*k] && !ft_isspace(tasm->file[i][*k]))
	{
		c++;
		(*k)++;
	}
	*k -= c;
	if (c != 0)
	{
		if (!(tasm->instr[n]->name = ft_strndup(&tasm->file[i][*k], c)))
			free_and_exit(tasm);
	}
	else
		tasm->instr[n]->name = NULL;
	if (tasm->instr[n]->name)
		return (1);
	return (0);
}

void		get_args(t_asm *tasm, int i, int n, int k)
{
	int			c;
	int			a;

	while (tasm->file[i][k] && ft_isalpha(tasm->file[i][k]))
		k++;
	a = 0;
	while (a < 3 && tasm->file[i][k])
	{
		c = 0;
		while (ft_isspace(tasm->file[i][k]) == 1)
			k++;
		while (tasm->file[i][k + c] && (tasm->file[i][k + c] != SEPARATOR_CHAR))
			c++;
		if (!(tasm->instr[n]->args[a] = ft_strndup(&tasm->file[i][k], c)))
			free_and_exit(tasm);
		a++;
		k += c + 1;
	}
	if (a >= 2 && tasm->file[i][k - 2] != '\n')
	{
		if (!(tasm->instr[n]->args[a - 1] = ft_strjoin1(
						tasm->instr[n]->args[a - 1], &tasm->file[i][k - 1])))
			free_and_exit(tasm);
	}
	tasm->instr[n]->nb_arg = a;
}

int			proceed_parsing(t_asm *tasm, int *n, int label, int i)
{
	int			test;
	int			k;

	test = 0;
	k = 0;
	malloc_instr(tasm, n, label);
	!label ? test = get_label(tasm, i, *n, (&k)) : 0;
	test += get_the_name(tasm, i, *n, (&k));
	if (test == 0)
	{
		ft_printf("Line invalid >[%s]<\n", tasm->file[i]);
		free_and_exit(tasm);
	}
	get_args(tasm, i, *n, k);
	if (!(tasm->file[i + 1]) || (tasm->instr[*n]->name == NULL
				&& ((is_label(tasm, i + 1) == 1)
					|| line_not_empty(tasm, i + 1) == 0)))
		return (0);
	else if (tasm->instr[*n]->name == NULL)
	{
		(*n)--;
		return (1);
	}
	else
		return (0);
}

void		get_body(t_asm *tasm, int i)
{
	int			n;
	int			k;
	int			label;

	malloc_instr_tab(tasm);
	n = -1;
	label = 0;
	while (tasm->file[++i])
	{
		k = 0;
		if (line_not_empty(tasm, i))
			label = proceed_parsing(tasm, &n, label, i);
		else if (!line_not_empty(tasm, i))
		{
			while (ft_isspace(tasm->file[i][k]) == 1)
				k++;
			if (tasm->file[i][k] != '\0')
			{
				ft_printf("Incorrect line >[%s]<\n", tasm->file[i]);
				tasm->instr[n + 1] = NULL;
				free_and_exit(tasm);
			}
		}
	}
	tasm->instr[++n] = NULL;
}
