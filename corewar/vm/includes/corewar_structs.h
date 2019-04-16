/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:07:27 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/16 18:27:27 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_STRUCTS_H
# define COREWAR_STRUCTS_H

# include "./corewar.h"

typedef unsigned char	t_mem;

typedef struct			s_process
{
	int					pc;
	int					reg[REG_NUMBER];
	int					carry;
	int					op_code;
	int					cycles_to_exec;
	int					live;
	int					id;
	struct s_process	*next;
}						t_process;

typedef struct			s_champ_data
{
	t_header			header;
	t_mem				content[CHAMP_MAX_SIZE];
}						t_champ_data;

typedef struct			s_champ
{
	int					id;
	t_champ_data		data;
	char				*filepath;
	int					last_cycle_alive;
}						t_champ;

typedef struct			s_vm
{
	t_mem				arena[MEM_SIZE];
	t_champ				champs[MAX_PLAYERS];
	t_process			*process_list;
	int					dump_nb;
	int					last_champ_alive;
	int					nb_champs;
	int					cycle_to_die;
	int					nb_live;
	int					nb_process;
	int					debug;
}						t_vm;

typedef struct			s_op
{
	char				*opname;
	int					arg_count;
	int					arg_type[3];
	int					opcode;
	int					cycles;
	char				*description;
	int					encoded;
	int					half_size;
}						t_op;

extern t_op				g_op_tab[OP_NBR];

#endif
