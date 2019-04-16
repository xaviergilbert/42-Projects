# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/11 15:18:42 by xgilbert          #+#    #+#              #
#    Updated: 2018/09/13 16:50:06 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

FONCTIONS = ./fonction_aux/algo_tri.c\
./fonction_aux/gestion_cas_erreur.c ./fonction_aux/dellst.c\
./fonction_aux/get_info.c ./fonction_aux/init.c ./fonction_aux/initlst.c\
./fonction_aux/insertlst.c ./fonction_aux/push.c ./fonction_aux/post_opti.c\
./fonction_aux/optimisation.c ./fonction_aux/reverse_rotate.c\
./fonction_aux/rotate.c ./fonction_aux/swap.c ./fonction_aux/petite_lst.c

DISPLAY = ./fonction_aux/displaylst.c

LIBFT = ./libft/libftprintf.a

RM = rm -f

CURRENT_DIR = $(shell pwd)

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(PUSH_SWAP) $(CHECKER)

$(LIBFT):
	@echo "COMPILATION LIBFT"
	@make -C libft

$(PUSH_SWAP): $(LIBFT)
	@echo "COMPILAGE PUSH_SWAP"
	@gcc $(FLAGS) -o $(PUSH_SWAP) ./push_swap.c $(FONCTIONS) $(DISPLAY) $(LIBFT)

$(CHECKER):
	@echo "COMPILAGE CHECKER"
	@gcc $(FLAGS) -o $(CHECKER) ./checker.c $(FONCTIONS) $(DISPLAY) $(LIBFT)

clean:
	@cd ./libft && make clean

fclean: clean
	@echo "SUPPRESSION EXECUTABLES"
	@$(RM) $(PUSH_SWAP) $(CHECKER)
	@cd ./libft/ && make fclean

test: re
	@echo "IMPORT SCRIPT DE TEST"
	@cd && cd xgilbert/GitHub/MAIN && cp test_ps.sh $(CURRENT_DIR)\
	&& cd $(CURRENT_DIR)
	@echo "EXECUTION SCRIPT DE TEST"
	@sh test_ps.sh
	@rm test_ps.sh

re: fclean all
