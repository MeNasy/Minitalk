NAME=libftprintf.a

SRCS = ft_hx.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c\
ft_unputnbr.c ft_voidhx.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
