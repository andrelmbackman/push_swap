CHECKNAME = checker
PUSHNAME = push_swap

CHECKSRC = src/checker/checker.c
PUSHSRC = src/push_swap/push_swap.c

OBJS = $(addsuffix .o,$(basename $(notdir CHECKSRC)))
CFLAGS = -Wall -Werror -Wextra

LIBS = ./libft/libft.a ./ft_printf/libftprintf.a
INCL = -I ./includes

.PHONY: all clean fclean re

all: $(CHECKNAME) $(PUSHNAME)


$(CHECKNAME): $(LIBS) $(CHECKSRC)
	gcc $(CFLAGS) $(INCL) -o $(CHECKNAME) $(CHECKSRC) $(LIBS)

$(PUSHNAME): $(LIBS) $(PUSHSRC)
	gcc $(CFLAGS) $(INCL) -o $(PUSHNAME) $(PUSHSRC) $(LIBS)

$(LIBS):
	@$(MAKE) -C ./libft/ all
	@$(MAKE) -C ./ft_printf/ all

clean:
	@$(MAKE) -C ./libft/ clean
	@$(MAKE) -C ./ft_printf/ clean

fclean:
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./ft_printf fclean
	/bin/rm $(CHECKNAME) $(PUSHNAME)

re: fclean all