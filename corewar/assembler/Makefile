# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 16:31:28 by xgilbert          #+#    #+#              #
#    Updated: 2019/04/16 18:18:47 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ../libft/
LIBFT = $(LIBFT_DIR)libftprintf.a

SRC_DIR = ./srcs/
SRCS = main.c \
	  	split_file.c \
		get_header.c \
		parsing.c \
		get_body.c \
		tools_get_body.c \
		to_hexa.c \
		op.c \
		check_error.c \
		err_check_errors.c \
		check_valid_arg.c \
		parsing_label.c \
		tools.c \
		check_overflow.c \
		instr_to_hexa.c \
		calcul_byte.c \
		bytes_to_file.c \
		write_in_file.c \
		hexa_to_decimal.c\
		free_all.c

OBJ_DIR = ./bin/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@echo "CREATION .o ASM"
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@echo "COMPILATION ASM"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@echo "SUPPRESSION .o ASM"
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "SUPPRESSION EXECUTABLES"
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all
