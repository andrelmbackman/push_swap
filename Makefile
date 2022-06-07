CHECKNAME = checker
PUSHNAME = push_swap

CHECKSRC = src/checker.c
PUSHSRC = src/push_swap.c

OBJS = *.o
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

.PHONY: all clean fclean re

all: $(CHECKNAME) $(PUSHNAME)
	$(MAKE) -C ./libft

$(CHECKNAME): $(CHECKSRC)
	gcc $(CFLAGS) -o $(CHECKNAME) $(CHECKSRC)

$(PUSHNAME): $(PUSHSRC)
	gcc $(CFLAGS) -o $(PUSHNAME) $(PUSHSRC)

clean:
	$(MAKE) -C ./libft clean

fclean:
	$(MAKE) -C ./libft fclean
	/bin/rm $(CHECKNAME) $(PUSHNAME)

re: fclean all