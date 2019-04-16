# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makeefile                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 10:44:27 by xgilbert          #+#    #+#              #
#    Updated: 2017/11/07 16:43:55 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

#PS = ./srcs

#PI = ./includes

SRCS = display_file.c

O = display_file.o

RM = rm -f

LIB = libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(NAME) $(SRCS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
