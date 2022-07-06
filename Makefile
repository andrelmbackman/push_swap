CHECKNAME = checker
PUSHNAME = push_swap

CHECKSRC = src/checker/checker.c src/checker/check_input.c
PUSHSRC = src/push_swap/push_swap.c
ALLSRC = src/utilities/moves.c src/utilities/stacks.c

OBJS = $(addsuffix .o,$(basename $(notdir CHECKSRC)))
CFLAGS = -Wall -Werror -Wextra

LIBS = ./libft/libft.a ./ft_printf/libftprintf.a
INCL = -I ./includes

all: $(CHECKNAME) $(PUSHNAME)


$(CHECKNAME): $(LIBS) $(CHECKSRC)
	gcc $(CFLAGS) $(INCL) -o $(CHECKNAME) $(CHECKSRC) $(ALLSRC) $(LIBS)

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

.PHONY: all clean fclean re
