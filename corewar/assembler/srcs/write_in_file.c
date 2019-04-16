/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:31:17 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/13 13:03:49 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int			write_instr(t_instr *instr, int fd)
{
	char			**hexa_str;
	int				hexa_nb;
	int				i;

	if (!(hexa_str = ft_strsplit(instr->code_hexa, ' ')))
		return (0);
	i = 0;
	while (hexa_str[i])
	{
		hexa_nb = base_to_decimal(hexa_str[i++], 16);
		write(fd, &hexa_nb, 1);
	}
	i = 0;
	while (hexa_str[i])
		free(hexa_str[i++]);
	free(hexa_str);
	return (1);
}

static void			adjust_exec_magic(int fd)
{
	char			stock;

	lseek(fd, 0, SEEK_SET);
	stock = (char)(COREWAR_EXEC_MAGIC >> 24 & 0xff);
	write(fd, &(stock), 1);
	stock = (char)(COREWAR_EXEC_MAGIC >> 16 & 0xff);
	write(fd, &(stock), 1);
	stock = (char)(COREWAR_EXEC_MAGIC >> 8 & 0xff);
	write(fd, &(stock), 1);
	stock = (char)(COREWAR_EXEC_MAGIC & 0xff);
	write(fd, &(stock), 1);
}

static int			padded_char(int size)
{
	while (size % 4 != 0)
		size++;
	return (size);
}

static void			adjust_prog_size(int fd, unsigned int prog_size)
{
	char			stock;

	lseek(fd, sizeof(unsigned int)
			+ padded_char(PROG_NAME_LENGTH + 1), SEEK_SET);
	stock = (char)((prog_size >> 24) & 0xff);
	write(fd, &(stock), 1);
	stock = (char)((prog_size >> 16) & 0xff);
	write(fd, &(stock), 1);
	stock = (char)((prog_size >> 8) & 0xff);
	write(fd, &(stock), 1);
	stock = (char)(prog_size & 0xff);
	write(fd, &(stock), 1);
}

int					write_in_file(t_asm *tasm, int fd)
{
	int				i;

	write(fd, tasm->header, sizeof(t_header));
	adjust_exec_magic(fd);
	adjust_prog_size(fd, tasm->header->prog_size);
	lseek(fd, sizeof(t_header), SEEK_SET);
	i = 0;
	while (tasm->instr[i])
	{
		if (tasm->instr[i]->name)
			!write_instr(tasm->instr[i], fd) ? free_and_exit(tasm) : 0;
		i++;
	}
	return (1);
}
