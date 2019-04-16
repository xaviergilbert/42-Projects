
NAME = do-op

PS = ./srcs

PI = ./includes

SRCS = $(PS)/do_op.c\
	   $(PS)/ft_putstr.c\
	   $(PS)/ft_atoi.c\
	   $(PS)/ft_putnbr.c\
	   $(PS)/op.c

ALL: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) -I $(PI)

clean:
	/bin/rm $(NAME)

re: clean ALL

