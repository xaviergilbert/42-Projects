/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:04:46 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/16 18:27:33 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "corewar.h"

typedef struct	s_instruction
{
	int			id_op;
	int			nb_arg;
	int			encoded_byte;
	int			*argtype_tab;
	int			*arg_list;
	int			mod;
}				t_instruction;

void			free_instruction(t_instruction *instruction);
int				get_args(char *op, int type, int id_op, int *arg);
int				get_argument(char *op, t_instruction *instruction);
int				get_real_value(t_vm *vm, t_process *proc, t_instruction *instr,
	int i);
int				twochar_to_int(char *str);
int				fourchar_to_int(char *str);
void			int_to_fourchar(int reg, t_mem *arena, int index);
int				has_valid_nb_arg(t_instruction *instruction);
int				has_valid_args(t_instruction *instr);
int				pc_increment(char *op);

int				op_live(t_vm *vm, t_process *proc, char *op);
int				op_ld(t_vm *vm, t_process *proc, char *op);
int				op_st(t_vm *vm, t_process *proc, char *op);
int				op_add(t_vm *vm, t_process *proc, char *op);
int				op_sub(t_vm *vm, t_process *proc, char *op);
int				op_and(t_vm *vm, t_process *proc, char *op);
int				op_or(t_vm *vm, t_process *proc, char *op);
int				op_xor(t_vm *vm, t_process *proc, char *op);
int				op_zjmp(t_vm *vm, t_process *proc, char *op);
int				op_ldi(t_vm *vm, t_process *proc, char *op);
int				op_sti(t_vm *vm, t_process *proc, char *op);
int				op_fork(t_vm *vm, t_process *proc, char *op);
int				op_lld(t_vm *vm, t_process *proc, char *op);
int				op_lldi(t_vm *vm, t_process *proc, char *op);
int				op_lfork(t_vm *vm, t_process *proc, char *op);
int				op_aff(t_vm *vm, t_process *proc, char *op);

#endif
