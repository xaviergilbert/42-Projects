# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 14:54:36 by xgilbert          #+#    #+#              #
#    Updated: 2018/06/01 12:04:02 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT = ./libft/libft.a

SRCS = ./rendu/backtracking.c\
	   ./rendu/creation_carre.c\
	   ./rendu/fichier_test_cas_erreur.c\
	   ./rendu/fichier_tetri_to_str.c\
	   ./rendu/fill_carre.c\
	   ./rendu/main.c\
	   ./rendu/pos_diese.c\
	   ./rendu/stockage_tetri.c\
	   ./rendu/test_fill.c

RM = rm -f

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cd ./libft/ && make
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(SRCS)

clean:
	$(RM) $(OBJS)
	cd ./libft/ && make clean

fclean: clean
	$(RM) $(NAME)
	cd ./libft/ && make fclean

re: fclean all
