CHECKNAME = checker
PUSHNAME = push_swap

CHECKSRC = src/checker/checker.c src/checker/moves_check.c
PUSHSRC = src/push_swap/push_swap.c src/push_swap/sort_small.c
ALLSRC = src/utilities/moves1.c src/utilities/moves2.c\
src/utilities/moves3.c src/utilities/stacks.c src/utilities/free_stacks.c\
src/utilities/moves_helpers.c src/utilities/args_check.c

OBJS = $(addsuffix .o,$(basename $(notdir CHECKSRC)))
CFLAGS = -Wall -Werror -Wextra

LIBS = ./libft/libft.a 
INCL = -I ./includes

all: $(CHECKNAME) $(PUSHNAME)


$(CHECKNAME): $(LIBS) $(CHECKSRC)
	clang -g3 $(CFLAGS) $(INCL) -o $(CHECKNAME) $(CHECKSRC) $(ALLSRC) $(LIBS)

$(PUSHNAME): $(LIBS) $(PUSHSRC)
	clang -g3 $(CFLAGS) $(INCL) -o $(PUSHNAME) $(PUSHSRC) $(ALLSRC) $(LIBS)

$(LIBS):
	@$(MAKE) -C ./libft/ all

clean:
	@$(MAKE) -C ./libft/ clean

fclean:
	$(MAKE) -C ./libft fclean
	/bin/rm $(CHECKNAME) $(PUSHNAME)

re: fclean all

.PHONY: all clean fclean re
