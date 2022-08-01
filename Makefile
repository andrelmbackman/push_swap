CHECKNAME = checker
PUSHNAME = push_swap

CHECKSRC = src/checker/checker.c src/checker/args_check.c\
src/checker/moves_check.c
PUSHSRC = src/push_swap/push_swap.c
ALLSRC = src/utilities/moves1.c src/utilities/moves2.c\
src/utilities/moves3.c src/utilities/stacks.c src/utilities/free_stacks.c

OBJS = $(addsuffix .o,$(basename $(notdir CHECKSRC)))
CFLAGS = -Wall -Werror -Wextra

LIBS = ./libft/libft.a 
INCL = -I ./includes

all: $(CHECKNAME) $(PUSHNAME)


$(CHECKNAME): $(LIBS) $(CHECKSRC)
	gcc -g3 -fsanitize=address $(CFLAGS) $(INCL) -o $(CHECKNAME) $(CHECKSRC) $(ALLSRC) $(LIBS)

$(PUSHNAME): $(LIBS) $(PUSHSRC)
	gcc $(CFLAGS) $(INCL) -o $(PUSHNAME) $(PUSHSRC) $(LIBS)

$(LIBS):
	@$(MAKE) -C ./libft/ all

clean:
	@$(MAKE) -C ./libft/ clean

fclean:
	$(MAKE) -C ./libft fclean
	/bin/rm $(CHECKNAME) $(PUSHNAME)

re: fclean all

.PHONY: all clean fclean re
