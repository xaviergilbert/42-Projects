# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 14:54:36 by xgilbert          #+#    #+#              #
#    Updated: 2018/06/28 13:58:33 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

SRCS = ./analyse.c\
	   ./attributs.c\
	   ./conversion.c\
	   ./ft_printf.c\
	   ./get_info.c\
	   ./largeur_champs.c\
	   ./precision.c

RM = rm -f

OBJS = $(SRCS:.c=.o)

CURRENT_DIR = $(shell pwd)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	@echo 'COMPILATION LIBFT'
	@make -C libft

$(NAME): $(OBJS) $(LIBFT)
	@echo 'CREATION .o PRINTF'
	@$(CC) -c $(FLAGS) $(SRCS)
	@echo "COPIE libft.a DANS DOSSIER COURANT"
	@cp libft/libft.a ./$(NAME)
	@echo 'ASSEMBLAGE .o PRINTF'
	@ar rc $(NAME) $(OBJS)
	@echo 'INDEXATION PRINTF'
	@ranlib $(NAME)

clean:
	@echo 'SUPPRESSION .o PRINTF'
	@$(RM) $(OBJS)
	@cd ./libft/ && make clean

fclean: clean
	@echo 'SUPPRESSION .a PRINTF'
	@$(RM) $(NAME)
	@cd ./libft/ && make fclean

re: fclean all

test:
	@echo "IMPORT MAIN"
	@cd && cd xgilbert/GitHub/MAIN && cp printfmain.c $(CURRENT_DIR)\
	&& cd $(CURRENT_DIR)
	@echo "COMPILATION libftprintf.a AVEC MAIN"
	@$(CC) $(FLAGS) $(NAME) printfmain.c
	@echo "EXECUTION DU PROGRAMME"
	@./a.out
	@rm a.out
	@rm printfmain.c

curqi: re
	@cp *.a ~/xgilbert/GitHub/curqi_test/
	@cd ~/xgilbert/GitHub/curqi_test/ && make && ./ft_printf_tests
	@cd $(CURRENT_DIR)

