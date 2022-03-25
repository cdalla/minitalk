NAME1 = server

NAME2 = client

PRINTF = ft_printf/libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRC1 =	server.c\
		utils.c

SRC2 =	client.c\
		utils.c

all: $(NAME1) $(NAME2)
	
$(NAME1): $(PRINTF) $(SRC1)
	$(CC) $^ -o $@

$(NAME2): $(PRINTF) $(SRC2)
	$(CC) $^ -o $@

$(PRINTF):
	make -C ft_printf

clean:
	make clean -C ft_printf

fclean: clean
	make fclean -C ft_printf
	rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all, clean, fclean, re, bonus