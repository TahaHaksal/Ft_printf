CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_convertinthexa.c ft_extract2.c ft_printf_utils.c ft_printf_utils2.c ft_printf.c ft_putnbr.c ft_vdptr.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
