NAME = libftprintf.a

CC = gcc

CFLAGS = -Werror -Wextra -Wall

OSRC = $(SRC:.c=.o)

SRC =	ft_printf.c\
		ft_putchar.c\
		ft_puthexa_low.c\
		ft_puthexa_up.c\
		ft_putnbr.c\
		ft_putpointer.c\
		ft_putstr.c\
		ft_putunbr.c\

all: $(NAME)

$(NAME): $(OSRC)
	@ar rc $(NAME) $(OSRC)

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME) $(OSRC)

re: fclean all

.PHONY: all, clean, fclean, re, bonus