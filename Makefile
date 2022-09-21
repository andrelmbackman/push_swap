CHECKNAME = checker
PUSHNAME = push_swap

CHECKSRC = src/checker/checker.c src/checker/free_all.c

PUSHSRC = src/push_swap/push_swap.c src/push_swap/sort_small.c\
src/push_swap/sort_five.c src/push_swap/sort_medium.c\
src/push_swap/sort_big.c src/push_swap/sort_helpers.c \
 src/push_swap/get_destined.c \


ALLSRC = src/utilities/moves1_swap.c src/utilities/moves2_rotate.c\
src/utilities/moves3_rrotate.c src/utilities/moves4_push.c\
src/utilities/stacks.c src/utilities/free_print_stacks.c\
src/utilities/moves_helpers.c src/utilities/args_check.c

OBJS = $(addsuffix .o,$(basename $(notdir CHECKSRC)))
CFLAGS = -Wall -Werror -Wextra

LIBS = ./libft/libft.a 
INCL = -I ./includes

all: $(CHECKNAME) $(PUSHNAME)


$(CHECKNAME): $(LIBS) $(CHECKSRC) $(ALLSRC)
	gcc $(CFLAGS) $(INCL) -o $(CHECKNAME) $(CHECKSRC) $(ALLSRC) $(LIBS)

$(PUSHNAME): $(LIBS) $(PUSHSRC) $(ALLSRC)
	gcc $(CFLAGS) $(INCL) -o $(PUSHNAME) $(PUSHSRC) $(ALLSRC) $(LIBS)

$(LIBS):
	@$(MAKE) -C ./libft/ all

clean:
	@$(MAKE) -C ./libft/ clean

fclean:
	@$(MAKE) -C ./libft fclean
	/bin/rm -f $(CHECKNAME) $(PUSHNAME)

re: fclean all

.PHONY: all clean fclean re
