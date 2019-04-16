# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 11:11:28 by xgilbert          #+#    #+#              #
#    Updated: 2017/09/20 17:12:48 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PS = ./srcs

PI = ./includes

SRCS = $(PS)/ft_putchar.c\
		$(PS)/ft_putstr.c\
		$(PS)/ft_swap.c\
		$(PS)/ft_strlen.c\
		$(PS)/ft_strcmp.c

O = ft_putchar.o\
	ft_putstr.o\
	ft_swap.o\
	ft_strlen.o\
	ft_strcmp.o

ALL: $(NAME)

$(NAME):
	gcc -c $(SRCS) -I $(PI)
	ar rc $(NAME) $(O)

clean:
	/bin/rm $(O)

fclean: clean
	/bin/rm $(NAME)

re: fclean ALL
