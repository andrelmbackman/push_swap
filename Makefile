CHECKNAME = checker
PUSHNAME = push_swap

CHECKSRC = src/checker/checker.c
PUSHSRC = src/push_swap/push_swap.c

OBJS = *.o
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
INCL = -I ./includes

.PHONY: all clean fclean re

all: $(CHECKNAME) $(PUSHNAME)
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf

$(CHECKNAME): $(CHECKSRC)
	gcc $(CFLAGS) $(INCL) -o $(CHECKNAME) $(CHECKSRC) $(LIBFT) $(PRINTF)

$(PUSHNAME): $(PUSHSRC)
	gcc $(CFLAGS) $(INCL) -o $(PUSHNAME) $(PUSHSRC) $(LIBFT) $(PRINTF)

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./ft_printf clean

fclean:
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./ft_printf fclean
	/bin/rm $(CHECKNAME) $(PUSHNAME)

re: fclean all