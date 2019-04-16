# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 10:07:04 by xgilbert          #+#    #+#              #
#    Updated: 2017/11/07 16:03:39 by xgilbert         ###   ########.fr        #
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

RM = rm -f

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		gcc -c $(SRCS)
		ar rc $(NAME) $(O)

clean:
	$(RM) $(OBJS) $(O)

fclean: clean
	$(RM) $(NAME)

re: fclean all

