# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 16:31:28 by xgilbert          #+#    #+#              #
#    Updated: 2019/04/16 18:26:38 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

INCLUDE_DIR = includes/

LIBFT_DIR = ../libft/
LIBFT = $(LIBFT_DIR)libftprintf.a

SRC_DIR = srcs/
SRCS = main.c \
		init/init_vm.c \
		init/init_corewar.c \
		utils/get_nb_champs.c \
		utils/champ_id_exists.c \
		utils/to_big_endian.c \
		utils/op.c \
		utils/get_op.c \
		utils/get_champ_by_id.c \
		utils/process.c \
		utils/print_debug.c \
		utils/free_process.c \
		utils/free_and_quit.c \
		parser/args_are_valids.c \
		parser/fill_vm_with_argv.c \
		launcher/exec_vm.c \
		launcher/for_each_cycle.c \
		launcher/clean_process_alive.c \
		launcher/elimination_a_la_batte_le_processus.c \
		launcher/display_ending.c \
		operations/op_add.c \
		operations/op_aff.c \
		operations/op_and.c \
		operations/op_fork.c \
		operations/op_lfork.c \
		operations/op_ld.c \
		operations/op_ldi.c \
		operations/op_live.c \
		operations/op_lld.c \
		operations/op_lldi.c \
		operations/op_or.c \
		operations/op_st.c \
		operations/op_sti.c \
		operations/op_sub.c \
		operations/op_xor.c \
		operations/op_zjump.c \
		operations/convert.c \
		operations/free_instruction.c \
		operations/get_argument.c \
		operations/get_real_value.c \
		operations/int_to_fourchar.c \
		operations/args_checker.c \
		operations/pc_increment.c


OBJ_DIR = bin/
SUB_OBJ_DIRS = init/ \
				parser/ \
				operations/ \
				operations/op_utils/ \
				launcher/ \
				utils/

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_DIRS = $(addprefix $(OBJ_DIR), $(SUB_OBJ_DIRS))

all: $(NAME)

$(OBJ_DIR):
	@echo "CREATION .o COREWAR"
	@mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@echo "COMPILATION COREWAR"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@echo "SUPPRESSION .o COREWAR"
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "SUPPRESSION EXECUTABLES"
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all
