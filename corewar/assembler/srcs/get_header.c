/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:42:13 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 12:44:55 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		err_header(t_asm *tasm, int error)
{
	if (error == 1)
		ft_printf("Name not in good format\n");
	else if (error == 2)
		ft_printf("Name too long\n");
	else if (error == 3)
		ft_printf("Comment not in good format\n");
	else if (error == 4)
		ft_printf("Comment too long\n");
	free_and_exit(tasm);
}

int			get_name(t_asm *tasm, int i)
{
	int			k;
	int			l;

	k = 0;
	while (tasm->file[i][k] == ' ' || tasm->file[i][k] == '\t')
		k++;
	ft_strncmp(&tasm->file[i][k], ".name", 5) != 0 ? err_header(tasm, 1) : 0;
	k += 5;
	while (tasm->file[i][k] == ' ' || tasm->file[i][k] == '\t')
		k++;
	tasm->file[i][k++] != '"' ? err_header(tasm, 1) : 0;
	l = 0;
	while (tasm->file[i])
	{
		while (tasm->file[i][k] && tasm->file[i][k] != '"')
		{
			ft_strncat(tasm->header->prog_name, &tasm->file[i][k++], 1);
			++l > PROG_NAME_LENGTH ? err_header(tasm, 2) : 0;
		}
		if (tasm->file[i][k] && tasm->file[i][k] == '"')
			break ;
		tasm->file[i + 1] ? i++ : err_header(tasm, 1);
		k = 0;
	}
	return (i + 1);
}

int			get_comment(t_asm *tasm, int i)
{
	int			k;
	int			l;

	k = 0;
	while (tasm->file[i][k] == ' ' || tasm->file[i][k] == '\t')
		k++;
	ft_strncmp(&tasm->file[i][k], ".comment", 8) != 0 ? err_header(tasm, 3) : 0;
	k += 8;
	while (tasm->file[i][k] == ' ' || tasm->file[i][k] == '\t')
		k++;
	tasm->file[i][k++] != '"' ? err_header(tasm, 3) : 0;
	l = 0;
	while (tasm->file[i])
	{
		while (tasm->file[i][k] && tasm->file[i][k] != '"')
		{
			ft_strncat(tasm->header->comment, &tasm->file[i][k++], 1);
			++l > COMMENT_LENGTH ? err_header(tasm, 4) : 0;
		}
		if (tasm->file[i][k] && tasm->file[i][k] == '"')
			break ;
		tasm->file[i + 1] ? i++ : err_header(tasm, 3);
		k = 0;
	}
	return (i + 1);
}

int			go_not_empty_line(t_asm *tasm, int i)
{
	int			k;

	while (tasm->file[i])
	{
		k = -1;
		while (tasm->file[i][++k])
		{
			if (!ft_isspace(tasm->file[i][k])
			&& tasm->file[i][k] != '\0')
				return (i);
		}
		i++;
	}
	return (i);
}

int			get_header(t_asm *tasm)
{
	int			i;

	i = 0;
	if (!(tasm->header = (t_header*)malloc(sizeof(t_header))))
		free_and_exit(tasm);
	ft_bzero(tasm->header, sizeof(t_header));
	i = go_not_empty_line(tasm, i);
	tasm->file[i] ? i = get_name(tasm, i) : err_header(tasm, 1);
	i = go_not_empty_line(tasm, i);
	tasm->file[i] ? i = get_comment(tasm, i) : err_header(tasm, 3);
	tasm->header->magic = COREWAR_EXEC_MAGIC;
	return (i);
}
