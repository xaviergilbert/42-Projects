/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:07:27 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/16 17:58:55 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libft/libft/libft.h"
# include "./op.h"
# include <limits.h>

# define OP_NBR	17

typedef struct		s_op
{
	char			*opname;
	int				arg_count;
	int				arg_type[3];
	int				opcode;
	int				cycles;
	char			*description;
	int				encoded;
	int				half_size;
}					t_op;

extern t_op			g_op_tab[OP_NBR];

typedef struct		s_instr
{
	char			*label;
	char			*name;
	char			*code_hexa;
	char			*args[3];
	int				operation_label[3];
	int				pos_label[3];
	int				nb_arg;
	int				byte;
	int				pos_first_byte;
	int				opcode;
}					t_instr;

typedef struct		s_asm
{
	t_instr			**instr;
	t_header		*header;
	char			**file;
}					t_asm;

/*
** Parsing
*/

char				**split_file(char const *s, char c);
int					parsing(t_asm *tasm);
int					get_header(t_asm *tasm);
void				get_body(t_asm *tasm, int i);
void				malloc_instr_tab(t_asm *tasm);
void				malloc_instr(t_asm *tasm, int *n, int label);
int					line_not_empty(t_asm *tasm, int i);
int					is_label(t_asm *tasm, int i);
void				parsing_label(t_asm *tasm);

/*
** Check Errors
*/

int					check_errors(t_asm *tasm);
void				check_valid_arg(t_asm *tasm, int n, int a, int type);
void				err_check_errors(int error, t_asm *tasm, int n, int a);

/*
** Display / Debug Functions
*/

void				aff_elem_instruction(t_asm *tasm, int n);

/*
** tools.c
*/

int					ft_pow_2(int nb);
char				*ft_binary_to_hexa(char *binary);
char				*ft_strjoin1_size(char *dst, char *src, int size);
int					hexa_to_good_size_hexa(char **tmp, size_t size);
int					size_by_type_instruction(int type);
void				to_hexa(t_asm *tasm);

/*
** instr_to_hexa.c
*/

void				byte_encodage(t_asm *tasm, int n);
void				hexa_name(t_asm *tasm, int n);
void				ft_arg_to_hexa(t_asm *tasm, int n, int type, char *arg);
void				ft_label_to_hexa(t_asm *tasm, int n, int type, int i);
void				byte_instructions(t_asm *tasm, int n);
char				*check_overflow(t_asm *tasm, char *arg);

/*
** calcul_byte.c
*/

void				instru_calcul_byte(t_asm *tasm, int n);
void				calcul_byte(t_asm *tasm);

/*
** bytes_to_file.c
*/
int					bytes_to_file(t_asm *tasm, char *dot_s_filename);
int					write_in_file(t_asm *tasm, int fd);
int					base_to_decimal(char *str, int base);

/*
** Free_all.c
*/

void				free_all(t_asm *tasm);
void				free_and_exit(t_asm *tasm);

#endif
