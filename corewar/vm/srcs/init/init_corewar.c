/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:01:32 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/04 15:14:51 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	add_to_arena(t_vm *vm, t_champ *champ, int index_champ,
	int total_champs)
{
	int		position;

	position = (MEM_SIZE / total_champs);
	ft_memcpy(&(vm->arena[index_champ * position]), &(champ->data.content),
		to_big_endian(champ->data.header.prog_size) + 1);
	return (EXIT_SUCCESS);
}

static int	champ_data_is_valid(t_champ_data *data, int len)
{
	return (!((to_big_endian(data->header.magic) != COREWAR_EXEC_MAGIC)
		|| (to_big_endian(data->header.prog_size) > CHAMP_MAX_SIZE)
		|| (len < (PROG_NAME_LENGTH + 1 + COM_LENGTH + 1 + AT_LEAST_ONE_OP))));
}

static int	fill_buffer(t_mem *buffer, t_mem *tmp, int bytes_read,
	int *offset)
{
	int		i;

	i = 0;
	while (i < bytes_read)
	{
		buffer[*offset + i] = tmp[i];
		i++;
	}
	*offset += i;
	return (EXIT_SUCCESS);
}

static int	fill_champ_data(t_vm *vm, t_champ *champ)
{
	int		fd;
	int		bytes_read;
	int		offset;
	t_mem	buffer[sizeof(t_header) + CHAMP_MAX_SIZE];
	t_mem	tmp[sizeof(t_header) + CHAMP_MAX_SIZE];

	fd = open(champ->filepath, O_RDONLY);
	if (fd <= 2)
		free_and_quit(vm, "Error: couldn't open .cor file.", EXIT_FAILURE);
	ft_bzero((void *)tmp, sizeof(t_header) + CHAMP_MAX_SIZE);
	ft_bzero((void *)buffer, sizeof(t_header) + CHAMP_MAX_SIZE);
	offset = 0;
	while (((bytes_read = read(fd, tmp, sizeof(t_header)
		+ CHAMP_MAX_SIZE)) > 0))
	{
		if ((offset + bytes_read) > (int)sizeof(t_header) + CHAMP_MAX_SIZE)
			free_and_quit(vm, "Error: champion too big.", EXIT_FAILURE);
		fill_buffer(buffer, tmp, bytes_read, &offset);
	}
	ft_memcpy(&(champ->data), buffer, sizeof(t_header) + CHAMP_MAX_SIZE);
	close(fd);
	return (!(champ_data_is_valid(&(champ->data), offset)));
}

int			init_corewar(t_vm *vm)
{
	int		nb_champs;
	int		i;

	nb_champs = get_nb_champs(vm->champs);
	vm->nb_champs = nb_champs;
	i = 0;
	while (i < nb_champs)
		vm->champs[i++].id *= -1;
	i = 0;
	while (i < nb_champs)
	{
		if (fill_champ_data(vm, &(vm->champs[i])) == EXIT_FAILURE)
			free_and_quit(vm, "Error: bad binary or champion too big.",
				EXIT_FAILURE);
		add_to_arena(vm, &(vm->champs[i]), i, nb_champs);
		if (create_champ_process(vm, i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
